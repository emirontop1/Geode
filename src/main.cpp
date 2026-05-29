#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;
using namespace cocos2d;

// ─────────────────────────────────────────
//  Global flags
// ─────────────────────────────────────────
namespace {
    bool g_noclip    = false;
    bool g_autoPlay  = false;
    bool g_menuOpen  = false;
    bool g_showLines = true;   // trajectory çizgilerini göster/gizle

    // Çizgi node'larını tutmak için (her frame sil-yeniden çiz)
    CCNode* g_lineNode = nullptr;
}

// ─────────────────────────────────────────
//  Bildirim yardımcısı
// ─────────────────────────────────────────
void toast(const char* txt) {
    Notification::create(txt, NotificationIcon::Info)->show();
}

// ─────────────────────────────────────────
//  Trajectory (yörünge) simülasyon ayarları
// ─────────────────────────────────────────
static constexpr int   SIM_STEPS      = 40;    // kaç frame ileri bak
static constexpr float SIM_DT         = 1.f / 60.f;
static constexpr float GRAVITY        = -0.958f; // GD'nin yaklaşık yerçekimi katsayısı (velocity/frame)
static constexpr float JUMP_VELOCITY  = 11.5f;   // cube zıplama hızı (yaklaşık)
static constexpr float SHIP_ACCEL     = 0.6f;    // ship yukarı ivme
static constexpr float SHIP_GRAVITY   = -0.4f;   // ship aşağı çekim
static constexpr float WAVE_SPEED     = 5.5f;    // wave dikey hız

// ─────────────────────────────────────────
//  Tek adım fizik simülasyonu
//  pressing = o adımda butona basılı mı?
// ─────────────────────────────────────────
struct SimState {
    float y  = 0.f;
    float vy = 0.f; // dikey hız
};

SimState simStep(const SimState& s, bool pressing, PlayerObject* player) {
    SimState next = s;

    if (player->m_isShip) {
        // Ship: basılıysa yukarı ivme, değilse yerçekimi
        if (pressing) next.vy += SHIP_ACCEL;
        else          next.vy += SHIP_GRAVITY;
        next.vy = std::clamp(next.vy, -8.f, 8.f);
        next.y  += next.vy;
    }
    else if (player->m_isDart) {
        // Wave: basılıysa yukarı sabit hız, değilse aşağı
        next.vy = pressing ? WAVE_SPEED : -WAVE_SPEED;
        next.y  += next.vy;
    }
    else {
        // Cube / Robot / Spider vb.
        // Zıplama: yerdeyse ve pressing ise anlık hız ver
        if (pressing && s.vy <= 0.f && s.y <= player->getPositionY() + 1.f) {
            next.vy = JUMP_VELOCITY;
        }
        next.vy += GRAVITY;
        next.y  += next.vy;
        // Yere çakılma engeli (basit zemin limiti)
        if (next.y < player->getPositionY() && next.vy < 0.f) {
            next.y  = player->getPositionY();
            next.vy = 0.f;
        }
    }

    return next;
}

// ─────────────────────────────────────────
//  Yörünge çizgisi — CCDrawNode kullanır
// ─────────────────────────────────────────
void drawTrajectory(
    CCNode*          parent,
    PlayerObject*    player,
    bool             pressingPath,     // bu yörüngede buton basılı mı?
    const ccColor4F& color
) {
    if (!player || !parent) return;

    auto draw = CCDrawNode::create();
    parent->addChild(draw);

    SimState state;
    state.y  = player->getPositionY();
    state.vy = player->getYVelocity();

    float x = player->getPositionX();
    // Karakter her frame yaklaşık bu kadar ilerler (GD sabit hız ~9 unit/frame)
    float xSpeed = 9.f;

    CCPoint prev = { x, state.y };

    for (int i = 1; i <= SIM_STEPS; ++i) {
        state = simStep(state, pressingPath, player);
        CCPoint cur = { x + xSpeed * i, state.y };

        draw->drawSegment(prev, cur, 1.5f, color);
        // Küçük nokta
        draw->drawDot(cur, 2.5f, color);

        prev = cur;
    }
}

