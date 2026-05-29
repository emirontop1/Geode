#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;
using namespace cocos2d;

// ─────────────────────────────────────────
//  Global State
// ─────────────────────────────────────────

namespace {
    bool g_noclip    = false;
    bool g_autoPlay  = false;
    bool g_menuOpen  = false;

    // Trajectory preview overlay pointer
    // (PlayLayer'a her girişte yeniden oluşturulur)
    CCDrawNode* g_trajectoryNode = nullptr;
}

// ─────────────────────────────────────────
//  Yardımcı: Toast Bildirimi
// ─────────────────────────────────────────

void toast(const char* txt) {
    Notification::create(txt, NotificationIcon::Info)->show();
}

// ─────────────────────────────────────────
//  Yörünge Simülasyonu
//
//  GD fizik sabitleri (yaklaşık, normal hızda):
//    GRAVITY  ≈ -0.958  (kare başına uyg. ivme, dt=1/60)
//    JUMP_VY  ≈  11.180 (pushButton anında dikey hız)
//    FALL_VY  ≈ -28.0   (terminal hız tavanı)
//
//  simulate() → adım adım euler entegrasyonu ile
//  tahmini pozisyonları döndürür.
// ─────────────────────────────────────────

namespace Physics {
    constexpr float GRAVITY   = -0.958f;
    constexpr float JUMP_VY   =  11.18f;
    constexpr float TERMINAL  = -28.0f;
    constexpr int   STEPS     =  120;    // ~2 saniyelik tahmin (60fps)
    constexpr float DT        =  1.0f;   // "1 frame" birimi

    struct State {
        float x, y, vx, vy;
    };

    // Tek adım euler
    State step(State s, bool holding) {
        float ay = GRAVITY;
        if (holding && s.vy < 0.f) ay *= 0.5f; // basılı tutunca düşüş yavaşlar

        s.vy += ay * DT;
        if (s.vy < TERMINAL) s.vy = TERMINAL;

        s.x += s.vx * DT;
        s.y += s.vy * DT;

        return s;
    }

    // STEPS kadar simüle et, her noktayı kaydet
    std::vector<CCPoint> simulate(
        float startX, float startY,
        float vx, float vy,
        bool holding
    ) {
        std::vector<CCPoint> pts;
        pts.reserve(STEPS);

        State s { startX, startY, vx, vy };

        for (int i = 0; i < STEPS; ++i) {
            s = step(s, holding);
            pts.push_back({ s.x, s.y });

            // Zemin altına düştüyse dur
            if (s.y < -100.f) break;
        }

        return pts;
    }
}

// ─────────────────────────────────────────
//  Yörünge Çizici
//
//  İki set nokta:
//    jumpPts  → şu an zıplarsa (sarı)
//    fallPts  → zıplamazsa / mevcut yörünge (kırmızı)
//  Her setin sonuna ok başlığı eklenir.
// ─────────────────────────────────────────

void drawArrow(CCDrawNode* node, const std::vector<CCPoint>& pts,
               ccColor4F color, float lineWidth = 2.f)
{
    if (pts.size() < 2) return;

    // Çizgi segmentleri
    for (size_t i = 0; i + 1 < pts.size(); ++i) {
        node->drawSegment(pts[i], pts[i + 1], lineWidth, color);
    }

    // Ok başlığı (son 2 nokta üzerinden açı hesabı)
    CCPoint tip  = pts.back();
    CCPoint prev = pts[pts.size() - 2];

    float angle = ccpToAngle(ccpSub(tip, prev));

    float headLen  = 14.f;
    float headAngle = 0.45f; // radyan (~26°)

    CCPoint left = ccpAdd(tip, CCPoint(
        -headLen * cosf(angle - headAngle),
        -headLen * sinf(angle - headAngle)
    ));
    CCPoint right = ccpAdd(tip, CCPoint(
        -headLen * cosf(angle + headAngle),
        -headLen * sinf(angle + headAngle)
    ));

    node->drawSegment(tip, left,  lineWidth + 1.f, color);
    node->drawSegment(tip, right, lineWidth + 1.f, color);
}

