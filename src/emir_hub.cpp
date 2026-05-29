/*
 * Emir Hub — Lines Only (Trajectory Preview)
 * Geode / GD 2.2081 / Android aarch64
 */

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;
using namespace cocos2d;

// Global durum
namespace EH {
    bool traj = true;
    CCDrawNode* drawNode = nullptr;
}

// Yörünge güncelleme fonksiyonu (PlayLayer'dan çağrılacak)
void refreshTraj(PlayLayer* self) {
    if (!EH::traj || !EH::drawNode) return;
    
    EH::drawNode->clear();
    
    auto player = self->m_player1;
    if (!player) return;

    // Basit bir yörünge tahmini (Velocity bazlı)
    auto pos = player->getPosition();
    auto vel = player->getVelocity();
    
    // Yörünge çizgisi çizimi
    for (int i = 0; i < 20; ++i) {
        auto nextPos = pos + vel * (i * 0.1f);
        EH::drawNode->drawDot(nextPos, 2.0f, ccc4f(1, 1, 0, 1)); // Sarı yörünge
    }
}

class $modify(MyPlayLayer, PlayLayer) {
    bool init(GJGameLevel* lvl, bool replay, bool noCreate) {
        if (!PlayLayer::init(lvl, replay, noCreate)) return false;

        // DrawNode'u PlayLayer'a ekle
        EH::drawNode = CCDrawNode::create();
        EH::drawNode->setZOrder(9997);
        this->addChild(EH::drawNode);

        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);
        refreshTraj(this);
    }
};
