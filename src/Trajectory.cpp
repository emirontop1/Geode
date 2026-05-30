#include "Trajectory.hpp"
#include "../../Client/Client.hpp"

/* ══════════════════════════════
   Fizik sabitleri
   ══════════════════════════════ */
static constexpr int   SIM_STEPS      = 120;
static constexpr float SIM_DT         = 1.f / 60.f;
static constexpr float GRAVITY        = -900.f;
static constexpr float SHIP_ACCEL     = 700.f;
static constexpr float PLAYER_HW      = 30.f;
static constexpr float PLAYER_HH      = 30.f;
static constexpr float TRAJ_RADIUS    = 3.5f;
static constexpr float OPACITY_MAX    = 200.f;
static const ccColor3B TRAJ_COLOR     = { 255, 220, 50 };

/* ══════════════════════════════
   Yardımcı: solid obje mi?
   ══════════════════════════════ */
static bool isSolid(GameObject* obj) {
    if (!obj)                    return false;
    if (obj->m_isDisabled)       return false;
    if (obj->m_isTrigger)        return false;
    if (obj->m_isInvisibleBlock) return false;
    if (obj->m_isPassable)       return false;
    if (obj->m_isDecoration)     return false;
    if (obj->m_isDecoration2)    return false;
    return true;
}

/* ══════════════════════════════
   Verilen noktada solid çarpışma
   ══════════════════════════════ */
static bool collidesWithSolid(GJBaseGameLayer* gbl, CCPoint pos) {
    if (!gbl) return false;
    CCRect hb{ pos.x - PLAYER_HW*.5f, pos.y - PLAYER_HH*.5f, PLAYER_HW, PLAYER_HH };
    auto* arr = gbl->staticObjectsInRect(hb, true);
    if (!arr) return false;
    for (int i = 0; i < (int)arr->count(); i++) {
        auto* obj = static_cast<GameObject*>(arr->objectAtIndex(i));
        if (isSolid(obj) && hb.intersectsRect(obj->boundingBox()))
            return true;
    }
    return false;
}

/* ══════════════════════════════
   computeTrajectory
   ══════════════════════════════ */
std::vector<CCPoint> computeTrajectory(
    PlayLayer* pl, PlayerCheckpoint* cp,
    PlayerObject* player, LevelSettingsObject* settings)
{
    std::vector<CCPoint> pts;
    if (!pl || !cp || !player) return pts;

    auto* gbl = static_cast<GJBaseGameLayer*>(pl);

    float px  = player->getPositionX();
    float py  = player->getPositionY();
    float vx  = player->getCurrentXVelocity();
    float vy  = 0.f;
    float grav    = cp->m_gravityMod > 0.f ? cp->m_gravityMod : 1.f;
    float gravDir = cp->m_isUpsideDown ? 1.f : -1.f;
    bool  plat    = settings ? settings->m_platformerMode : false;

    bool isShip   = cp->m_isShip;
    bool isBall   = cp->m_isBall;
    bool isBird   = cp->m_isBird;
    bool isWave   = cp->m_isDart;
    bool isRobot  = cp->m_isRobot;
    bool isSpider = cp->m_isSpider;
    bool isSwing  = cp->m_isSwing;
    bool isCube   = !isShip && !isBall && !isBird && !isWave && !isRobot && !isSpider && !isSwing;

    /* Başlangıç Y hızı (zıplama anı simülasyonu) */
    if      (isCube || isRobot) { vy = 550.f * grav; if (cp->m_isMini) vy *= .75f; }
    else if (isBall)            vy = 300.f * grav;
    else if (isBird)            vy = 350.f * grav;
    else if (isShip || isSwing) vy = 200.f * grav;
    else if (isSpider)          vy = 450.f * grav;
    /* isWave: vy=0, açıyla hareket eder */

    if (plat && vx == 0.f) vx = 200.f;

    int dotCount = (int)Mod::get()->getSettingValue<int64_t>("dot_count");
    if (dotCount <= 0 || dotCount > SIM_STEPS) dotCount = SIM_STEPS;

    for (int step = 0; step < dotCount; step++) {
        if (isWave) {
            float ang = CC_DEGREES_TO_RADIANS(cp->m_isUpsideDown ? 45.f : -45.f);
            float spd = std::abs(vx) > 0.f ? std::abs(vx) : 300.f;
            px += std::cos(ang) * spd * SIM_DT;
            py += std::sin(ang) * spd * SIM_DT;
        } else if (isShip) {
            vy += SHIP_ACCEL * grav * gravDir * SIM_DT;
            vy  = std::clamp(vy, -700.f, 700.f);
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else if (isSwing) {
            vy += SHIP_ACCEL * .9f * grav * gravDir * SIM_DT;
            vy  = std::clamp(vy, -650.f, 650.f);
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else if (isBall) {
            vy += GRAVITY * grav * (-gravDir) * SIM_DT;
            px += vx * SIM_DT; py += vy * SIM_DT;
        } else { /* Cube, UFO, Robot, Spider */
            vy += GRAVITY * grav * gravDir * SIM_DT;
            px += vx * SIM_DT; py += vy * SIM_DT;
        }

        CCPoint sim = ccp(px, py);
        if (collidesWithSolid(gbl, sim)) { pts.push_back(sim); break; }
        pts.push_back(sim);
    }
    return pts;
}

/* ══════════════════════════════
   TrajectoryNode  —  create
   ══════════════════════════════ */
TrajectoryNode* TrajectoryNode::create() {
    auto* n = new TrajectoryNode();
    if (n && n->init()) { n->autorelease(); return n; }
    CC_SAFE_DELETE(n);
    return nullptr;
}

bool TrajectoryNode::init() {
    if (!CCNode::init()) return false;

    m_modeLabel = CCLabelBMFont::create("", "bigFont.fnt");
    m_modeLabel->setScale(.38f);
    m_modeLabel->setColor(TRAJ_COLOR);
    m_modeLabel->setOpacity(200);
    m_modeLabel->setVisible(false);
    addChild(m_modeLabel, 2);

    return true;
}

void TrajectoryNode::setPoints(const std::vector<CCPoint>& pts, const std::string& mode) {
    m_points = pts;
    bool showLabel = Client::get().isEnabled("show_mode_label");
    if (m_modeLabel) {
        if (!pts.empty() && showLabel) {
            m_modeLabel->setString(("[ " + mode + " ]").c_str());
            m_modeLabel->setPosition(ccp(pts.front().x, pts.front().y + 20.f));
            m_modeLabel->setVisible(true);
        } else {
            m_modeLabel->setVisible(false);
        }
    }
    setVisible(!pts.empty());
}

/* ══════════════════════════════
   draw()  —  noktaları çiz
   ══════════════════════════════ */
void TrajectoryNode::draw() {
    CCNode::draw();
    int n = (int)m_points.size();
    for (int i = 0; i < n; i++) {
        float a = 1.f - ((float)i / (float)n) * .85f;
        ccDrawColor4B(TRAJ_COLOR.r, TRAJ_COLOR.g, TRAJ_COLOR.b, (GLubyte)(OPACITY_MAX * a));
        ccDrawCircle(m_points[i], TRAJ_RADIUS, 0, 12, false);
    }
}