// ─────────────────────────────────────────
//  Basit çarpışma tahmini:
//  Simüle edilen yörüngede engel var mı?
//  (PlayLayer'ın m_objects listesini tara)
// ─────────────────────────────────────────
bool pathHasObstacle(PlayLayer* pl, PlayerObject* player, bool pressing) {
    if (!pl || !player) return false;

    SimState state;
    state.y  = player->getPositionY();
    state.vy = player->getYVelocity();

    float x      = player->getPositionX();
    float xSpeed = 9.f;

    for (int i = 1; i <= SIM_STEPS; ++i) {
        state = simStep(state, pressing, player);
        float simX = x + xSpeed * i;
        float simY = state.y;

        // Tüm objeleri kontrol et
        auto& objs = pl->m_objects;
        for (int j = 0; j < objs->count(); ++j) {
            auto obj = static_cast<GameObject*>(objs->objectAtIndex(j));
            if (!obj || !obj->isVisible()) continue;

            // Çarpışma alanı (basit AABB)
            float ox = obj->getPositionX();
            float oy = obj->getPositionY();

            if (
                std::abs(simX - ox) < 18.f &&
                std::abs(simY - oy) < 18.f
            ) {
                return true; // engel var
            }
        }
    }

    return false;
}

// ─────────────────────────────────────────
//  AutoPlay ana mantığı (her frame çağrılır)
// ─────────────────────────────────────────
void runAutoPlay(PlayLayer* pl) {
    if (!g_autoPlay || !pl) return;

    auto player = pl->m_player1;
    if (!player) return;

    // ── Çizgileri temizle ──
    if (g_lineNode) {
        g_lineNode->removeAllChildren();
    }

    // ── Yörünge çizgilerini çiz ──
    if (g_showLines && g_lineNode) {
        // Kırmızı = zıplamama yolu
        drawTrajectory(
            g_lineNode, player,
            false,
            { 1.f, 0.2f, 0.2f, 0.7f }
        );
        // Yeşil = zıplama yolu
        drawTrajectory(
            g_lineNode, player,
            true,
            { 0.2f, 1.f, 0.2f, 0.7f }
        );
    }

    // ── Ship modu ──
    if (player->m_isShip) {
        if (player->getPositionY() < 120.f)
            player->pushButton(PlayerButton::Jump);
        else
            player->releaseButton(PlayerButton::Jump);
        return;
    }

    // ── Wave modu ──
    if (player->m_isDart) {
        if (player->getYVelocity() < -2.f)
            player->pushButton(PlayerButton::Jump);
        else
            player->releaseButton(PlayerButton::Jump);
        return;
    }

    // ── Cube / Robot vb. — Yörünge seçimi ──
    bool jumpDangerous  = pathHasObstacle(pl, player, true);   // zıplarsak tehlike var mı?
    bool stayDangerous  = pathHasObstacle(pl, player, false);  // zıplamazsak tehlike var mı?

    if (!stayDangerous) {
        // Yerde kalmak güvenli → buton bırak
        player->releaseButton(PlayerButton::Jump);
    } else if (!jumpDangerous) {
        // Zıplamak güvenli → zıpla
        if (player->m_isOnGround && player->getYVelocity() <= 0.f)
            player->pushButton(PlayerButton::Jump);
        else
            player->releaseButton(PlayerButton::Jump);
    } else {
        // Her iki yol da tehlikeli → en azından zıplamayı dene (default)
        if (player->m_isOnGround && player->getYVelocity() <= 0.f)
            player->pushButton(PlayerButton::Jump);
        else
            player->releaseButton(PlayerButton::Jump);
    }
}

// ─────────────────────────────────────────
//  EmirMenu — oyun içi overlay menü
// ─────────────────────────────────────────
class EmirMenu : public CCLayer {
public:
    CCMenu*      m_menu = nullptr;
    CCLayerColor* m_bg  = nullptr;

    static EmirMenu* create() {
        auto ret = new EmirMenu();
        if (ret && ret->init()) { ret->autorelease(); return ret; }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) return false;

        auto win = CCDirector::sharedDirector()->getWinSize();
        this->setTouchEnabled(false);

        // Arka plan kutusu
        m_bg = CCLayerColor::create({ 0, 0, 0, 140 }, 270.f, 260.f);
        m_bg->setPosition({ win.width / 2 - 135.f, win.height / 2 - 130.f });
        m_bg->setVisible(false);
        this->addChild(m_bg, 100);

        m_menu = CCMenu::create();
        m_menu->setPosition(0, 0);
        this->addChild(m_menu, 101);

