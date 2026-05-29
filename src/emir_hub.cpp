/*
 * Emir Hub — Lines Only (Trajectory Preview)
 * Geode / GD 2.2081 / Android aarch64
 */

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include <cmath>

using namespace geode::prelude;
using namespace cocos2d;

namespace emir_hub {
    constexpr int kPreviewSegments = 24;
    constexpr float kPreviewStep = 1.0f / 12.0f;
    constexpr float kLineRadius = 1.35f;
    constexpr float kMinimumVelocity = 0.01f;
    constexpr int kDrawZOrder = 9997;

    bool g_trajectoryEnabled = true;
    CCDrawNode* g_trajectoryNode = nullptr;

    CCPoint getPlayerVelocity(PlayerObject* player) {
        if (!player) {
            return ccp(0.0f, 0.0f);
        }

        return ccp(
            static_cast<float>(player->getCurrentXVelocity()),
            static_cast<float>(player->getYVelocity())
        );
    }

    bool hasDrawableVelocity(CCPoint const& velocity) {
        return std::abs(velocity.x) > kMinimumVelocity || std::abs(velocity.y) > kMinimumVelocity;
    }

    void clearTrajectory() {
        if (g_trajectoryNode) {
            g_trajectoryNode->clear();
        }
    }

    void detachTrajectoryNode() {
        clearTrajectory();
        g_trajectoryNode = nullptr;
    }

    void refreshTrajectory(PlayLayer* layer) {
        if (!g_trajectoryEnabled || !g_trajectoryNode) {
            clearTrajectory();
            return;
        }

        g_trajectoryNode->clear();

        if (!layer || !layer->isGameplayActive()) {
            return;
        }

        auto player = layer->m_player1;
        if (!player) {
            return;
        }

        auto const velocity = getPlayerVelocity(player);
        if (!hasDrawableVelocity(velocity)) {
            return;
        }

        auto previous = player->getPosition();
        auto const color = ccc4f(1.0f, 0.9f, 0.05f, 0.9f);

        for (int step = 1; step <= kPreviewSegments; ++step) {
            auto const time = static_cast<float>(step) * kPreviewStep;
            auto const next = ccp(
                previous.x + velocity.x * kPreviewStep,
                player->getPositionY() + velocity.y * time
            );

            g_trajectoryNode->drawSegment(previous, next, kLineRadius, color);
            previous = next;
        }
    }
}

class $modify(EmirHubPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        emir_hub::g_trajectoryNode = CCDrawNode::create();
        emir_hub::g_trajectoryNode->setZOrder(emir_hub::kDrawZOrder);
        this->addChild(emir_hub::g_trajectoryNode);

        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);
        emir_hub::refreshTrajectory(this);
    }

    void onExit() {
        emir_hub::detachTrajectoryNode();
        PlayLayer::onExit();
    }
};
