// ╔══════════════════════════════════════════════════════════════════╗
// ║                      E M I R   H U B  v3.0                      ║
// ║  Sekmeli gelişmiş panel · Geode SDK · GD 2.2081                 ║
// ╚══════════════════════════════════════════════════════════════════╝

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/CCScheduler.hpp>
#include <Geode/ui/Notification.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>

using namespace geode::prelude;
using namespace cocos2d;

// ══════════════════════════════════════════════════════════════════
//  GLOBAL STATE
// ══════════════════════════════════════════════════════════════════
namespace EH {

// ── Bypass / cheat ──────────────────────────────────────────────
bool noclip         = false;
bool noclipP2       = false;   // 2. oyuncu için de noclip
bool autoPlay       = false;
bool showTrajLines  = true;
bool infiniteLives  = false;   // ölünce reset etme (noclip kapalıyken bile)

// ── Görsel ──────────────────────────────────────────────────────
bool showHitboxes   = false;
bool showFPS        = false;
bool hidePlayer     = false;
bool hideBG         = false;
bool hideGround     = false;
bool hideObjects    = false;    // objeleri gizle (sadece görsel)
bool mirrorMode     = false;    // ekranı yatay çevir
bool cameraZoomOn   = false;

// ── Player tweaks ────────────────────────────────────────────────
bool  gravityFlip   = false;
bool  smallPlayer   = false;
bool  ghostTrail    = false;    // iz bırak
bool  noRotation    = false;    // dönme yok
bool  antiPush      = false;    // objelerin player'ı itmesi yok

// ── Hız / zaman ─────────────────────────────────────────────────
float speedhack     = 1.0f;    // 0.1 – 5.0
float musicSpeed    = 1.0f;    // 0.5 – 2.0

// ── Practice / Checkpoint ───────────────────────────────────────
bool  practiceMusic = false;
bool  showRespawnAnim = true;
bool  instantRespawn = false;   // ölünce anında respawn (noclip değil)
bool  checkpointEveryX = false;
int   checkpointInterval = 2;   // kaç saniyede bir otomatik checkpoint

// ── Stats overlay ───────────────────────────────────────────────
bool  showAttempts   = false;
bool  showDeaths     = false;
bool  showPercent    = false;
bool  showCPS        = false;    // clicks per second

// ── Menü durumu ──────────────────────────────────────────────────
bool  menuOpen       = false;
int   activeTab      = 0;       // 0=Bypass 1=Visual 2=Player 3=Speed 4=Stats 5=Debug

// ── Debug log ───────────────────────────────────────────────────
std::vector<std::string> debugLog;
void dbgLog(const std::string& s) {
    debugLog.push_back(s);
    if (debugLog.size() > 20) debugLog.erase(debugLog.begin());
    log::info("[EmirHub] {}", s);
}

// ── CPS sayacı ──────────────────────────────────────────────────
int   clickCount     = 0;
float cpsTimer       = 0.f;
float currentCPS     = 0.f;

// ── Auto-checkpoint timer ────────────────────────────────────────
float acTimer        = 0.f;

// ── Trajectory draw nodes ────────────────────────────────────────
CCDrawNode* jumpLine   = nullptr;
CCDrawNode* noJumpLine = nullptr;

// ── Hitbox draw node ─────────────────────────────────────────────
CCDrawNode* hitboxNode = nullptr;

// ── Ghost trail ──────────────────────────────────────────────────
float trailTimer = 0.f;

// ── Zoom level ───────────────────────────────────────────────────
float cameraZoom = 1.0f;

} // namespace EH

// ══════════════════════════════════════════════════════════════════
//  YARDIMCI
// ══════════════════════════════════════════════════════════════════
static void toast(const char* txt) {
    Notification::create(txt, NotificationIcon::Info)->show();
}

static std::string fmtFloat(float v, int dec = 2) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%.*f", dec, v);
    return buf;
}

// ══════════════════════════════════════════════════════════════════
//  TRAJECTORY SIMULATION
// ══════════════════════════════════════════════════════════════════
static constexpr float GD_GRAVITY    = -0.958f;
static constexpr float GD_JUMP_VEL   =  11.18f;
static constexpr int   SIM_FRAMES    = 50;
static constexpr float PLAYER_HALF   = 14.f;

struct TrajResult {
    std::vector<CCPoint> pts;
    bool dies = false;
    int  deathFrame = -1;
};

static TrajResult simulate(CCPoint pos, float vy, bool holdJump,
                            bool isShip, bool isDart, bool isBall,
                            bool isSwing, bool gravFlip,
                            PlayLayer* pl)
{
    TrajResult r;
    float px = pos.x, py = pos.y;
    float vx = 5.77f;
    float gMul = gravFlip ? -1.f : 1.f;

    for (int i = 0; i < SIM_FRAMES; ++i) {
        if (isShip || isSwing) {
            float thrust = holdJump ? 0.45f * gMul : -0.45f * gMul;
            vy = vy * 0.98f + thrust;
            vy = std::clamp(vy, -6.f, 6.f);
        } else if (isDart) {
            vy = holdJump ? 4.f * gMul : -4.f * gMul;
        } else if (isBall) {
            vy += GD_GRAVITY * gMul;
            if (holdJump && i == 0) vy = GD_JUMP_VEL * gMul * 0.85f;
        } else {
            // cube / robot / spider
            vy += GD_GRAVITY * gMul;
            if (holdJump && i == 0) vy = GD_JUMP_VEL * gMul;
            if (gMul > 0 && py <= 20.f && vy < 0.f) { vy = 0.f; py = 20.f; }
            if (gMul < 0 && py >= 280.f && vy > 0.f) { vy = 0.f; py = 280.f; }
        }
        px += vx; py += vy;
        r.pts.push_back({px, py});

        // Obje çarpışma kontrolü (sadece sol katman üzerinden geçen objeler)
        if (pl && pl->m_objects) {
            CCRect pr(px - PLAYER_HALF, py - PLAYER_HALF, PLAYER_HALF*2, PLAYER_HALF*2);
            for (unsigned j = 0; j < pl->m_objects->count(); ++j) {
                auto* obj = dynamic_cast<GameObject*>(pl->m_objects->objectAtIndex(j));
                if (!obj) continue;
                if (std::abs(obj->getPositionX() - px) > 150.f) continue;
                // m_isDangerous flag olmadığı için tüm solid objeleri kontrol ediyoruz
                if (pr.intersectsRect(obj->boundingBox())) {
                    r.dies = true; r.deathFrame = i;
                    break;
                }
            }
        }
        if (r.dies) break;
    }
    return r;
}

