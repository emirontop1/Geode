/**
 * emir_hub.cpp
 * Geode Mod — EmiR Hub
 *
 * Özellik: Oyuncu anda zıpladığında (veya mod'a göre inputa bastığında)
 * nereye gideceğini gösteren trajectory (yol tahmini) çizgisi.
 * - Cube, Ship, Ball, UFO (Bird), Wave (Dart), Robot, Spider, Swing ve
 *   Platformer modların tümünü destekler.
 * - m_isPassable == false olan objeler (solid bloklar) çarpışmayı durdurur.
 * - GJBaseGameLayer::staticObjectsInRect() ile çevreden solid objeleri alır.
 * - Her frame PlayLayer::postUpdate hook'u içinde güncellenir.
 */

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;
using namespace cocos2d;

/* ─────────────────────────────────────────────
   Simülasyon sabitleri
   ───────────────────────────────────────────── */
static constexpr int   SIM_STEPS        = 120;
static constexpr float SIM_DT           = 1.0f / 60.0f;
static constexpr float GRAVITY          = -900.0f;
static constexpr float SHIP_ACCEL_UP    = 700.0f;
static constexpr float SHIP_ACCEL_DOWN  = 700.0f;
static constexpr float WAVE_ANGLE_UP    = -45.0f;
static constexpr float WAVE_ANGLE_DOWN  =  45.0f;
static constexpr float PLAYER_HITBOX_W  = 30.0f;
static constexpr float PLAYER_HITBOX_H  = 30.0f;
static constexpr float TRAJ_DOT_RADIUS  = 3.5f;
static constexpr int   DOT_COLOR_R      = 255;
static constexpr int   DOT_COLOR_G      = 220;
static constexpr int   DOT_COLOR_B      = 50;
static constexpr float DOT_OPACITY_MAX  = 200.0f;

/* ─────────────────────────────────────────────
   Mod ayar anahtarları
   ───────────────────────────────────────────── */
static const std::string SETTING_ENABLED   = "trajectory_enabled";
static const std::string SETTING_DOT_COUNT = "dot_count";

/* ─────────────────────────────────────────────
   Yardımcı: Checkpoint'ten mod adı
   ───────────────────────────────────────────── */
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

/* ─────────────────────────────────────────────
   Solid obje kontrolü
   ───────────────────────────────────────────── */
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

/* ─────────────────────────────────────────────
   Verilen pozisyonda solid çarpışma var mı?
   ───────────────────────────────────────────── */
static bool collidesWithSolid(GJBaseGameLayer* gbl, CCPoint pos) {
    if (!gbl) return false;

    CCRect hitbox = CCRect(
        pos.x - PLAYER_HITBOX_W * 0.5f,
        pos.y - PLAYER_HITBOX_H * 0.5f,
        PLAYER_HITBOX_W,
        PLAYER_HITBOX_H
    );

    CCArray* statics = gbl->staticObjectsInRect(hitbox, true);
    if (!statics) return false;

    for (int i = 0; i < (int)statics->count(); i++) {
        auto* obj = static_cast<GameObject*>(statics->objectAtIndex(i));
        if (isSolidObject(obj)) {
            if (hitbox.intersectsRect(obj->boundingBox()))
                return true;
        }
    }
    return false;
}

/* ─────────────────────────────────────────────
   Trajectory noktaları hesapla
   ───────────────────────────────────────────── */