void updateTrajectory(PlayLayer* pl) {
    if (!g_trajectoryNode) return;
    if (!pl) return;

    auto player = pl->m_player1;
    if (!player) return;

    g_trajectoryNode->clear();

    float px = player->getPositionX();
    float py = player->getPositionY();
    float vx = player->m_playerSpeed * 5.7f; // yaklaşık yatay hız
    float vy = player->getYVelocity();

    // ---- Sarı: Zıplarsa ----
    // Ship/wave için farklı jump vy
    float jumpVY = Physics::JUMP_VY;
    if (player->m_isShip)  jumpVY =  8.0f;
    if (player->m_isDart)  jumpVY =  6.0f;
    if (player->m_isBall)  jumpVY =  9.5f;
    if (player->m_isUfo)   jumpVY =  7.5f;
    if (player->m_isRobot) jumpVY = 11.0f;
    if (player->m_isSpider) jumpVY = 10.0f;

    auto jumpPts = Physics::simulate(px, py, vx, jumpVY, true);
    auto fallPts = Physics::simulate(px, py, vx, vy,     false);

    // Sarı ok: "zıplarsan buraya gidersin"
    ccColor4F yellow = { 1.f, 0.95f, 0.2f, 0.85f };
    drawArrow(g_trajectoryNode, jumpPts, yellow, 2.0f);

    // Kırmızı ok: "zıplamazsan / şu anki yörüngede"
    ccColor4F red = { 1.f, 0.25f, 0.25f, 0.85f };
    drawArrow(g_trajectoryNode, fallPts, red, 2.0f);
}

// ─────────────────────────────────────────
//  İleriyi Gören AutoPlay
//
//  Strateji:
//  1. Önündeki ~200 px'e (yaklaşık 35 frame) bak.
//  2. Mevcut yörüngede engel/boşluk var mı simüle et.
//  3. Zıplayınca daha iyi pozisyonda mı olur?
//  4. Ship/Wave: Y konumuna göre irtifa kontrolü.
//  5. Cube/Robot/Spider: zemin tespiti + öngörü.
// ─────────────────────────────────────────

namespace AutoPlay {

    // Simülasyondan gelen noktaların ortalama Y'sini döndür
    // (yüksekliği karşılaştırmak için kullanılır)
    float avgY(const std::vector<CCPoint>& pts, int count = 20) {
        if (pts.empty()) return 0.f;
        float sum = 0.f;
        int   n   = std::min((int)pts.size(), count);
        for (int i = 0; i < n; ++i) sum += pts[i].y;
        return sum / n;
    }

    // Oyuncu önündeki yakın alandaki ortalama zemin yüksekliğini
    // PlayLayer'dan çekmeye çalışır (basit yaklaşım: raycast yok,
    // oyuncunun Y'sini referans alır)
    // GD'nin collision sistemi kapalı olduğundan simülasyon
    // puanlama üzerinden karar verilir.

