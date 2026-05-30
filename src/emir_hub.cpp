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
static constexpr int   SIM_STEPS        = 120;   // kaç adım simüle edilecek
static constexpr float SIM_DT           = 1.0f / 60.0f; // her adımın süresi (saniye)
static constexpr float GRAVITY          = -900.0f;  // piksel / s²  (normal gravity)
static constexpr float SHIP_ACCEL_UP    = 700.0f;
static constexpr float SHIP_ACCEL_DOWN  = 700.0f;
static constexpr float WAVE_ANGLE_UP    = -45.0f;   // derece
static constexpr float WAVE_ANGLE_DOWN  =  45.0f;
static constexpr float PLAYER_HITBOX_W  = 30.0f;
static constexpr float PLAYER_HITBOX_H  = 30.0f;
static constexpr float TRAJ_DOT_RADIUS  = 3.5f;
static constexpr int   DOT_COLOR_R      = 255;
static constexpr int   DOT_COLOR_G      = 220;
static constexpr int   DOT_COLOR_B      = 50;
static constexpr float DOT_OPACITY_MAX  = 200.0f;   // 0-255

/* ─────────────────────────────────────────────
   Mod adı / ayarlar için Geode keys
   ───────────────────────────────────────────── */
static const std::string SETTING_ENABLED   = "trajectory_enabled";
static const std::string SETTING_DOT_COUNT = "dot_count";

/* ─────────────────────────────────────────────
   Yardımcı: GameObjectType'dan mod adı
   ───────────────────────────────────────────── */