// ══════════════════════════════════════════════════════════════════
//  AUTO PLAY
// ══════════════════════════════════════════════════════════════════
static void runAutoPlay(PlayLayer* pl) {
    if (!EH::autoPlay || !pl) return;
    auto* p = pl->m_player1;
    if (!p) return;

    CCPoint pos = p->getPosition();
    float vy    = (float)p->getYVelocity();
    bool ship   = p->m_isShip;
    bool dart   = p->m_isDart;
    bool ball   = p->m_isBall;
    bool swing  = p->m_isSwing;
    bool gflip  = p->m_isUpsideDown;

    auto jr  = simulate(pos, vy, true,  ship, dart, ball, swing, gflip, pl);
    auto njr = simulate(pos, vy, false, ship, dart, ball, swing, gflip, pl);

    // Draw lines
    if (EH::showTrajLines) {
        auto ensureNode = [&](CCDrawNode*& node) {
            if (!node) {
                node = CCDrawNode::create();
                node->setZOrder(9999);
                // UI katmanına ekle (kamera kaymasından etkilenmesin diye objectLayer)
                pl->m_objectLayer->addChild(node);
            }
            node->clear();
        };
        ensureNode(EH::jumpLine);
        ensureNode(EH::noJumpLine);

        ccColor4F blue  = {0.2f, 0.7f, 1.0f, 0.8f};
        ccColor4F red   = {1.0f, 0.3f, 0.3f, 0.8f};
        ccColor4F bdead = {1.0f, 0.8f, 0.0f, 0.8f}; // ölüm noktası sarı

        auto drawPts = [](CCDrawNode* n, const std::vector<CCPoint>& pts,
                          ccColor4F col, int deathF) {
            for (size_t i = 0; i + 1 < pts.size(); ++i) {
                ccColor4F c = (deathF >= 0 && (int)i >= deathF - 2) ?
                    ccColor4F{1.f,0.8f,0.f,0.8f} : col;
                n->drawSegment(pts[i], pts[i+1], 1.8f, c);
            }
            // Ölüm noktasına X işareti
            if (deathF >= 0 && deathF < (int)pts.size()) {
                CCPoint dp = pts[deathF];
                n->drawSegment({dp.x-6,dp.y-6},{dp.x+6,dp.y+6}, 2.f, {1,0,0,1});
                n->drawSegment({dp.x+6,dp.y-6},{dp.x-6,dp.y+6}, 2.f, {1,0,0,1});
            }
        };
        drawPts(EH::jumpLine,   jr.pts,  blue, jr.deathFrame);
        drawPts(EH::noJumpLine, njr.pts, red,  njr.deathFrame);
    }

    // Karar
    bool jump;
    if (!jr.dies && njr.dies)  jump = true;
    else if (jr.dies && !njr.dies) jump = false;
    else if (jr.dies && njr.dies)  jump = false; // ikisi de ölüyor, varsayılan
    else {
        // İkisi de güvenli → aktif mod kontrolü
        if (ship || swing) jump = (pos.y < 130.f) ^ gflip;
        else if (dart)     jump = (vy < -2.f) ^ gflip;
        else               jump = (p->m_isOnGround && vy <= 0.f);
    }

    if (jump) p->pushButton(PlayerButton::Jump);
    else      p->releaseButton(PlayerButton::Jump);
}

// ══════════════════════════════════════════════════════════════════
//  HITBOX ÇIZIMI
// ══════════════════════════════════════════════════════════════════
static void drawHitboxes(PlayLayer* pl) {
    if (!EH::showHitboxes || !pl) return;

    if (!EH::hitboxNode) {
        EH::hitboxNode = CCDrawNode::create();
        EH::hitboxNode->setZOrder(9998);
        pl->m_objectLayer->addChild(EH::hitboxNode);
    }
    EH::hitboxNode->clear();

    // Player hitbox
    auto drawPlayer = [&](PlayerObject* p) {
        if (!p) return;
        CCRect r = p->boundingBox();
        ccColor4F col = {0.f, 1.f, 0.f, 0.8f};
        EH::hitboxNode->drawRect(r.origin, {r.origin.x+r.size.width, r.origin.y+r.size.height}, {0,0,0,0}, 1.5f, col);
    };
    drawPlayer(pl->m_player1);
    if (pl->m_player2) drawPlayer(pl->m_player2);

    // Obje hitbox'ları (yakın olanlar)
    if (!pl->m_objects) return;
    CCPoint pp = pl->m_player1 ? pl->m_player1->getPosition() : CCPointZero;
    for (unsigned i = 0; i < pl->m_objects->count(); ++i) {
        auto* obj = dynamic_cast<GameObject*>(pl->m_objects->objectAtIndex(i));
        if (!obj || !obj->isVisible()) continue;
        if (std::abs(obj->getPositionX() - pp.x) > 400.f) continue;
        CCRect r = obj->boundingBox();
        ccColor4F col = {1.f, 0.3f, 0.3f, 0.5f}; // kırmızı = tehlike
        EH::hitboxNode->drawRect(r.origin, {r.origin.x+r.size.width, r.origin.y+r.size.height}, {0,0,0,0}, 1.f, col);
    }
}