static std::vector<CCPoint> computeTrajectory(
    PlayLayer*           pl,
    PlayerCheckpoint*    cp,
    PlayerObject*        player,
    LevelSettingsObject* settings)
{
    std::vector<CCPoint> points;
    if (!pl || !cp || !player) return points;

    GJBaseGameLayer* gbl = static_cast<GJBaseGameLayer*>(pl);

    float px    = player->getPositionX();
    float py    = player->getPositionY();
    float vx    = player->getCurrentXVelocity();
    float vy    = 0.0f;
    float grav  = cp->m_gravityMod > 0.0f ? cp->m_gravityMod : 1.0f;
    float gravDir = cp->m_isUpsideDown ? 1.0f : -1.0f;
    bool  isPlatformer = settings ? settings->m_platformerMode : false;

    bool isCube   = !cp->m_isShip && !cp->m_isBall && !cp->m_isBird &&
                    !cp->m_isDart && !cp->m_isRobot && !cp->m_isSpider &&
                    !cp->m_isSwing;
    bool isShip   = cp->m_isShip;
    bool isBall   = cp->m_isBall;
    bool isBird   = cp->m_isBird;
    bool isWave   = cp->m_isDart;
    bool isRobot  = cp->m_isRobot;
    bool isSpider = cp->m_isSpider;
    bool isSwing  = cp->m_isSwing;

    if (isCube || isRobot) {
        vy = 550.0f * grav;
        if (cp->m_isMini) vy *= 0.75f;
    } else if (isBall) {
        vy = 300.0f * grav;
    } else if (isBird) {
        vy = 350.0f * grav;
    } else if (isShip || isSwing) {
        vy = 200.0f * grav;
    } else if (isWave) {
        vy = 0.0f;
    } else if (isSpider) {
        vy = 450.0f * grav;
    }

    if (isPlatformer) {
        vx = (vx == 0.0f) ? 200.0f : vx;
    }

    int dotCount = Mod::get()->getSettingValue<int64_t>(SETTING_DOT_COUNT);
    if (dotCount <= 0 || dotCount > SIM_STEPS) dotCount = SIM_STEPS;

    for (int step = 0; step < dotCount; step++) {
        if (isWave) {
            float waveAngleDeg = cp->m_isUpsideDown ? WAVE_ANGLE_DOWN : WAVE_ANGLE_UP;
            float rad   = CC_DEGREES_TO_RADIANS(waveAngleDeg);
            float speed = std::abs(vx) > 0.0f ? std::abs(vx) : 300.0f;
            px += std::cos(rad) * speed * SIM_DT;
            py += std::sin(rad) * speed * SIM_DT;
        } else if (isShip) {
            float accel = SHIP_ACCEL_UP * grav * gravDir;
            vy += accel * SIM_DT;
            vy  = std::clamp(vy, -700.0f, 700.0f);
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else if (isSwing) {
            float accel = SHIP_ACCEL_UP * 0.9f * grav * gravDir;
            vy += accel * SIM_DT;
            vy  = std::clamp(vy, -650.0f, 650.0f);
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else if (isBall) {
            float gravAccel = GRAVITY * grav * (-gravDir);
            vy += gravAccel * SIM_DT;
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else {
            float gravAccel = GRAVITY * grav * gravDir;
            vy += gravAccel * SIM_DT;
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        }

        CCPoint simPos = ccp(px, py);

        if (collidesWithSolid(gbl, simPos)) {
            points.push_back(simPos);
            break;
        }

        points.push_back(simPos);
    }

    return points;
}

/* ─────────────────────────────────────────────
   Trajectory çizim katmanı
   ───────────────────────────────────────────── */
class TrajectoryNode : public CCNode {
public:
    std::vector<CCPoint> m_points;
    CCLabelBMFont*       m_modeLabel = nullptr;

    static TrajectoryNode* create() {
        auto* node = new TrajectoryNode();
        if (node && node->init()) {
            node->autorelease();
            return node;
        }
        CC_SAFE_DELETE(node);
        return nullptr;
    }

    bool init() override {
        if (!CCNode::init()) return false;

        m_modeLabel = CCLabelBMFont::create("", "bigFont.fnt");
        m_modeLabel->setScale(0.45f);
        m_modeLabel->setColor({DOT_COLOR_R, DOT_COLOR_G, DOT_COLOR_B});
        m_modeLabel->setOpacity(200);
        this->addChild(m_modeLabel, 2);

        return true;
    }

    void setPoints(const std::vector<CCPoint>& points, const std::string& mode) {
        m_points = points;
        if (m_modeLabel && !points.empty()) {
            m_modeLabel->setString(("Trajectory — " + mode).c_str());
            m_modeLabel->setPosition(ccp(points.front().x, points.front().y + 25.0f));
        }
        this->setVisible(!points.empty());
    }

    void draw() override {
        CCNode::draw();
        if (m_points.empty()) return;

        int n = (int)m_points.size();
        for (int i = 0; i < n; i++) {
            float alpha = 1.0f - ((float)i / (float)n) * 0.85f;
            ccDrawColor4B(
                DOT_COLOR_R,
                DOT_COLOR_G,
                DOT_COLOR_B,
                (GLubyte)(DOT_OPACITY_MAX * alpha)
            );
            ccDrawCircle(m_points[i], TRAJ_DOT_RADIUS, 0, 12, false);
        }
    }
};

/* ─────────────────────────────────────────────
   FLAlertLayer popup için delegate
   FLAlertLayerProtocol implement eden ayrı sınıf.
   SDK referansına göre FLAlertLayer::create()
   delegate pointer alır; subclass init() çağrısı
   yanlış — doğrusu static create() + protocol.
   ───────────────────────────────────────────── */
class EHAlertDelegate : public FLAlertLayerProtocol {
public:
    void FLAlert_Clicked(FLAlertLayer* /*layer*/, bool btn2) override {
        if (btn2) {
            bool cur = Mod::get()->getSettingValue<bool>(SETTING_ENABLED);
            (void)Mod::get()->setSettingValue<bool>(SETTING_ENABLED, !cur);
        }
    }
};

// Delegate'i static olarak tut (popup kapatılana kadar yaşamalı)
static EHAlertDelegate s_ehDelegate;

/* Popup'ı ekrana getiren yardımcı fonksiyon */
static void showEHMenu() {
    // SDK: FLAlertLayer::create(delegate, title, desc, btn1, btn2, width)
    auto* alert = FLAlertLayer::create(
        &s_ehDelegate,
        "EmiR Hub",
        "Trajectory sistemi aktif/pasif:",
        "Kapat",
        "Aç/Kapat",
        300.0f
    );
    alert->show();
}

/* ─────────────────────────────────────────────
   PlayLayer hook
   ───────────────────────────────────────────── */
class $modify(EHPlayLayer, PlayLayer) {
    struct Fields {
        TrajectoryNode*   trajectoryNode = nullptr;
        PlayerCheckpoint* tempCp         = nullptr;
    };

    void postUpdate(float dt) override {
        PlayLayer::postUpdate(dt);

        if (!Mod::get()->getSettingValue<bool>(SETTING_ENABLED)) {
            if (m_fields->trajectoryNode)
                m_fields->trajectoryNode->setVisible(false);
            return;
        }

        _ensureTrajectoryNode();
        _updateTrajectory();
    }

    void resetLevel() override {
        PlayLayer::resetLevel();
        if (m_fields->trajectoryNode)
            m_fields->trajectoryNode->setPoints({}, "");
    }

private:
    void _ensureTrajectoryNode() {
        if (m_fields->trajectoryNode) return;

        auto* node = TrajectoryNode::create();
        if (!node) return;

        this->addChild(node, 1000);
        m_fields->trajectoryNode = node;
    }

    void _updateTrajectory() {
        auto* node = m_fields->trajectoryNode;
        if (!node) return;

        PlayerObject* player = m_player1;
        if (!player) { node->setPoints({}, ""); return; }

        PlayerCheckpoint* cp = PlayerCheckpoint::create();
        if (!cp)    { node->setPoints({}, ""); return; }
        player->saveToCheckpoint(cp);

        std::string          mode     = modeName(cp);
        LevelSettingsObject* settings = m_levelSettings;

        std::vector<CCPoint> pts = computeTrajectory(this, cp, player, settings);

        node->setPosition(CCPointZero);
        node->setPoints(pts, mode);
    }
};

/* ─────────────────────────────────────────────
   Geode entry point
   ───────────────────────────────────────────── */
$on_mod(Loaded) {
    log::info("[EmiR Hub] Mod yüklendi. Trajectory sistemi hazır.");
}

/*
   mod.json örneği:
   {
     "id":        "emirkaya.emir_hub",
     "name":      "EmiR Hub",
     "developer": "EmiR",
     "version":   "1.0.0",
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
       }
     }
   }
*/
