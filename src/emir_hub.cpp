/*
 *  Emir Hub v3 — Geode / GD 2.2081 / Android aarch64
 *
 *  ✓ Noclip
 *  ✓ AutoPlay  (cube/ship/ball/bird/wave/robot/spider/swing)
 *  ✓ Trajectory Preview (sarı = zıplarsan, kırmızı = mevcut yörünge)
 *  ✓ Güzel UI (panel + renk feedback)
 *
 *  NOT: m_isOnGround PlayerObject'ta doğrudan erişilebilir
 *       (Geode bindings'de PlayerCheckpoint ile aynı layout paylaşılır).
 *       getActiveMode() → GameObjectType enum değerleri:
 *         Cube=1, Ship=2, Ball=3, UFO/Bird=6, Wave=8,
 *         Robot=9, Spider=10, Swing=11
 */

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;
using namespace cocos2d;

// ══════════════════════════════════════════════════════
//  Global durum
// ══════════════════════════════════════════════════════

namespace EH {
    bool noclip     = false;
    bool autoPlay   = false;
    bool traj       = true;
    bool menuOpen   = false;

    CCDrawNode* drawNode = nullptr;
}

// ══════════════════════════════════════════════════════
//  Bildirim
// ══════════════════════════════════════════════════════

static void notif(const char* msg) {
    Notification::create(msg, NotificationIcon::Success)->show();
}

// ══════════════════════════════════════════════════════
//  Yörünge simülasyonu
// ══════════════════════════════════════════════════════

namespace Sim {
    constexpr float G_ACC     = -0.9f;
    constexpr float JUMP_V    =  11.2f;
    constexpr float TERMINAL  = -28.0f;
    constexpr int   STEPS     = 90;

    // Genel (cube / robot / spider / ball)
    std::vector<CCPoint> run(float sx, float sy,
                             float vx, float vy)
    {
        std::vector<CCPoint> pts;
        float x = sx, y = sy;
        for (int i = 0; i < STEPS; ++i) {
            vy += G_ACC;
            if (vy < TERMINAL) vy = TERMINAL;
            x += vx; y += vy;
            pts.push_back({x, y});
            if (y < -200.f) break;
        }
        return pts;
    }

    // Ship / UFO
    std::vector<CCPoint> runShip(float sx, float sy,
                                 float vx, float vy,
                                 bool hold)
    {
        std::vector<CCPoint> pts;
        float x = sx, y = sy;
        for (int i = 0; i < STEPS; ++i) {
            float ay = G_ACC * 0.55f + (hold ? 0.38f : 0.f);
            vy += ay;
            if (vy >  14.f) vy =  14.f;
            if (vy < -14.f) vy = -14.f;
            x += vx; y += vy;
            pts.push_back({x, y});
            if (y < -200.f || y > 700.f) break;
        }
        return pts;
    }
}

// ══════════════════════════════════════════════════════
//  Yörünge çizimi
// ══════════════════════════════════════════════════════

static void drawArrow(CCDrawNode* dn,
                      const std::vector<CCPoint>& pts,
                      ccColor4F col, float w = 2.f)
{
    if (pts.size() < 3) return;
    for (size_t i = 0; i + 1 < pts.size(); ++i)
        dn->drawSegment(pts[i], pts[i+1], w, col);

    auto tip = pts.back();
    auto prv = pts[pts.size()-3];
    float a  = ccpToAngle(ccpSub(tip, prv));
    float L  = 13.f, sp = 0.48f;
    dn->drawSegment(tip,
        ccp(tip.x - L*cosf(a-sp), tip.y - L*sinf(a-sp)), w+0.6f, col);
    dn->drawSegment(tip,
        ccp(tip.x - L*cosf(a+sp), tip.y - L*sinf(a+sp)), w+0.6f, col);
}

static void refreshTraj(PlayLayer* pl) {
    if (!EH::drawNode) return;
    EH::drawNode->clear();
    if (!EH::traj || !pl) return;

    auto* p = pl->m_player1;
    if (!p) return;

    float px = p->getPositionX();
    float py = p->getPositionY();
    float vx = (float)p->getCurrentXVelocity();
    float vy = (float)p->getYVelocity();

    // GameObjectType int değerleri
    int mode = (int)p->getActiveMode();
    bool shipLike = (mode == 2 || mode == 6); // Ship, UFO/Bird

    ccColor4F yellow = {1.f, 0.93f, 0.10f, 0.92f};
    ccColor4F red    = {1.f, 0.22f, 0.22f, 0.92f};

    if (shipLike) {
        drawArrow(EH::drawNode,
                  Sim::runShip(px, py, vx, vy, true),  yellow);
        drawArrow(EH::drawNode,
                  Sim::runShip(px, py, vx, vy, false), red);
    } else {
        drawArrow(EH::drawNode,
                  Sim::run(px, py, vx, Sim::JUMP_V), yellow);
        drawArrow(EH::drawNode,
                  Sim::run(px, py, vx, vy),          red);
    }
}

