#pragma once
#include <Geode/Geode.hpp>
#include <vector>

using namespace geode::prelude;
using namespace cocos2d;

/* ═══════════════════════════════════════════════════════
   TrajectoryNode  —  Her frame PlayLayer üstüne çizilir
   ═══════════════════════════════════════════════════════ */
class TrajectoryNode : public CCNode {
public:
    std::vector<CCPoint> m_points;
    CCLabelBMFont*       m_modeLabel = nullptr;

    static TrajectoryNode* create();
    bool  init() override;

    void  setPoints(const std::vector<CCPoint>& pts, const std::string& mode);
    void  draw() override;
};

/* ═══════════════════════════════════════════════════════
   Fizik simülasyonu (PlayLayer → computeTrajectory)
   ═══════════════════════════════════════════════════════ */
std::vector<CCPoint> computeTrajectory(
    PlayLayer*           pl,
    PlayerCheckpoint*    cp,
    PlayerObject*        player,
    LevelSettingsObject* settings
);
