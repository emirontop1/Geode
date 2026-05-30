/**
 * emir_hub.cpp
 * Geode Mod — EmiR Hub
 *
 * GeodeMenu stilinde sürüklenebilir mod menüsü + trajectory sistemi.
 * Tab tuşu (PC) veya ekran butonu ile açılır/kapanır.
 */

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;
using namespace cocos2d;

/* ════════════════════════════════════════════
   Sabitler
   ════════════════════════════════════════════ */
static constexpr int   SIM_STEPS       = 120;
static constexpr float SIM_DT          = 1.0f / 60.0f;
static constexpr float GRAVITY         = -900.0f;
static constexpr float SHIP_ACCEL_UP   = 700.0f;
static constexpr float PLAYER_HW       = 30.0f;
static constexpr float PLAYER_HH       = 30.0f;
static constexpr float TRAJ_RADIUS     = 3.5f;
static constexpr float DOT_OPACITY_MAX = 200.0f;

// Menü boyutları (GeodeMenu'ya benzer)
static constexpr float MENU_W          = 340.0f;
static constexpr float MENU_H          = 240.0f;
static constexpr float TOGGLE_W        = 140.0f;
static constexpr float TOGGLE_H        = 30.0f;
static constexpr float HEADER_H        = 28.0f;

// Menü renkleri (koyu mor / GeodeMenu paleti)
static const ccColor4B  BG_COLOR       = {20,  20,  35,  220};
static const ccColor4B  HEADER_COLOR   = {40,  30,  80,  255};
static const ccColor3B  TITLE_COLOR    = {200, 180, 255};
static const ccColor3B  ON_COLOR       = {80,  220, 120};
static const ccColor3B  OFF_COLOR      = {200,  60,  60};
static const ccColor3B  DOT_COLOR      = {255, 220,  50};

/* ════════════════════════════════════════════
   Ayar anahtarları
   ════════════════════════════════════════════ */
static const std::string S_ENABLED    = "trajectory_enabled";
static const std::string S_DOT_COUNT  = "dot_count";
static const std::string S_SHOW_MODE  = "show_mode_label";

/* ════════════════════════════════════════════
   Yardımcılar
   ════════════════════════════════════════════ */
static std::string modeName(PlayerCheckpoint* cp) {
    if (!cp)            return "Cube";
    if (cp->m_isShip)   return "Ship";
    if (cp->m_isBall)   return "Ball";
    if (cp->m_isBird)   return "UFO";
    if (cp->m_isDart)   return "Wave";
    if (cp->m_isRobot)  return "Robot";
    if (cp->m_isSpider) return "Spider";
    if (cp->m_isSwing)  return "Swing";
    return "Cube";
}

static bool isSolidObject(GameObject* obj) {
    if (!obj)                    return false;
    if (obj->m_isDisabled)       return false;
    if (obj->m_isTrigger)        return false;
    if (obj->m_isInvisibleBlock) return false;
    if (obj->m_isPassable)       return false;
    if (obj->m_isDecoration)     return false;
    if (obj->m_isDecoration2)    return false;
    return true;
}

static bool collidesWithSolid(GJBaseGameLayer* gbl, CCPoint pos) {
    if (!gbl) return false;
    CCRect hitbox{pos.x - PLAYER_HW * .5f, pos.y - PLAYER_HH * .5f, PLAYER_HW, PLAYER_HH};
    auto* arr = gbl->staticObjectsInRect(hitbox, true);
    if (!arr) return false;
    for (int i = 0; i < (int)arr->count(); i++) {
        auto* obj = static_cast<GameObject*>(arr->objectAtIndex(i));
        if (isSolidObject(obj) && hitbox.intersectsRect(obj->boundingBox()))
            return true;
    }
    return false;
}