// ══════════════════════════════════════════════════════════════════
//  GHOST TRAIL
// ══════════════════════════════════════════════════════════════════
static void updateGhostTrail(PlayLayer* pl, float dt) {
    if (!EH::ghostTrail || !pl) return;
    EH::trailTimer += dt;
    if (EH::trailTimer < 0.05f) return;
    EH::trailTimer = 0.f;

    auto* p = pl->m_player1;
    if (!p) return;

    // Oyuncunun kopyasını sprite olarak bırak ve solar
    auto* ghost = CCSprite::create("playerSquare_001.png");
    if (!ghost) return;
    ghost->setPosition(p->getPosition());
    ghost->setRotation(p->getRotation());
    ghost->setScaleX(p->getScaleX() * 0.8f);
    ghost->setScaleY(p->getScaleY() * 0.8f);
    ghost->setColor({100, 200, 255});
    ghost->setOpacity(140);
    pl->m_objectLayer->addChild(ghost, 9990);

    // Solma aksiyonu
    ghost->runAction(CCSequence::create(
        CCFadeTo::create(0.4f, 0),
        CCRemoveSelf::create(),
        nullptr
    ));
}

// ══════════════════════════════════════════════════════════════════
//  FPS / STATS OVERLAY  (UI katmanına label ekliyoruz)
// ══════════════════════════════════════════════════════════════════
static CCLabelBMFont* s_fpsLabel      = nullptr;
static CCLabelBMFont* s_statsLabel    = nullptr;
static float          s_fpsTimer      = 0.f;
static int            s_frameCount    = 0;

static void initOverlayLabels(PlayLayer* pl) {
    auto win = CCDirector::sharedDirector()->getWinSize();

    if (!s_fpsLabel) {
        s_fpsLabel = CCLabelBMFont::create("FPS: --", "bigFont.fnt");
        s_fpsLabel->setScale(0.35f);
        s_fpsLabel->setAnchorPoint({0, 1});
        s_fpsLabel->setPosition({5.f, win.height - 5.f});
        s_fpsLabel->setZOrder(100000);
        pl->addChild(s_fpsLabel);
    }
    if (!s_statsLabel) {
        s_statsLabel = CCLabelBMFont::create("", "bigFont.fnt");
        s_statsLabel->setScale(0.3f);
        s_statsLabel->setAnchorPoint({0, 1});
        s_statsLabel->setPosition({5.f, win.height - 22.f});
        s_statsLabel->setZOrder(100000);
        pl->addChild(s_statsLabel);
    }
}

static void updateOverlay(PlayLayer* pl, float dt) {
    if (!pl) return;

    s_fpsTimer  += dt;
    s_frameCount++;
    if (s_fpsTimer >= 0.5f) {
        float fps = s_frameCount / s_fpsTimer;
        s_fpsTimer = 0.f; s_frameCount = 0;
        if (s_fpsLabel && EH::showFPS)
            s_fpsLabel->setString(("FPS: " + fmtFloat(fps, 1)).c_str());
    }
    if (s_fpsLabel) s_fpsLabel->setVisible(EH::showFPS);

    // CPS
    EH::cpsTimer += dt;
    if (EH::cpsTimer >= 1.f) {
        EH::currentCPS = EH::clickCount / EH::cpsTimer;
        EH::clickCount = 0; EH::cpsTimer = 0.f;
    }

    // Stats label
    if (s_statsLabel) {
        std::string txt;
        auto* level = pl->m_level;
        if (EH::showAttempts && level)
            txt += "ATT: " + std::to_string((int)level->m_attempts.value()) + "  ";
        if (EH::showPercent && level)
            txt += "%" + std::to_string((int)level->m_normalPercent.value()) + "  ";
        if (EH::showCPS)
            txt += "CPS: " + fmtFloat(EH::currentCPS, 1);
        s_statsLabel->setString(txt.c_str());
        s_statsLabel->setVisible(!txt.empty());
    }
}

// ══════════════════════════════════════════════════════════════════
//  AUTO CHECKPOINT
// ══════════════════════════════════════════════════════════════════
static void updateAutoCheckpoint(PlayLayer* pl, float dt) {
    if (!EH::checkpointEveryX || !pl) return;
    EH::acTimer += dt;
    if (EH::acTimer >= (float)EH::checkpointInterval) {
        EH::acTimer = 0.f;
        // Practice modunda checkpoint ekle
        if (pl->m_isPracticeMode) {
            EH::dbgLog("Auto checkpoint: use manual checkpoint");
        }
    }
}

// ══════════════════════════════════════════════════════════════════
//  MİRROR MOD  (kamera X scale)
// ══════════════════════════════════════════════════════════════════
static void applyMirror(PlayLayer* pl) {
    if (!pl) return;
    float sx = EH::mirrorMode ? -1.f : 1.f;
    // Camera/objectLayer düzeyinde flip
    if (pl->m_objectLayer) {
        auto win = CCDirector::sharedDirector()->getWinSize();
        if (EH::mirrorMode) {
            pl->m_objectLayer->setScaleX(-1.f);
            // anchor noktasını sağa kaydır
            pl->m_objectLayer->setPositionX(win.width);
        } else {
            pl->m_objectLayer->setScaleX(1.f);
            pl->m_objectLayer->setPositionX(0.f);
        }
    }
}