        // ── Aç butonu (sol tarafta sabit) ──
        auto openBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("EH", 80, true, "goldFont.fnt", "GJ_button_04.png", 30.f, 1.f),
            this, menu_selector(EmirMenu::onOpen)
        );
        openBtn->setPosition({ 60.f, win.height / 2 });
        m_menu->addChild(openBtn);

        // ── Noclip ──
        auto noclipBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Noclip", 120, true, "goldFont.fnt", "GJ_button_01.png", 25.f, 0.8f),
            this, menu_selector(EmirMenu::onNoclip)
        );
        noclipBtn->setPosition({ win.width / 2, win.height / 2 + 75.f });
        noclipBtn->setTag(1000);
        noclipBtn->setVisible(false);
        m_menu->addChild(noclipBtn);

        // ── AutoPlay ──
        auto autoBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Auto Play", 120, true, "goldFont.fnt", "GJ_button_05.png", 25.f, 0.8f),
            this, menu_selector(EmirMenu::onAutoPlay)
        );
        autoBtn->setPosition({ win.width / 2, win.height / 2 + 25.f });
        autoBtn->setTag(1001);
        autoBtn->setVisible(false);
        m_menu->addChild(autoBtn);

        // ── Çizgileri Göster/Gizle ──
        auto linesBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Show Lines", 120, true, "goldFont.fnt", "GJ_button_03.png", 25.f, 0.8f),
            this, menu_selector(EmirMenu::onToggleLines)
        );
        linesBtn->setPosition({ win.width / 2, win.height / 2 - 25.f });
        linesBtn->setTag(1003);
        linesBtn->setVisible(false);
        m_menu->addChild(linesBtn);

        // ── Kapat ──
        auto closeBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Close", 120, true, "goldFont.fnt", "GJ_button_06.png", 25.f, 0.8f),
            this, menu_selector(EmirMenu::onOpen)
        );
        closeBtn->setPosition({ win.width / 2, win.height / 2 - 75.f });
        closeBtn->setTag(1002);
        closeBtn->setVisible(false);
        m_menu->addChild(closeBtn);

        return true;
    }

    void updateGUI() {
        int tags[] = { 1000, 1001, 1002, 1003 };
        for (int t : tags) {
            if (auto node = m_menu->getChildByTag(t))
                node->setVisible(g_menuOpen);
        }
        if (m_bg) m_bg->setVisible(g_menuOpen);
    }

    void onOpen(CCObject*)         { g_menuOpen = !g_menuOpen; updateGUI(); }

    void onNoclip(CCObject*) {
        g_noclip = !g_noclip;
        toast(g_noclip ? "Noclip Enabled" : "Noclip Disabled");
    }

    void onAutoPlay(CCObject*) {
        g_autoPlay = !g_autoPlay;
        toast(g_autoPlay ? "AutoPlay Enabled" : "AutoPlay Disabled");

        // AutoPlay kapanınca buton bırak
        if (!g_autoPlay) {
            // PlayLayer'a erişmek için parent zinciri
            auto scene = CCDirector::sharedDirector()->getRunningScene();
            if (auto pl = scene->getChildByType<PlayLayer>(0)) {
                if (auto p = pl->m_player1)
                    p->releaseButton(PlayerButton::Jump);
            }
        }
    }

    void onToggleLines(CCObject*) {
        g_showLines = !g_showLines;

        // Buton etiketini güncelle
        if (auto node = m_menu->getChildByTag(1003)) {
            if (auto btn = dynamic_cast<CCMenuItemSpriteExtra*>(node)) {
                // ButtonSprite'ın label'ını bulmak için çocukları dolaş
                // Basit yol: toast ile bildir
            }
        }
        toast(g_showLines ? "Lines Shown" : "Lines Hidden");

        if (!g_showLines && g_lineNode)
            g_lineNode->removeAllChildren();
    }
};

// ─────────────────────────────────────────
//  PlayLayer hook
// ─────────────────────────────────────────
class $modify(MyPlayLayer, PlayLayer) {

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        // Menü ekle
        auto menu = EmirMenu::create();
        this->addChild(menu, 99999);

        // Çizgi node'u oluştur — PlayLayer'ın dünya koordinatlarında yaşar
        g_lineNode = CCNode::create();
        this->addChild(g_lineNode, 99998);

        toast("Emir Hub Loaded");
        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);
        runAutoPlay(this);
    }

    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        if (g_noclip) return;
        PlayLayer::destroyPlayer(player, obj);
    }

    void onExit() {
        // Sahne bitince g_lineNode'u sıfırla (dangling pointer olmasın)
        g_lineNode = nullptr;
        PlayLayer::onExit();
    }
};

$on_mod(Loaded) {
    log::info("Emir Hub Loaded");
}