static std::vector<CCPoint> computeTrajectory(
    PlayLayer* pl, PlayerCheckpoint* cp, PlayerObject* player, LevelSettingsObject* settings)
{
    std::vector<CCPoint> pts;
    if (!pl || !cp || !player) return pts;

    auto* gbl = static_cast<GJBaseGameLayer*>(pl);

    float px = player->getPositionX();
    float py = player->getPositionY();
    float vx = player->getCurrentXVelocity();
    float vy = 0.f;
    float grav     = cp->m_gravityMod > 0.f ? cp->m_gravityMod : 1.f;
    float gravDir  = cp->m_isUpsideDown ? 1.f : -1.f;
    bool  isPlatformer = settings ? settings->m_platformerMode : false;

    bool isShip   = cp->m_isShip;
    bool isBall   = cp->m_isBall;
    bool isBird   = cp->m_isBird;
    bool isWave   = cp->m_isDart;
    bool isRobot  = cp->m_isRobot;
    bool isSpider = cp->m_isSpider;
    bool isSwing  = cp->m_isSwing;
    bool isCube   = !isShip && !isBall && !isBird && !isWave && !isRobot && !isSpider && !isSwing;

    if      (isCube || isRobot) { vy = 550.f * grav; if (cp->m_isMini) vy *= .75f; }
    else if (isBall)            { vy = 300.f * grav; }
    else if (isBird)            { vy = 350.f * grav; }
    else if (isShip || isSwing) { vy = 200.f * grav; }
    else if (isSpider)          { vy = 450.f * grav; }

    if (isPlatformer && vx == 0.f) vx = 200.f;

    int dotCount = (int)Mod::get()->getSettingValue<int64_t>(S_DOT_COUNT);
    if (dotCount <= 0 || dotCount > SIM_STEPS) dotCount = SIM_STEPS;

    for (int step = 0; step < dotCount; step++) {
        if (isWave) {
            float ang = CC_DEGREES_TO_RADIANS(cp->m_isUpsideDown ? 45.f : -45.f);
            float spd = std::abs(vx) > 0.f ? std::abs(vx) : 300.f;
            px += std::cos(ang) * spd * SIM_DT;
            py += std::sin(ang) * spd * SIM_DT;
        } else if (isShip) {
            vy += SHIP_ACCEL_UP * grav * gravDir * SIM_DT;
            vy  = std::clamp(vy, -700.f, 700.f);
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else if (isSwing) {
            vy += SHIP_ACCEL_UP * .9f * grav * gravDir * SIM_DT;
            vy  = std::clamp(vy, -650.f, 650.f);
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else if (isBall) {
            vy += GRAVITY * grav * (-gravDir) * SIM_DT;
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else {
            vy += GRAVITY * grav * gravDir * SIM_DT;
            px += vx * SIM_DT; py += vy * SIM_DT;
        }

        CCPoint sim = ccp(px, py);
        if (collidesWithSolid(gbl, sim)) { pts.push_back(sim); break; }
        pts.push_back(sim);
    }
    return pts;
}

/* ════════════════════════════════════════════
   TrajectoryNode  (CCNode, kendi draw())
   ════════════════════════════════════════════ */
class TrajectoryNode : public CCNode {
public:
    std::vector<CCPoint> m_points;
    CCLabelBMFont*       m_label = nullptr;

    static TrajectoryNode* create() {
        auto* n = new TrajectoryNode();
        if (n && n->init()) { n->autorelease(); return n; }
        CC_SAFE_DELETE(n); return nullptr;
    }

    bool init() override {
        if (!CCNode::init()) return false;
        m_label = CCLabelBMFont::create("", "bigFont.fnt");
        m_label->setScale(.40f);
        m_label->setColor(DOT_COLOR);
        m_label->setOpacity(200);
        addChild(m_label, 2);
        return true;
    }

    void setPoints(const std::vector<CCPoint>& pts, const std::string& mode) {
        m_points = pts;
        bool show = Mod::get()->getSettingValue<bool>(S_SHOW_MODE);
        if (m_label && !pts.empty() && show) {
            m_label->setString(("[ " + mode + " ]").c_str());
            m_label->setPosition(ccp(pts.front().x, pts.front().y + 22.f));
            m_label->setVisible(true);
        } else if (m_label) {
            m_label->setVisible(false);
        }
        setVisible(!pts.empty());
    }

    void draw() override {
        CCNode::draw();
        int n = (int)m_points.size();
        for (int i = 0; i < n; i++) {
            float a = 1.f - ((float)i / (float)n) * .85f;
            ccDrawColor4B(DOT_COLOR.r, DOT_COLOR.g, DOT_COLOR.b, (GLubyte)(DOT_OPACITY_MAX * a));
            ccDrawCircle(m_points[i], TRAJ_RADIUS, 0, 12, false);
        }
    }
};

/* ════════════════════════════════════════════
   EHMenuLayer  — GeodeMenu stilinde sürüklenebilir panel
   ════════════════════════════════════════════ */
class EHMenuLayer : public CCLayer {
public:
    /* ── iç state ── */
    CCLayerColor*  m_bg        = nullptr;   // ana panel arkaplanı
    CCLayerColor*  m_header    = nullptr;   // başlık bandı
    CCLabelBMFont* m_title     = nullptr;
    CCMenu*        m_closeMenu = nullptr;

    // Toggle buton çiftleri (ON / OFF sprite + label)
    struct ToggleRow {
        std::string  key;
        std::string  label;
        CCLabelBMFont* nameLabel  = nullptr;
        CCLabelBMFont* stateLabel = nullptr;
        CCMenuItemSpriteExtra* btn = nullptr;
    };
    std::vector<ToggleRow> m_rows;

    // Sürükleme
    bool   m_dragging     = false;
    CCPoint m_dragOffset  = CCPointZero;

    /* ── Singleton benzeri erişim ── */
    static EHMenuLayer* s_instance;

    static EHMenuLayer* create() {
        auto* l = new EHMenuLayer();
        if (l && l->init()) { l->autorelease(); return l; }
        CC_SAFE_DELETE(l); return nullptr;
    }

    /* ── Toggle show/hide ── */
    static void toggle() {
        auto* scene = CCDirector::get()->getRunningScene();
        if (!scene) return;

        // Zaten açıksa kapat
        if (s_instance) {
            s_instance->removeFromParent();
            s_instance = nullptr;
            return;
        }

        auto* menu = EHMenuLayer::create();
        if (!menu) return;

        CCSize ws = CCDirector::get()->getWinSize();
        menu->setPosition(ccp(ws.width * .5f - MENU_W * .5f,
                               ws.height * .5f - MENU_H * .5f));
        scene->addChild(menu, 9999);
        s_instance = menu;
    }

    bool init() override {
        if (!CCLayer::init()) return false;

        setContentSize({MENU_W, MENU_H});

        // ── Arkaplan ──
        m_bg = CCLayerColor::create(BG_COLOR, MENU_W, MENU_H);
        m_bg->setPosition(CCPointZero);
        addChild(m_bg, 0);

        // ── Başlık bandı ──
        m_header = CCLayerColor::create(HEADER_COLOR, MENU_W, HEADER_H);
        m_header->setPosition(ccp(0, MENU_H - HEADER_H));
        addChild(m_header, 1);

        // ── Başlık yazısı ──
        m_title = CCLabelBMFont::create("EmiR Hub", "goldFont.fnt");
        m_title->setScale(.55f);
        m_title->setColor(TITLE_COLOR);
        m_title->setPosition(ccp(MENU_W * .5f, MENU_H - HEADER_H * .5f));
        addChild(m_title, 2);

        // ── Kapat butonu (sağ üst) ──
        auto* closeSpr = ButtonSprite::create("X", "bigFont.fnt", "GJ_button_06.png", .5f);
        auto* closeBtn = CCMenuItemSpriteExtra::create(
            closeSpr, this, menu_selector(EHMenuLayer::onClose));
        m_closeMenu = CCMenu::create(closeBtn, nullptr);
        m_closeMenu->setPosition(ccp(MENU_W - 18.f, MENU_H - HEADER_H * .5f));
        addChild(m_closeMenu, 3);

        // ── Toggle satırları ──
        _addToggleRow(0, S_ENABLED,   "Trajectory");
        _addToggleRow(1, S_SHOW_MODE, "Mod Etiketi");

        // ── Dokunma/mouse ──
        setTouchEnabled(true);
        setTouchMode(kCCTouchesOneByOne);

        return true;
    }

    void _addToggleRow(int idx, const std::string& key, const char* label) {
        float y = MENU_H - HEADER_H - 20.f - idx * (TOGGLE_H + 8.f);

        ToggleRow row;
        row.key   = key;
        row.label = label;

        // İsim etiketi
        row.nameLabel = CCLabelBMFont::create(label, "bigFont.fnt");
        row.nameLabel->setScale(.42f);
        row.nameLabel->setColor({220, 220, 255});
        row.nameLabel->setAnchorPoint({0.f, .5f});
        row.nameLabel->setPosition(ccp(12.f, y));
        addChild(row.nameLabel, 2);

        // Durum etiketi (ON / OFF)
        bool cur = Mod::get()->getSettingValue<bool>(key);
        row.stateLabel = CCLabelBMFont::create(cur ? "ON" : "OFF", "bigFont.fnt");
        row.stateLabel->setScale(.40f);
        row.stateLabel->setColor(cur ? ON_COLOR : OFF_COLOR);
        row.stateLabel->setAnchorPoint({1.f, .5f});
        row.stateLabel->setPosition(ccp(MENU_W - 12.f, y));
        addChild(row.stateLabel, 2);

        // Tıklanabilir buton (satırın tamamı üzerinde şeffaf)
        auto* hitSpr = CCScale9Sprite::create("square02_small.png");
        hitSpr->setContentSize({MENU_W - 16.f, TOGGLE_H - 4.f});
        hitSpr->setOpacity(0);

        row.btn = CCMenuItemSpriteExtra::create(
            hitSpr, this, menu_selector(EHMenuLayer::onToggle));
        row.btn->setTag(idx);
        row.btn->setPosition(ccp(MENU_W * .5f - 8.f, y));

        auto* rowMenu = CCMenu::create(row.btn, nullptr);
        rowMenu->setPosition(CCPointZero);
        addChild(rowMenu, 4);

        // Ayırıcı çizgi
        auto* sep = CCLayerColor::create({80, 80, 120, 100}, MENU_W - 20.f, 1.f);
        sep->setPosition(ccp(10.f, y - TOGGLE_H * .5f));
        addChild(sep, 1);

        m_rows.push_back(row);
    }

    void onToggle(CCObject* sender) {
        int idx = sender->getTag();
        if (idx < 0 || idx >= (int)m_rows.size()) return;
        auto& row = m_rows[idx];
        bool cur = Mod::get()->getSettingValue<bool>(row.key);
        bool next = !cur;
        (void)Mod::get()->setSettingValue<bool>(row.key, next);
        row.stateLabel->setString(next ? "ON" : "OFF");
        row.stateLabel->setColor(next ? ON_COLOR : OFF_COLOR);

        // Animasyon: hafif scale pulse
        row.stateLabel->runAction(CCSequence::create(
            CCScaleTo::create(.06f, 1.3f),
            CCScaleTo::create(.06f, 1.0f),
            nullptr));
    }

    void onClose(CCObject*) {
        s_instance = nullptr;
        removeFromParent();
    }

    /* ── Sürükleme (başlık bandına tıklayınca) ── */
    bool ccTouchBegan(CCTouch* touch, CCEvent*) override {
        CCPoint lp = convertTouchToNodeSpace(touch);
        // Başlık bandı içinde mi?
        CCRect headerRect{0, MENU_H - HEADER_H, MENU_W, HEADER_H};
        if (headerRect.containsPoint(lp)) {
            m_dragging   = true;
            m_dragOffset = lp;
            return true;
        }
        // Panel içindeyse yut (arkaya geçmesin)
        CCRect panelRect{0, 0, MENU_W, MENU_H};
        return panelRect.containsPoint(lp);
    }

    void ccTouchMoved(CCTouch* touch, CCEvent*) override {
        if (!m_dragging) return;
        CCPoint wp = touch->getLocation();
        setPosition(wp - m_dragOffset);
    }

    void ccTouchEnded(CCTouch*, CCEvent*) override { m_dragging = false; }
    void ccTouchCancelled(CCTouch* t, CCEvent* e) override { ccTouchEnded(t, e); }

    void registerWithTouchDispatcher() override {
        CCDirector::get()->getTouchDispatcher()->addTargetedDelegate(this, -500, true);
    }
};

EHMenuLayer* EHMenuLayer::s_instance = nullptr;

/* ════════════════════════════════════════════
   PlayLayer hook  — trajectory çizimi
   ════════════════════════════════════════════ */
class $modify(EHPlayLayer, PlayLayer) {
    struct Fields {
        TrajectoryNode* tnode = nullptr;
    };

    void postUpdate(float dt) override {
        PlayLayer::postUpdate(dt);

        if (!Mod::get()->getSettingValue<bool>(S_ENABLED)) {
            if (m_fields->tnode) m_fields->tnode->setVisible(false);
            return;
        }

        _ensureNode();
        _update();
    }

    void resetLevel() override {
        PlayLayer::resetLevel();
        if (m_fields->tnode) m_fields->tnode->setPoints({}, "");
    }

private:
    void _ensureNode() {
        if (m_fields->tnode) return;
        auto* n = TrajectoryNode::create();
        if (!n) return;
        addChild(n, 1000);
        m_fields->tnode = n;
    }

    void _update() {
        auto* node = m_fields->tnode;
        if (!node) return;

        PlayerObject* player = m_player1;
        if (!player) { node->setPoints({}, ""); return; }

        auto* cp = PlayerCheckpoint::create();
        if (!cp)  { node->setPoints({}, ""); return; }
        player->saveToCheckpoint(cp);

        auto pts = computeTrajectory(this, cp, player, m_levelSettings);
        node->setPosition(CCPointZero);
        node->setPoints(pts, modeName(cp));
    }
};

/* ════════════════════════════════════════════
   PauseLayer hook  — Tab ile menü aç
   (Pause ekranında da çalışsın diye)
   ════════════════════════════════════════════ */
class $modify(EHPauseLayer, PauseLayer) {
    void keyDown(enumKeyCodes key) override {
        PauseLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }
};

/* ════════════════════════════════════════════
   PlayLayer hook  — Oyun içi Tab tuşu
   ════════════════════════════════════════════ */
class $modify(EHPlayLayerKey, PlayLayer) {
    void keyDown(enumKeyCodes key) override {
        PlayLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }
};

/* ════════════════════════════════════════════
   MenuLayer hook  — Ana menüde Tab tuşu
   ════════════════════════════════════════════ */
class $modify(EHMenuLayerKey, MenuLayer) {
    void keyDown(enumKeyCodes key) override {
        MenuLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }
};

/* ════════════════════════════════════════════
   Geode entry point
   ════════════════════════════════════════════ */
$on_mod(Loaded) {
    log::info("[EmiR Hub] Yüklendi. Tab tuşu ile menüyü aç.");
}

/*
   mod.json:
   {
     "id":        "emirkaya.emir_hub",
     "name":      "EmiR Hub",
     "developer": "EmiR",
     "version":   "1.1.0",
     "geode":     "3.0.0",
     "gd": { "win": "2.2081", "android": "2.2081", "mac": "2.2081" },
     "dependencies": [
       { "id": "geode.loader", "version": ">=3.0.0", "importance": "required" }
     ],
     "settings": {
       "trajectory_enabled": {
         "name":        "Trajectory Aktif",
         "description": "Zıplandığında yol tahmini çizgisini göster/gizle.",
         "type":        "bool",
         "default":     true
       },
       "dot_count": {
         "name":        "Nokta Sayısı",
         "description": "Trajectory'de kaç nokta gösterilsin (10-120).",
         "type":        "int",
         "default":     60,
         "min":         10,
         "max":         120
       },
       "show_mode_label": {
         "name":        "Mod Etiketi",
         "description": "Trajectory üzerinde mod adını göster.",
         "type":        "bool",
         "default":     true
       }
     }
   }
*/