// ══════════════════════════════════════════════════════════════════
//  SPEEDHACK  (CCScheduler time scale hook)
// ══════════════════════════════════════════════════════════════════
class $modify(EHScheduler, CCScheduler) {
    void update(float dt) {
        CCScheduler::update(dt * EH::speedhack);
    }
};

// ══════════════════════════════════════════════════════════════════
//  PLAYER OBJECT HOOK  (rotation, scale, gravity, click count)
// ══════════════════════════════════════════════════════════════════
class $modify(EHPlayerObject, PlayerObject) {
    void update(float dt) {
        PlayerObject::update(dt);

        if (EH::noRotation)   this->setRotation(0.f);
        if (EH::smallPlayer)  { this->setScaleX(0.5f); this->setScaleY(0.5f); }
    }

    bool init(int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4) {
        bool res = PlayerObject::init(p0, p1, p2, p3, p4);
        return res;
    }

    void pushButton(PlayerButton btn) {
        PlayerObject::pushButton(btn);
        if (btn == PlayerButton::Jump) EH::clickCount++;
    }
};

// ══════════════════════════════════════════════════════════════════
//  PANEL GUI  ─  sekmeli, slider'lı
// ══════════════════════════════════════════════════════════════════

// Basit slider yardımcısı (CCSlider Geode'da var)
static CCMenuItemSpriteExtra* makeBtn(const char* lbl, int w,
                                      const char* font,
                                      const char* bg,
                                      float h, float s,
                                      CCObject* tgt, SEL_MenuHandler sel)
{
    return CCMenuItemSpriteExtra::create(
        ButtonSprite::create(lbl, w, true, font, bg, h, s),
        tgt, sel
    );
}

// Sekme sabitleri
static const char* TAB_NAMES[] = {"Bypass","Visual","Player","Speed","Stats","Debug"};
static const int   TAB_COUNT   = 6;
static const float PANEL_W     = 320.f;
static const float PANEL_H     = 260.f;

class EmirHubPanel : public CCLayer {
public:
    // ── Panel bileşenleri ──────────────────────────────────────
    CCLayerColor*    m_bg        = nullptr;
    CCMenu*          m_tabMenu   = nullptr;
    CCMenu*          m_bodyMenu  = nullptr;
    CCNode*          m_tabPages[TAB_COUNT] = {};
    CCLabelBMFont*   m_titleLbl  = nullptr;
    Slider*        m_speedSlider = nullptr;
    Slider*        m_zoomSlider  = nullptr;
    CCLabelBMFont*   m_speedValLbl = nullptr;
    CCLabelBMFont*   m_zoomValLbl  = nullptr;
    CCLabelBMFont*   m_debugTextLbl = nullptr;
    // Tag aralıkları: toggle butonları 2000+

    // ── Fabrika ───────────────────────────────────────────────
    static EmirHubPanel* create() {
        auto* r = new EmirHubPanel();
        if (r && r->init()) { r->autorelease(); return r; }
        CC_SAFE_DELETE(r); return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) return false;
        this->setTouchEnabled(false);

        auto win = CCDirector::sharedDirector()->getWinSize();
        float cx = win.width / 2, cy = win.height / 2;

        // ── Arka plan ──
        m_bg = CCLayerColor::create({10,10,30,210}, PANEL_W, PANEL_H);
        m_bg->setPosition({cx - PANEL_W/2, cy - PANEL_H/2});
        m_bg->setVisible(false);
        this->addChild(m_bg, 100);

        // ── Başlık ──
        m_titleLbl = CCLabelBMFont::create("EMIR HUB v3", "goldFont.fnt");
        m_titleLbl->setScale(0.55f);
        m_titleLbl->setPosition({cx, cy + PANEL_H/2 - 14.f});
        m_titleLbl->setVisible(false);
        this->addChild(m_titleLbl, 102);

        // ── Açma butonu (her zaman görünür) ──
        auto* openMenu = CCMenu::create();
        openMenu->setPosition(0,0);
        this->addChild(openMenu, 103);

        auto* openBtn = makeBtn("EH", 60, "goldFont.fnt", "GJ_button_04.png", 28.f, 1.f,
                                this, menu_selector(EmirHubPanel::onToggleMenu));
        openBtn->setPosition({55.f, cy});
        openMenu->addChild(openBtn);

        // ── Sekme menüsü ──
        m_tabMenu = CCMenu::create();
        m_tabMenu->setPosition(0,0);
        m_tabMenu->setVisible(false);
        this->addChild(m_tabMenu, 102);

        float tabX = cx - PANEL_W/2 + 10.f;
        float tabY = cy + PANEL_H/2 - 34.f;
        float tabSpacing = PANEL_W / TAB_COUNT;
        for (int i = 0; i < TAB_COUNT; ++i) {
            auto* tb = makeBtn(TAB_NAMES[i], 46, "chatFont.fnt",
                               i == EH::activeTab ? "GJ_button_02.png" : "GJ_button_04.png",
                               18.f, 0.5f,
                               this, menu_selector(EmirHubPanel::onTab));
            tb->setPosition({tabX + i * tabSpacing + tabSpacing/2, tabY});
            tb->setTag(3000 + i);
            m_tabMenu->addChild(tb);
        }

        // ── Sayfa içerikleri ──
        buildBypassPage(cx, cy);
        buildVisualPage(cx, cy);
        buildPlayerPage(cx, cy);
        buildSpeedPage(cx, cy);
        buildStatsPage(cx, cy);
        buildDebugPage(cx, cy);

        // ── Kapat butonu ──
        m_bodyMenu = CCMenu::create();
        m_bodyMenu->setPosition(0,0);
        m_bodyMenu->setVisible(false);
        this->addChild(m_bodyMenu, 103);

