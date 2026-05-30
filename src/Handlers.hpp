#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "../UI/EHMenuLayer.hpp"
#include "../Client/Client.hpp"
#include "../Hacks/Trajectory/Trajectory.hpp"

using namespace geode::prelude;
using namespace cocos2d;

/* ═══════════════════════════════════════════════════════
   Yardımcı: PlayerCheckpoint'ten mod adı
   ═══════════════════════════════════════════════════════ */
static inline std::string modeName(PlayerCheckpoint* cp) {
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

/* ═══════════════════════════════════════════════════════
   PlayLayer  —  trajectory çizimi + Tab tuşu
   ═══════════════════════════════════════════════════════ */
class $modify(EHPlayLayer, PlayLayer) {
    struct Fields {
        TrajectoryNode* tnode = nullptr;
    };

    /* postUpdate: her frame */
    void postUpdate(float dt) override {
        PlayLayer::postUpdate(dt);

        if (!Client::get().isEnabled("trajectory_enabled")) {
            if (m_fields->tnode) m_fields->tnode->setVisible(false);
            return;
        }
        _ensureNode();
        _updateTrajectory();
    }

    void resetLevel() override {
        PlayLayer::resetLevel();
        if (m_fields->tnode) m_fields->tnode->setPoints({}, "");
    }

    void onQuit() override {
        EHMenuLayer::destroy();
        PlayLayer::onQuit();
    }

    /* Tab tuşu → menüyü aç/kapat */
    void keyDown(enumKeyCodes key) override {
        PlayLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }

private:
    void _ensureNode() {
        if (m_fields->tnode) return;
        auto* n = TrajectoryNode::create();
        if (!n) return;
        addChild(n, 1000);
        m_fields->tnode = n;
    }

    void _updateTrajectory() {
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

/* ═══════════════════════════════════════════════════════
   PauseLayer  —  Tab tuşu
   ═══════════════════════════════════════════════════════ */
class $modify(EHPauseLayer, PauseLayer) {
    void keyDown(enumKeyCodes key) override {
        PauseLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }
};

/* ═══════════════════════════════════════════════════════
   MenuLayer (ana menü)  —  Tab tuşu
   ═══════════════════════════════════════════════════════ */
class $modify(EHMenuLayerHook, MenuLayer) {
    void keyDown(enumKeyCodes key) override {
        MenuLayer::keyDown(key);
        if (key == enumKeyCodes::KEY_Tab)
            EHMenuLayer::toggle();
    }
};