    void run(PlayLayer* pl) {
        if (!g_autoPlay) return;
        if (!pl) return;

        auto player = pl->m_player1;
        if (!player) return;

        float px = player->getPositionX();
        float py = player->getPositionY();
        float vx = player->m_playerSpeed * 5.7f;
        float vy = player->getYVelocity();

        // ── Ship: yüksekliği orta bölgede tut ──
        if (player->m_isShip) {
            float target = 165.f; // ekranın ortası civarı
            if (py < target - 15.f)
                player->pushButton(PlayerButton::Jump);
            else
                player->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Wave: ani hız değişimlerine tepki ver ──
        if (player->m_isDart) {
            if (vy < -3.f)
                player->pushButton(PlayerButton::Jump);
            else if (vy > 3.f)
                player->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── UFO: sallantıyı azalt, orta bölge ──
        if (player->m_isUfo) {
            float target = 160.f;
            if (py < target)
                player->pushButton(PlayerButton::Jump);
            else
                player->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Ball: yere değince zıpla ──
        if (player->m_isBall) {
            if (player->m_isOnGround && vy <= 0.f)
                player->pushButton(PlayerButton::Jump);
            else
                player->releaseButton(PlayerButton::Jump);
            return;
        }

        // ── Cube / Robot / Spider: öngörülü zıplama ──
        // Mevcut yörünge ile zıplama yörüngesini karşılaştır.
        // 30 frame (0.5sn) sonraki ortalama Y'ye bak.
        // Zıpladığımızda daha yüksekte miyiz? Zıpla.
        // Ama çok yüksekte uçmayalım (üst sınır kontrolü).

        auto fallPts = Physics::simulate(px, py, vx, vy, false);
        auto jumpPts = Physics::simulate(px, py, vx, Physics::JUMP_VY, true);

        float fallAvg = avgY(fallPts, 30);
        float jumpAvg = avgY(jumpPts, 30);

        // Çok alçaksa kesinlikle zıpla
        bool tooLow    = py < 85.f;
        // Çok yüksekse zıplama
        bool tooHigh   = py > 270.f;
        // Düşüyor ve zemine yakın
        bool fallingLow = (vy < -3.f && py < 130.f);

        if (tooHigh) {
            player->releaseButton(PlayerButton::Jump);
            return;
        }

        if (tooLow || fallingLow) {
            player->pushButton(PlayerButton::Jump);
            return;
        }

        // Genel öngörü kararı
        if (
            player->m_isOnGround &&
            vy <= 0.f &&
            jumpAvg > fallAvg + 5.f
        ) {
            player->pushButton(PlayerButton::Jump);
        }
        else {
            player->releaseButton(PlayerButton::Jump);
        }
    }
}

// ─────────────────────────────────────────
//  Emir Menü (UI Katmanı)
// ─────────────────────────────────────────

class EmirMenu : public CCLayer {
public:
    CCMenu*       m_menu = nullptr;
    CCLayerColor* m_bg   = nullptr;

    static EmirMenu* create() {
        auto ret = new EmirMenu();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) return false;

        auto win = CCDirector::sharedDirector()->getWinSize();

        this->setTouchEnabled(false);

        // ── Arkaplan ──
        m_bg = CCLayerColor::create({ 0, 0, 0, 140 }, 280.f, 240.f);
        m_bg->setPosition({
            win.width / 2 - 140.f,
            win.height / 2 - 120.f
        });
        m_bg->setVisible(false);
        this->addChild(m_bg, 100);

        m_menu = CCMenu::create();
        m_menu->setPosition(0, 0);
        this->addChild(m_menu, 101);

        // ── Aç/Kapat Düğmesi (her zaman görünür) ──
        auto openBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("EH", 80, true,
                "goldFont.fnt", "GJ_button_04.png", 30.f, 1.f),
            this,
            menu_selector(EmirMenu::onOpen)
        );
        openBtn->setPosition({ 60.f, win.height / 2 });
        m_menu->addChild(openBtn);

        // ── Noclip ──
        buildBtn("Noclip",    "GJ_button_01.png", 1000,
                 win.width / 2, win.height / 2 + 75.f,
                 menu_selector(EmirMenu::onNoclip));

        // ── AutoPlay ──
        buildBtn("Auto Play", "GJ_button_05.png", 1001,
                 win.width / 2, win.height / 2 + 25.f,
                 menu_selector(EmirMenu::onAutoPlay));

        // ── Trajectory ──
        buildBtn("Trajectory","GJ_button_02.png", 1002,
                 win.width / 2, win.height / 2 - 25.f,
                 menu_selector(EmirMenu::onTrajectory));

        // ── Kapat ──
        buildBtn("Close",     "GJ_button_06.png", 1003,
                 win.width / 2, win.height / 2 - 75.f,
                 menu_selector(EmirMenu::onOpen));

        // Başlangıçta menü kapalı
        setMenuVisible(false);
        return true;
    }

    // ---- Yardımcı: Düğme Oluştur ----
    void buildBtn(const char* text, const char* sprite, int tag,
                  float x, float y, SEL_MenuHandler sel)
    {
        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(text, 130, true,
                "goldFont.fnt", sprite, 25.f, 0.8f),
            this, sel
        );
        btn->setPosition({ x, y });
        btn->setTag(tag);
        m_menu->addChild(btn);
    }