        auto* closeBtn = makeBtn("X", 28, "bigFont.fnt", "GJ_button_06.png", 20.f, 0.7f,
                                 this, menu_selector(EmirHubPanel::onToggleMenu));
        closeBtn->setPosition({cx + PANEL_W/2 - 16.f, cy + PANEL_H/2 - 14.f});
        m_bodyMenu->addChild(closeBtn);

        showTab(EH::activeTab);
        return true;
    }

    // ─────────────────────────────────────────────
    //  Sayfa oluşturucular
    // ─────────────────────────────────────────────
    CCMenu* newPage(float cx, float cy) {
        auto* m = CCMenu::create();
        m->setPosition(0,0);
        m->setVisible(false);
        this->addChild(m, 101);
        return m;
    }

    // Toggle butonu  (tag ile durum tutulur; callback içinde bool'u flip eder)
    CCMenuItemSpriteExtra* addToggle(CCMenu* menu, const char* lbl, int tag,
                                     float x, float y, bool state, SEL_MenuHandler sel)
    {
        const char* bg = state ? "GJ_button_02.png" : "GJ_button_01.png";
        auto* btn = makeBtn(lbl, 120, "chatFont.fnt", bg, 20.f, 0.65f, this, sel);
        btn->setTag(tag);
        btn->setPosition({x, y});
        menu->addChild(btn);
        return btn;
    }

    // İki sütunlu grid için yardımcı (ileride genişletilebilir)
    CCPoint gridPos(int i, float cx, float startY, float colW = 135.f, float rowH = 28.f) {
        int col = i % 2, row = i / 2;
        float x = cx + (col == 0 ? -colW/2 - 5.f : colW/2 + 5.f);
        float y = startY - row * rowH;
        return {x, y};
    }

    // ── Bypass ──
    void buildBypassPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[0] = m;
        float sy = cy + PANEL_H/2 - 60.f;
        float lx = cx - 68.f, rx = cx + 68.f;
        float rh = 28.f;

        addToggle(m, "Noclip P1",  2000, lx, sy,       EH::noclip,       menu_selector(EmirHubPanel::onNoclip));
        addToggle(m, "Noclip P2",  2001, rx, sy,       EH::noclipP2,     menu_selector(EmirHubPanel::onNoclipP2));
        addToggle(m, "AutoPlay",   2002, lx, sy-rh,    EH::autoPlay,     menu_selector(EmirHubPanel::onAutoPlay));
        addToggle(m, "Traj Lines", 2003, rx, sy-rh,    EH::showTrajLines,menu_selector(EmirHubPanel::onTrajLines));
        addToggle(m, "Inf. Lives", 2004, lx, sy-rh*2,  EH::infiniteLives,menu_selector(EmirHubPanel::onInfLives));
        addToggle(m, "Inst.Resp.", 2005, rx, sy-rh*2,  EH::instantRespawn,menu_selector(EmirHubPanel::onInstResp));
        addToggle(m, "PracticeMusic",2006,lx, sy-rh*3, EH::practiceMusic,menu_selector(EmirHubPanel::onPracticeMusic));
        addToggle(m, "AutoCheckpt",2007, rx, sy-rh*3,  EH::checkpointEveryX,menu_selector(EmirHubPanel::onAutoCheckpt));
        addToggle(m, "Anti-Push",  2008, lx, sy-rh*4,  EH::antiPush,     menu_selector(EmirHubPanel::onAntiPush));
    }

    // ── Visual ──
    void buildVisualPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[1] = m;
        float sy = cy + PANEL_H/2 - 60.f;
        float lx = cx - 68.f, rx = cx + 68.f;
        float rh = 28.f;

        addToggle(m, "Hitboxes",  2100, lx, sy,       EH::showHitboxes,menu_selector(EmirHubPanel::onHitboxes));
        addToggle(m, "Show FPS",  2101, rx, sy,       EH::showFPS,     menu_selector(EmirHubPanel::onShowFPS));
        addToggle(m, "HidePlayer",2102, lx, sy-rh,   EH::hidePlayer,  menu_selector(EmirHubPanel::onHidePlayer));
        addToggle(m, "Hide BG",   2103, rx, sy-rh,   EH::hideBG,      menu_selector(EmirHubPanel::onHideBG));
        addToggle(m, "HideGround",2104, lx, sy-rh*2, EH::hideGround,  menu_selector(EmirHubPanel::onHideGround));
        addToggle(m, "HideObjs",  2105, rx, sy-rh*2, EH::hideObjects, menu_selector(EmirHubPanel::onHideObjects));
        addToggle(m, "Mirror",    2106, lx, sy-rh*3, EH::mirrorMode,  menu_selector(EmirHubPanel::onMirror));
        addToggle(m, "Ghost Trail",2107,rx, sy-rh*3, EH::ghostTrail,  menu_selector(EmirHubPanel::onGhostTrail));
    }

    // ── Player ──
    void buildPlayerPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[2] = m;
        float sy = cy + PANEL_H/2 - 60.f;
        float lx = cx - 68.f, rx = cx + 68.f;
        float rh = 28.f;

        addToggle(m, "Gravity Flip",2200, lx, sy,      EH::gravityFlip, menu_selector(EmirHubPanel::onGravFlip));
        addToggle(m, "Small Player",2201, rx, sy,      EH::smallPlayer, menu_selector(EmirHubPanel::onSmallPlayer));
        addToggle(m, "No Rotation", 2202, lx, sy-rh,  EH::noRotation,  menu_selector(EmirHubPanel::onNoRotation));
    }

    // ── Speed ──
    void buildSpeedPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[3] = m;
        float sy = cy + PANEL_H/2 - 65.f;

        // Speedhack label
        auto* shlbl = CCLabelBMFont::create("Speedhack: 1.00x", "bigFont.fnt");
        shlbl->setScale(0.38f);
        shlbl->setPosition({cx, sy});
        shlbl->setTag(4000);
        m->addChild(shlbl);

        // Slider  (Geode CCSlider)
        auto* shSlider = Slider::create(this, menu_selector(EmirHubPanel::onSpeedSlider), 1.f);
        shSlider->setPosition({cx, sy - 22.f});
        shSlider->setValue(0.167f); // 1.0 / 6.0
        shSlider->setTag(4001);
        m->addChild(shSlider);

        // Music speed label
        auto* mslbl = CCLabelBMFont::create("Music Speed: 1.00x", "bigFont.fnt");
        mslbl->setScale(0.38f);
        mslbl->setPosition({cx, sy - 55.f});
        mslbl->setTag(4002);
        m->addChild(mslbl);

        auto* msSlider = Slider::create(this, menu_selector(EmirHubPanel::onMusicSlider), 1.f);
        msSlider->setPosition({cx, sy - 77.f});
        msSlider->setValue(0.333f); // 1.0 / 3.0
        msSlider->setTag(4003);
        m->addChild(msSlider);

        // Zoom label
        auto* zmlbl = CCLabelBMFont::create("Camera Zoom: 1.00x", "bigFont.fnt");
        zmlbl->setScale(0.38f);
        zmlbl->setPosition({cx, sy - 110.f});
        zmlbl->setTag(4004);
        m->addChild(zmlbl);

        auto* zmSlider = Slider::create(this, menu_selector(EmirHubPanel::onZoomSlider), 1.f);
        zmSlider->setPosition({cx, sy - 130.f});
        zmSlider->setValue(0.25f); // 1.0 / 4.0
        zmSlider->setTag(4005);
        m->addChild(zmSlider);
    }

    // ── Stats ──
    void buildStatsPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[4] = m;
        float sy = cy + PANEL_H/2 - 60.f;
        float lx = cx - 68.f, rx = cx + 68.f;
        float rh = 28.f;

        addToggle(m, "Attempts",  2400, lx, sy,      EH::showAttempts,menu_selector(EmirHubPanel::onShowAttempts));
        addToggle(m, "Percent",   2401, rx, sy,      EH::showPercent, menu_selector(EmirHubPanel::onShowPercent));
        addToggle(m, "CPS Meter", 2402, lx, sy-rh,  EH::showCPS,     menu_selector(EmirHubPanel::onShowCPS));
    }

    // ── Debug ──
    void buildDebugPage(float cx, float cy) {
        auto* m = newPage(cx, cy);
        m_tabPages[5] = m;

        // Debug log alanı
        m_debugTextLbl = CCLabelBMFont::create("No debug info yet.", "chatFont.fnt");
        m_debugTextLbl->setScale(0.4f);
        m_debugTextLbl->setAnchorPoint({0.f, 1.f});
        m_debugTextLbl->setPosition({cx - PANEL_W/2 + 8.f, cy + PANEL_H/2 - 50.f});
        m_debugTextLbl->setWidth(PANEL_W - 16.f);
        m->addChild(m_debugTextLbl);

        // Clear log butonu
        auto* clrBtn = makeBtn("Clear Log", 100, "chatFont.fnt", "GJ_button_06.png", 18.f, 0.55f,
                               this, menu_selector(EmirHubPanel::onClearLog));
        clrBtn->setPosition({cx, cy - PANEL_H/2 + 18.f});
        m->addChild(clrBtn);
    }

    // ─────────────────────────────────────────────
    //  Sekme göster/gizle
    // ─────────────────────────────────────────────
    void showTab(int idx) {
        EH::activeTab = idx;
        for (int i = 0; i < TAB_COUNT; ++i) {
            if (m_tabPages[i]) m_tabPages[i]->setVisible(EH::menuOpen && i == idx);
            auto* tb = dynamic_cast<CCNode*>(m_tabMenu->getChildByTag(3000 + i));
            if (tb) tb->setColor(i == idx ? ccColor3B{120,220,120} : ccColor3B{255,255,255});
        }
        // Debug sayfasını her seferinde güncelle
        if (idx == 5) refreshDebugLog();
    }

    void refreshDebugLog() {
        if (!m_debugTextLbl) return;
        // Player info
        std::string info;
        if (auto* pl = PlayLayer::get()) {
            auto* p = pl->m_player1;
            if (p) {
                info += "Pos: (" + fmtFloat(p->getPositionX(),1) + ", " + fmtFloat(p->getPositionY(),1) + ")\n";
                info += "VelY: " + fmtFloat((float)p->getYVelocity(),3) + "\n";
                info += "Mode: ";
                if (p->m_isShip)  info += "Ship";
                else if (p->m_isDart)  info += "Wave";
                else if (p->m_isBall)  info += "Ball";
                else if (p->m_isUfo)   info += "UFO";
                else if (p->m_isRobot) info += "Robot";
                else if (p->m_isSpider)info += "Spider";
                else if (p->m_isSwing) info += "Swing";
                else info += "Cube";
                info += "\n";
                info += "Gravity: " + std::string(p->m_isUpsideDown ? "Flipped" : "Normal") + "\n";
                info += "OnGround: " + std::string(p->m_isOnGround ? "Yes" : "No") + "\n";
                info += "Speedhack: " + fmtFloat(EH::speedhack, 2) + "x\n";
                info += "FPS: " + fmtFloat(
                    CCDirector::sharedDirector()->getFrameRate(), 0) + "\n";
            }
        }
        // Son log mesajları
        info += "──── Log ────\n";
        int start = std::max(0, (int)EH::debugLog.size() - 6);
        for (int i = start; i < (int)EH::debugLog.size(); ++i)
            info += EH::debugLog[i] + "\n";
        m_debugTextLbl->setString(info.c_str());
    }

    // ─────────────────────────────────────────────
    //  Menü aç/kapat
    // ─────────────────────────────────────────────
    void setMenuVisible(bool v) {
        EH::menuOpen = v;
        if (m_bg)       m_bg->setVisible(v);
        if (m_titleLbl) m_titleLbl->setVisible(v);
        if (m_tabMenu)  m_tabMenu->setVisible(v);
        if (m_bodyMenu) m_bodyMenu->setVisible(v);
        showTab(EH::activeTab);
    }

    void onToggleMenu(CCObject*) { setMenuVisible(!EH::menuOpen); }

    void onTab(CCObject* s) {
        auto* btn = dynamic_cast<CCNode*>(s);
        if (!btn) return;
        int idx = btn->getTag() - 3000;
        if (idx < 0 || idx >= TAB_COUNT) return;
        showTab(idx);
    }

    // ─────────────────────────────────────────────
    //  Toggle callback'leri
    // ─────────────────────────────────────────────
    void flipColor(CCObject* s, bool& flag) {
        flag = !flag;
        auto* btn = dynamic_cast<CCNode*>(s);
        if (btn) btn->setColor(flag ? ccColor3B{100,255,100} : ccColor3B{255,255,255});
    }

    void onNoclip(CCObject* s)       { flipColor(s, EH::noclip);        toast(EH::noclip ? "Noclip ON" : "Noclip OFF"); }
    void onNoclipP2(CCObject* s)     { flipColor(s, EH::noclipP2);      toast(EH::noclipP2 ? "Noclip P2 ON" : "Noclip P2 OFF"); }
    void onAutoPlay(CCObject* s)     {
        flipColor(s, EH::autoPlay);
        if (!EH::autoPlay) {
            if (EH::jumpLine)   EH::jumpLine->clear();
            if (EH::noJumpLine) EH::noJumpLine->clear();
        }
        EH::dbgLog(EH::autoPlay ? "AutoPlay ON" : "AutoPlay OFF");
        toast(EH::autoPlay ? "AutoPlay ON" : "AutoPlay OFF");
    }
    void onTrajLines(CCObject* s)    { flipColor(s, EH::showTrajLines);  toast(EH::showTrajLines ? "Traj ON" : "Traj OFF"); }
    void onInfLives(CCObject* s)     { flipColor(s, EH::infiniteLives);  toast(EH::infiniteLives ? "Infinite Lives ON" : "Infinite Lives OFF"); }
    void onInstResp(CCObject* s)     { flipColor(s, EH::instantRespawn); toast(EH::instantRespawn ? "Instant Respawn ON" : "OFF"); }
    void onPracticeMusic(CCObject* s){ flipColor(s, EH::practiceMusic);  toast(EH::practiceMusic ? "Practice Music ON" : "OFF"); }
    void onAutoCheckpt(CCObject* s)  { flipColor(s, EH::checkpointEveryX); toast(EH::checkpointEveryX ? "Auto Checkpoint ON" : "OFF"); }
    void onAntiPush(CCObject* s)     { flipColor(s, EH::antiPush);       toast(EH::antiPush ? "Anti-Push ON" : "OFF"); }

    void onHitboxes(CCObject* s)     { flipColor(s, EH::showHitboxes);
        if (!EH::showHitboxes && EH::hitboxNode) EH::hitboxNode->clear();
    }
    void onShowFPS(CCObject* s)      { flipColor(s, EH::showFPS); }
    void onHidePlayer(CCObject* s)   {
        flipColor(s, EH::hidePlayer);
        if (auto* pl = PlayLayer::get())
            if (pl->m_player1) pl->m_player1->setVisible(!EH::hidePlayer);
    }
    void onHideBG(CCObject* s) {
        flipColor(s, EH::hideBG);
        if (auto* pl = PlayLayer::get()) {
            // BG layer: iterate children tagged as BG
            for (auto* child : CCArrayExt<CCNode*>(pl->getChildren())) {
                if (child && child->getTag() == 1000) child->setVisible(!EH::hideBG);
            }
        }
    }
    void onHideGround(CCObject* s) {
        flipColor(s, EH::hideGround);
        if (auto* pl = PlayLayer::get()) {
            if (pl->m_groundLayer) pl->m_groundLayer->setVisible(!EH::hideGround);
        }
    }
    void onHideObjects(CCObject* s) {
        flipColor(s, EH::hideObjects);
        if (auto* pl = PlayLayer::get()) {
            if (pl->m_objectLayer) pl->m_objectLayer->setVisible(!EH::hideObjects);
        }
    }
    void onMirror(CCObject* s) {
        flipColor(s, EH::mirrorMode);
        if (auto* pl = PlayLayer::get()) applyMirror(pl);
    }
    void onGhostTrail(CCObject* s)   { flipColor(s, EH::ghostTrail); }

    void onGravFlip(CCObject* s) {
        flipColor(s, EH::gravityFlip);
        if (auto* pl = PlayLayer::get()) {
            if (pl->m_player1)
                pl->flipGravity(pl->m_player1, EH::gravityFlip, false);
        }
    }
    void onSmallPlayer(CCObject* s)  { flipColor(s, EH::smallPlayer); }
    void onNoRotation(CCObject* s)   { flipColor(s, EH::noRotation); }

    void onShowAttempts(CCObject* s) { flipColor(s, EH::showAttempts); }
    void onShowPercent(CCObject* s)  { flipColor(s, EH::showPercent); }
    void onShowCPS(CCObject* s)      { flipColor(s, EH::showCPS); }

    void onClearLog(CCObject*) {
        EH::debugLog.clear();
        if (m_debugTextLbl) m_debugTextLbl->setString("Log cleared.");
    }

    // ─────────────────────────────────────────────
    //  Slider callback'leri
    // ─────────────────────────────────────────────
    void onSpeedSlider(CCObject* s) {
        auto* sl = dynamic_cast<Slider*>(s);
        if (!sl) return;
        // 0.0 → 0.1x,  1.0 → 6.0x
        EH::speedhack = 0.1f + sl->getValue() * 5.9f;
        auto* lbl = dynamic_cast<CCLabelBMFont*>(
            dynamic_cast<CCNode*>(m_tabPages[3])->getChildByTag(4000));
        if (lbl) lbl->setString(("Speedhack: " + fmtFloat(EH::speedhack) + "x").c_str());
        EH::dbgLog("Speedhack -> " + fmtFloat(EH::speedhack));
    }

    void onMusicSlider(CCObject* s) {
        auto* sl = dynamic_cast<Slider*>(s);
        if (!sl) return;
        EH::musicSpeed = 0.5f + sl->getValue() * 2.5f; // 0.5x – 3.0x
        // Music speed via FMOD pitch
        auto* fmod = FMODAudioEngine::sharedEngine();
        if (fmod && fmod->m_backgroundMusicChannel) fmod->m_backgroundMusicChannel->setPitch(EH::musicSpeed);
        auto* lbl = dynamic_cast<CCLabelBMFont*>(
            dynamic_cast<CCNode*>(m_tabPages[3])->getChildByTag(4002));
        if (lbl) lbl->setString(("Music Speed: " + fmtFloat(EH::musicSpeed) + "x").c_str());
        EH::dbgLog("Music speed -> " + fmtFloat(EH::musicSpeed));
    }

    void onZoomSlider(CCObject* s) {
        auto* sl = dynamic_cast<Slider*>(s);
        if (!sl) return;
        EH::cameraZoom = 0.5f + sl->getValue() * 3.5f; // 0.5x – 4.0x
        if (auto* pl = PlayLayer::get()) {
            if (pl->m_objectLayer) pl->m_objectLayer->setScale(EH::cameraZoom);
        }
        auto* lbl = dynamic_cast<CCLabelBMFont*>(
            dynamic_cast<CCNode*>(m_tabPages[3])->getChildByTag(4004));
        if (lbl) lbl->setString(("Camera Zoom: " + fmtFloat(EH::cameraZoom) + "x").c_str());
    }

    // Her frame debug sekmesi açıksa güncelle
    void updateDebugIfOpen() {
        if (EH::menuOpen && EH::activeTab == 5) refreshDebugLog();
    }
};