static std::string modeName(PlayerCheckpoint* cp) {
    if (!cp) return "Cube";
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
   Solid kontrol
   isPassable == true  → geçilebilir (sadece dekorasyon / trigger)
   isPassable == false → katı blok, çarpışma var
   ───────────────────────────────────────────── */
static bool isSolidObject(GameObject* obj) {
    if (!obj)                  return false;
    if (obj->m_isDisabled)     return false;
    if (obj->m_isTrigger)      return false;
    if (obj->m_isInvisibleBlock) return false;
    if (obj->m_isPassable)     return false;  // geçilebilir → solid değil
    if (obj->m_isDecoration)   return false;
    if (obj->m_isDecoration2)  return false;
    return true;
}

/* ─────────────────────────────────────────────
   Solid çarpışma kontrolü: verilen rect içinde
   solid bir obje var mı?
   ───────────────────────────────────────────── */
static bool collidesWithSolid(GJBaseGameLayer* gbl, CCPoint pos) {
    if (!gbl) return false;

    CCRect hitbox = CCRect(
        pos.x - PLAYER_HITBOX_W * 0.5f,
        pos.y - PLAYER_HITBOX_H * 0.5f,
        PLAYER_HITBOX_W,
        PLAYER_HITBOX_H
    );

    // Statik (solid) objeleri al
    CCArray* statics = gbl->staticObjectsInRect(hitbox, true);
    if (!statics) return false;

    for (int i = 0; i < (int)statics->count(); i++) {
        auto* obj = static_cast<GameObject*>(statics->objectAtIndex(i));
        if (isSolidObject(obj)) {
            // AABB çakışması
            CCRect objRect = obj->boundingBox();
            if (hitbox.intersectsRect(objRect)) {
                return true;
            }
        }
    }
    return false;
}

/* ─────────────────────────────────────────────
   Trajectory noktaları hesapla
   Checkpoint verilerini oku; her mod için
   farklı fizik simüle et.
   ───────────────────────────────────────────── */
static std::vector<CCPoint> computeTrajectory(
    PlayLayer* pl,
    PlayerCheckpoint* cp,
    PlayerObject* player,
    LevelSettingsObject* settings)
{
    std::vector<CCPoint> points;
    if (!pl || !cp || !player) return points;

    GJBaseGameLayer* gbl = static_cast<GJBaseGameLayer*>(pl);

    // Başlangıç durumu
    float px    = player->getPositionX();
    float py    = player->getPositionY();
    float vx    = player->getCurrentXVelocity();
    float vy    = 0.0f;  // zıpla anındaki Y hızı (simülasyon başlangıcı)
    float grav  = cp->m_gravityMod > 0.0f ? cp->m_gravityMod : 1.0f;
    float gravDir = cp->m_isUpsideDown ? 1.0f : -1.0f;  // ters yerçekimi
    bool  isPlatformer = settings ? settings->m_platformerMode : false;

    /* --- Mod tespiti --- */
    bool isCube    = !cp->m_isShip && !cp->m_isBall && !cp->m_isBird &&
                     !cp->m_isDart && !cp->m_isRobot && !cp->m_isSpider &&
                     !cp->m_isSwing;
    bool isShip    = cp->m_isShip;
    bool isBall    = cp->m_isBall;
    bool isBird    = cp->m_isBird;   // UFO
    bool isWave    = cp->m_isDart;
    bool isRobot   = cp->m_isRobot;
    bool isSpider  = cp->m_isSpider;
    bool isSwing   = cp->m_isSwing;

    // Mod bazlı başlangıç Y hızı (jump anı simülasyonu)
    if (isCube || isRobot) {
        // Cube/Robot: klasik jump, hız yaklaşık 550
        vy = 550.0f * grav;
        if (cp->m_isMini) vy *= 0.75f;
    } else if (isBall) {
        // Ball: yerçekimi tersine döner, hız düşük
        vy = 300.0f * grav;
    } else if (isBird) {
        // UFO: sabit boost
        vy = 350.0f * grav;
    } else if (isShip || isSwing) {
        // Ship/Swing: sürekli yukarı iter
        vy = 200.0f * grav;
    } else if (isWave) {
        // Wave (Dart): sabit açıda hareket; vy simülasyonu gerekmez
        vy = 0.0f;
    } else if (isSpider) {
        // Spider: karşı duvara veya zeminine zıplar
        vy = 450.0f * grav;
    }

    // Platformer modda yatay hız daha düşük
    if (isPlatformer) {
        vx = (vx == 0.0f) ? 200.0f : vx;
    }

    int dotCount = Mod::get()->getSettingValue<int64_t>(SETTING_DOT_COUNT);
    if (dotCount <= 0 || dotCount > SIM_STEPS) dotCount = SIM_STEPS;

    /* ─── Simülasyon döngüsü ─── */
    for (int step = 0; step < dotCount; step++) {
        float t = (float)step / (float)dotCount;

        /* Wave (Dart) özel hareketi:
           Sabit açıyla yönelir, yerçekimi yoktur */
        if (isWave) {
            float waveAngleDeg = cp->m_isUpsideDown ? WAVE_ANGLE_DOWN : WAVE_ANGLE_UP;
            float rad = CC_DEGREES_TO_RADIANS(waveAngleDeg);
            float speed = std::abs(vx) > 0.0f ? std::abs(vx) : 300.0f;
            px += std::cos(rad) * speed * SIM_DT;
            py += std::sin(rad) * speed * SIM_DT;
        } else if (isShip) {
            /* Ship: input basılıysa yukarı, değilse aşağı */
            float accel = SHIP_ACCEL_UP * grav * gravDir;
            vy += accel * SIM_DT;
            vy = std::clamp(vy, -700.0f, 700.0f);
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else if (isSwing) {
            /* Swing: Ship benzeri ama swing ateşi modu */
            float accel = SHIP_ACCEL_UP * 0.9f * grav * gravDir;
            vy += accel * SIM_DT;
            vy = std::clamp(vy, -650.0f, 650.0f);
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else if (isBall) {
            /* Ball: yerçekimi tersine döner, arc yapar */
            float gravAccel = GRAVITY * grav * (-gravDir);
            vy += gravAccel * SIM_DT;
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        } else {
            /* Cube, UFO, Robot, Spider: standart parabolik yerçekimi */
            float gravAccel = GRAVITY * grav * gravDir;
            vy += gravAccel * SIM_DT;
            px += vx * SIM_DT;
            py += vy * SIM_DT;
        }

        CCPoint simPos = ccp(px, py);

        // Solid çarpışma kontrolü
        if (collidesWithSolid(gbl, simPos)) {
            // Son noktayı ekle, çizimi bitir
            points.push_back(simPos);
            break;
        }

        points.push_back(simPos);
    }

    return points;
}

/* ─────────────────────────────────────────────
   Trajectory çizim katmanı (CCNode)
   PlayLayer'ın üstüne eklenir.
   ───────────────────────────────────────────── */
class TrajectoryNode : public CCNode {
public:
    std::vector<CCPoint> m_points;
    CCLabelBMFont*        m_modeLabel = nullptr;

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

        // Mod ismi etiketi
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
            // Etiketi ilk noktanın biraz üstüne koy
            m_modeLabel->setPosition(
                ccp(points.front().x, points.front().y + 25.0f)
            );
        }
        this->setVisible(!points.empty());
    }

    /* Özel çizim: her nokta için küçük bir daire (CCDrawNode kullan) */
    void draw() override {
        CCNode::draw();
        if (m_points.empty()) return;

        // Fade: baştaki noktalar tam opak, sona doğru soluklaşır
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
   PlayLayer hook
   ───────────────────────────────────────────── */
class $modify(EHPlayLayer, PlayLayer) {
    struct Fields {
        TrajectoryNode* trajectoryNode = nullptr;
        PlayerCheckpoint* tempCp       = nullptr;
    };

    /* postUpdate: her frame çalışır */
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

    /* Level reset/tekrar başlatma */
    void resetLevel() override {
        PlayLayer::resetLevel();
        if (m_fields->trajectoryNode)
            m_fields->trajectoryNode->setPoints({}, "");
    }

private:
    /* Trajectory node yoksa oluştur ve sahneye ekle */
    void _ensureTrajectoryNode() {
        if (m_fields->trajectoryNode) return;

        auto* node = TrajectoryNode::create();
        if (!node) return;

        // PlayLayer'ın UI katmanına ekle (z-order yüksek)
        this->addChild(node, 1000);
        m_fields->trajectoryNode = node;
    }

    /* Trajectory hesapla ve çiz */
    void _updateTrajectory() {
        auto* node = m_fields->trajectoryNode;
        if (!node) return;

        PlayerObject* player = m_player1;
        if (!player) {
            node->setPoints({}, "");
            return;
        }

        // Geçici checkpoint ile anlık durumu oku
        PlayerCheckpoint* cp = PlayerCheckpoint::create();
        if (!cp) { node->setPoints({}, ""); return; }
        player->saveToCheckpoint(cp);

        std::string mode = modeName(cp);

        LevelSettingsObject* settings = m_levelSettings;

        std::vector<CCPoint> pts = computeTrajectory(this, cp, player, settings);

        // Trajectory node'u playerın parent düğümüne göre düzelt
        // (PlayLayer'ın dünya koordinatlarında)
        node->setPosition(CCPointZero);
        node->setPoints(pts, mode);

        // cp artık gerekli değil (autorelease olduğu için serbest bırakılır)
    }
};

/* ─────────────────────────────────────────────
   Mod menüsü: Geode Settings panel üzerinden
   Ayarlar mod.json içinde tanımlanır.
   Burada çalışma zamanı toggle için kısa bir
   FLAlertLayer popup da ekliyoruz.
   ───────────────────────────────────────────── */
class EHMenuLayer : public FLAlertLayer {
public:
    static EHMenuLayer* create() {
        auto* layer = new EHMenuLayer();
        if (layer && layer->init(nullptr, "EmiR Hub", "Trajectory sistemi aktif/pasif:",
                                 "Kapat", "Aç/Kapat", 300.0f)) {
            layer->autorelease();
            return layer;
        }
        CC_SAFE_DELETE(layer);
        return nullptr;
    }

    void FLAlert_Clicked(FLAlertLayer* layer, bool btn2) override {
        if (btn2) {
            bool cur = Mod::get()->getSettingValue<bool>(SETTING_ENABLED);
            (void)Mod::get()->setSettingValue<bool>(SETTING_ENABLED, !cur);
        }
    }
};

/* ─────────────────────────────────────────────
   mod.json tanımı (başlık yorumu olarak)
   ─────────────────────────────────────────────
   {
     "id":          "emirkaya.emir_hub",
     "name":        "EmiR Hub",
     "developer":   "EmiR",
     "version":     "1.0.0",
     "geode":       "3.0.0",
     "gd":          { "win": "2.2081", "android": "2.2081", "mac": "2.2081" },
     "dependencies": [
       { "id": "geode.loader", "version": ">=3.0.0", "importance": "required" }
     ],
     "settings": {
       "trajectory_enabled": {
         "name":    "Trajectory Aktif",
         "description": "Zıplandığında yol tahmini çizgisini göster/gizle.",
         "type":    "bool",
         "default": true
       },
       "dot_count": {
         "name":    "Nokta Sayısı",
         "description": "Trajectory'de kaç nokta gösterilsin (10-120).",
         "type":    "int",
         "default": 60,
         "min":     10,
         "max":     120
       }
     }
   }
   ─────────────────────────────────────────────── */

/* ─────────────────────────────────────────────
   Geode entry point
   ───────────────────────────────────────────── */
$on_mod(Loaded) {
    log::info("[EmiR Hub] Mod yüklendi. Trajectory sistemi hazır.");
}