    void setMenuVisible(bool v) {
        for (int tag = 1000; tag <= 1003; ++tag) {
            auto child = m_menu->getChildByTag(tag);
            if (child) child->setVisible(v);
        }
        if (m_bg) m_bg->setVisible(v);
    }

    void updateButtonLabels() {
        // Noclip rengi
        auto noclipNode = m_menu->getChildByTag(1000);
        if (noclipNode) {
            noclipNode->setColor(
                g_noclip ? ccColor3B{80,255,80} : ccColor3B{255,255,255}
            );
        }
        // AutoPlay rengi
        auto autoNode = m_menu->getChildByTag(1001);
        if (autoNode) {
            autoNode->setColor(
                g_autoPlay ? ccColor3B{80,255,80} : ccColor3B{255,255,255}
            );
        }
    }

    // ── Callback'ler ──

    void onOpen(CCObject*) {
        g_menuOpen = !g_menuOpen;
        setMenuVisible(g_menuOpen);
        updateButtonLabels();
    }

    void onNoclip(CCObject*) {
        g_noclip = !g_noclip;
        updateButtonLabels();
        toast(g_noclip ? "Noclip Enabled" : "Noclip Disabled");
    }

    void onAutoPlay(CCObject*) {
        g_autoPlay = !g_autoPlay;
        updateButtonLabels();
        toast(g_autoPlay ? "AutoPlay Enabled" : "AutoPlay Disabled");
    }

    // Trajectory toggle: g_trajectoryNode'u göster/gizle
    void onTrajectory(CCObject*) {
        if (g_trajectoryNode) {
            bool vis = !g_trajectoryNode->isVisible();
            g_trajectoryNode->setVisible(vis);
            toast(vis ? "Trajectory Enabled" : "Trajectory Disabled");
        }
    }
};

// ─────────────────────────────────────────
//  PlayLayer Hook
// ─────────────────────────────────────────

class $modify(MyPlayLayer, PlayLayer) {

    // ── Init ──
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        // ---- Trajectory Overlay ----
        g_trajectoryNode = CCDrawNode::create();
        g_trajectoryNode->setZOrder(9998);
        // Başlangıçta görünür (toggle ile kapatılabilir)
        g_trajectoryNode->setVisible(true);
        this->addChild(g_trajectoryNode);

        // ---- Emir Menü ----
        auto menu = EmirMenu::create();
        this->addChild(menu, 99999);

        toast("Emir Hub Loaded");
        return true;
    }

    // ── Her Frame ──
    void update(float dt) {
        PlayLayer::update(dt);

        // AutoPlay
        AutoPlay::run(this);

        // Trajectory güncelle (sadece görünürse hesapla)
        if (g_trajectoryNode && g_trajectoryNode->isVisible()) {
            updateTrajectory(this);
        }
    }

    // ── Oyuncu Ölümü (Noclip) ──
    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        if (g_noclip) return;
        PlayLayer::destroyPlayer(player, obj);
    }

    // ── Level Resetlendi veya Bitirildi ──
    // Trajectory node referansını temizle
    void resetLevel() {
        PlayLayer::resetLevel();
        // resetLevel sonrası node hâlâ aynı sahnede yaşıyor,
        // sadece içeriğini temizle
        if (g_trajectoryNode) {
            g_trajectoryNode->clear();
        }
    }
};

// ─────────────────────────────────────────
//  Mod Yüklendiğinde
// ─────────────────────────────────────────

$on_mod(Loaded) {
    log::info("Emir Hub Loaded — AutoPlay + Trajectory Edition");
}