// ══════════════════════════════════════════════════════════════════
//  PLAY LAYER HOOK
// ══════════════════════════════════════════════════════════════════
static EmirHubPanel* s_panel = nullptr;

class $modify(EHPlayLayer, PlayLayer) {

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        // Draw node'ları sıfırla
        EH::jumpLine = EH::noJumpLine = EH::hitboxNode = nullptr;
        s_fpsLabel = s_statsLabel = nullptr;
        s_fpsTimer = 0.f; s_frameCount = 0;
        EH::cpsTimer = 0.f; EH::clickCount = 0; EH::acTimer = 0.f;
        EH::trailTimer = 0.f;
        EH::debugLog.clear();

        // Panel
        s_panel = EmirHubPanel::create();
        this->addChild(s_panel, 99999);

        // Overlay label'ları
        initOverlayLabels(this);

        // Mirror uygula (önceki oturumdan kalan durum varsa)
        if (EH::mirrorMode) applyMirror(this);

        EH::dbgLog("Level loaded");
        toast("Emir Hub v3 Loaded");
        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);

        runAutoPlay(this);
        drawHitboxes(this);
        updateGhostTrail(this, dt);
        updateOverlay(this, dt);
        updateAutoCheckpoint(this, dt);
        if (s_panel) s_panel->updateDebugIfOpen();

        // Anti-push: objelerin player'ı itmesi (velocity sıfırla değil, sadece debug)
        // Gerçek implementasyon checkCollisions hook gerektirir.

        // Practice music toggle (her frame değil, state değişince yeterli ama)
        // Bu PlayLayer'ın practiceLayer bayrağına göre müzik çalar/çalmaz.
    }

    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        // Noclip kontrolü
        if (player == this->m_player1 && EH::noclip) return;
        if (EH::noclipP2 && player != this->m_player1) return;

        // Infinite lives: reset etme ama ölümü kaydet
        if (EH::infiniteLives) {
            EH::dbgLog("Death ignored (infinite lives)");
            return;
        }

        // Instant respawn: normal ölüm ama hemen resetle
        if (EH::instantRespawn) {
            PlayLayer::destroyPlayer(player, obj);
            this->resetLevel();
            return;
        }

        PlayLayer::destroyPlayer(player, obj);
    }

    // Practice mode müzik
    void resetLevel() {
        PlayLayer::resetLevel();
        // Müzik hızını koru
        if (EH::musicSpeed != 1.0f) {
            auto* fmod = FMODAudioEngine::sharedEngine();
            if (fmod && fmod->m_backgroundMusicChannel) fmod->m_backgroundMusicChannel->setPitch(EH::musicSpeed);
        }
        EH::dbgLog("Level reset");
    }
};

// ══════════════════════════════════════════════════════════════════
//  MOD YÜKLENME
// ══════════════════════════════════════════════════════════════════
$on_mod(Loaded) {
    log::info("Emir Hub v3.0 loaded successfully");
    EH::dbgLog("Mod loaded");
}