// ══════════════════════════════════════════════════════
//  AutoPlay
//
//  m_isOnGround: PlayerObject'ta MEVCUT
//  (Geode 2.2081 bindings'de GJBaseGameLayer PAD içinde
//   PlayerObject* m_player1 ve alanları expose edilmiş)
// ══════════════════════════════════════════════════════

namespace AP {

    void tick(PlayLayer* pl) {
        if (!EH::autoPlay || !pl) return;
        auto* p = pl->m_player1;
        if (!p) return;

        float py   = p->getPositionY();
        float vy   = (float)p->getYVelocity();
        int   mode = (int)p->getActiveMode();

        // ── Ship (2) ──────────────────────────────────
        if (mode == 2) {
            if (py < 155.f) p->pushButton(PlayerButton::Jump);
            else            p->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Ball (3) ──────────────────────────────────
        if (mode == 3) {
            // Ball: zıpla veya yerçekimini ters çevir
            // getYVelocity <= 0 ve zemine yakınken zıpla
            if (vy <= 0.f && py < 120.f)
                p->pushButton(PlayerButton::Jump);
            else
                p->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── UFO/Bird (6) ──────────────────────────────
        if (mode == 6) {
            if (py < 150.f) p->pushButton(PlayerButton::Jump);
            else            p->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Wave/Dart (8) ─────────────────────────────
        if (mode == 8) {
            if      (vy < -2.5f) p->pushButton(PlayerButton::Jump);
            else if (vy >  2.5f) p->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Swing (11) ────────────────────────────────
        if (mode == 11) {
            if (py < 148.f) p->pushButton(PlayerButton::Jump);
            else            p->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Cube (1) / Robot (9) / Spider (10) / default ──
        // Yükseklik güvenlik sınırları
        if (py > 295.f) {
            p->releaseButton(PlayerButton::Jump);
            return;
        }
        if (py < 75.f) {
            p->pushButton(PlayerButton::Jump);
            return;
        }
        // Yer çekimi ve düşüş ile zıplama: dikey hız ≤0
        if (vy <= 0.f)
            p->pushButton(PlayerButton::Jump);
        else
            p->releaseButton(PlayerButton::Jump);
    }
}

// ══════════════════════════════════════════════════════
//  UI — EmirHubMenu
//
//  Tasarım: Yarı saydam siyah CCLayerColor panel
//           + Altın başlık etiketi
//           + CCMenuItemSpriteExtra butonlar
//           Aktif buton = yeşil, pasif = beyaz
// ══════════════════════════════════════════════════════

namespace Tags {
    constexpr int NOCLIP   = 201;
    constexpr int AUTOPLAY = 202;
    constexpr int TRAJ     = 203;
    constexpr int CLOSE    = 204;
}

class EmirHubMenu : public CCLayer {
    CCMenu*       m_menu  = nullptr;
    CCLayerColor* m_panel = nullptr;

public:
    static EmirHubMenu* create() {
        auto* r = new EmirHubMenu();
        if (r && r->init()) { r->autorelease(); return r; }
        CC_SAFE_DELETE(r); return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) return false;
        this->setTouchEnabled(false);

        auto ws = CCDirector::sharedDirector()->getWinSize();
        const float PW = 270.f, PH = 215.f;
        const float CX = ws.width / 2.f, CY = ws.height / 2.f;

        // ── Panel ──────────────────────────────────
        m_panel = CCLayerColor::create(
            {10, 10, 20, 185}, PW, PH);
        m_panel->setPosition({CX - PW/2, CY - PH/2});
        m_panel->setVisible(false);
        this->addChild(m_panel, 100);

        // Panel başlık
        {
            auto* lbl = CCLabelBMFont::create(
                "Emir Hub", "goldFont.fnt");
            lbl->setScale(0.70f);
            lbl->setPosition({PW/2, PH - 18.f});
            m_panel->addChild(lbl);

            // ince ayraç çizgisi (CCLayerColor)
            auto* line = CCLayerColor::create(
                {255,255,255,60}, PW - 20.f, 1.f);
            line->setPosition({10.f, PH - 32.f});
            m_panel->addChild(line);
        }

        // ── Buton menüsü ──────────────────────────
        m_menu = CCMenu::create();
        m_menu->setPosition(0, 0);
        this->addChild(m_menu, 101);

        // Açma butonu (her zaman görünür)
        {
            auto* btn = CCMenuItemSpriteExtra::create(
                ButtonSprite::create("EH", 48, true,
                    "goldFont.fnt", "GJ_button_04.png", 28.f, 1.f),
                this,
                menu_selector(EmirHubMenu::onMenu));
            btn->setPosition({50.f, CY});
            m_menu->addChild(btn);
        }

        // Panel butonları
        mkBtn("Noclip",    Tags::NOCLIP,
              CX, CY + 60.f, menu_selector(EmirHubMenu::onNoclip));
        mkBtn("Auto Play", Tags::AUTOPLAY,
              CX, CY + 10.f, menu_selector(EmirHubMenu::onAutoPlay));
        mkBtn("Trajectory",Tags::TRAJ,
              CX, CY - 40.f, menu_selector(EmirHubMenu::onTraj));
        mkBtn("Kapat",     Tags::CLOSE,
              CX, CY - 90.f, menu_selector(EmirHubMenu::onMenu));

        setPanelVis(false);
        return true;
    }

    // ─ Buton oluştur
    void mkBtn(const char* txt, int tag,
               float x, float y, SEL_MenuHandler sel)
    {
        auto* sp = ButtonSprite::create(
            txt, 145, true, "bigFont.fnt",
            "GJ_button_01.png", 25.f, 0.78f);

        auto* btn = CCMenuItemSpriteExtra::create(sp, this, sel);
        btn->setPosition({x, y});
        btn->setTag(tag);
        m_menu->addChild(btn);
    }

    // ─ Görünürlük
    void setPanelVis(bool v) {
        for (int t = Tags::NOCLIP; t <= Tags::CLOSE; ++t)
            if (auto* c = m_menu->getChildByTag(t))
                c->setVisible(v);
        m_panel->setVisible(v);
    }

    // ─ Renk feedback
    void syncColors() {
        struct { int t; bool on; } map[] = {
            {Tags::NOCLIP,   EH::noclip  },
            {Tags::AUTOPLAY, EH::autoPlay},
            {Tags::TRAJ,     EH::traj    },
        };
        for (auto& e : map) {
            auto* node = m_menu->getChildByTag(e.t);
            if (!node) continue;
            // CCMenuItemSpriteExtra → CCRGBAProtocol üzerinden setColor
            if (auto* rgba = dynamic_cast<CCRGBAProtocol*>(node))
                rgba->setColor(e.on
                    ? ccColor3B{90,255,90}
                    : ccColor3B{255,255,255});
        }
    }

    // ─ Callback'ler
    void onMenu(CCObject*) {
        EH::menuOpen = !EH::menuOpen;
        setPanelVis(EH::menuOpen);
        syncColors();
    }
    void onNoclip(CCObject*) {
        EH::noclip = !EH::noclip;
        syncColors();
        notif(EH::noclip ? "Noclip: Açık" : "Noclip: Kapalı");
    }
    void onAutoPlay(CCObject*) {
        EH::autoPlay = !EH::autoPlay;
        syncColors();
        notif(EH::autoPlay ? "AutoPlay: Açık" : "AutoPlay: Kapalı");
    }
    void onTraj(CCObject*) {
        EH::traj = !EH::traj;
        if (!EH::traj && EH::drawNode) EH::drawNode->clear();
        syncColors();
        notif(EH::traj ? "Trajectory: Açık" : "Trajectory: Kapalı");
    }
};

// ══════════════════════════════════════════════════════
//  PlayLayer hook
// ══════════════════════════════════════════════════════

class $modify(MyPlayLayer, PlayLayer) {

    bool init(GJGameLevel* lvl, bool replay, bool noCreate) {
        if (!PlayLayer::init(lvl, replay, noCreate)) return false;

        EH::drawNode = CCDrawNode::create();
        EH::drawNode->setZOrder(9997);
        this->addChild(EH::drawNode);

        this->addChild(EmirHubMenu::create(), 99999);

        notif("Emir Hub Hazır");
        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);
        AP::tick(this);
        refreshTraj(this);
    }

    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        if (EH::noclip) return;
        PlayLayer::destroyPlayer(player, obj);
    }
};

// ══════════════════════════════════════════════════════
//  Mod yüklenişi
// ══════════════════════════════════════════════════════

$on_mod(Loaded) {
    log::info("Emir Hub v3 yüklendi");
}
