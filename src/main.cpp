#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace geode::prelude;

namespace {
    // Tüm global değişkenler tek bir yerde
    bool g_ignoreDamage = false, g_practiceMode = false, g_autoPlay = false;
    bool g_autoCube = true, g_autoWave = true, g_showHitboxes = false;
    bool g_platformerAssist = false, g_hidePlayer = false, g_hideGround = false;
    bool g_hideMG = false, g_hideAttempts = false, g_bgEffects = true;
    bool g_autoHoldingJump = false, g_autoHoldingRight = false;
    int g_autoTapFrames = 0, g_autoTapCooldown = 0, g_speedIndex = 2;
    constexpr std::array<float, 5> kSpeedValues = { 0.50f, 0.75f, 1.00f, 1.50f, 2.00f };

    enum class PlayerMode { Cube, Ship, Ball, Ufo, Wave, Robot, Spider, Swing, Unknown };
    struct ThreatScan { bool obstacleAhead, obstacleAbove, obstacleBelow, wallAhead; float closestX, safeTargetY; };

    // --- Fonksiyon Tanımlamaları (Tekil) ---
    void setJumpHeld(PlayerObject* player, bool held) {
        if (!player || g_autoHoldingJump == held) return;
        held ? player->pushButton(static_cast<PlayerButton>(1)) : player->releaseButton(static_cast<PlayerButton>(1));
        g_autoHoldingJump = held;
    }

    bool isGroundMode(PlayerMode mode) {
        return mode == PlayerMode::Cube || mode == PlayerMode::Ball || mode == PlayerMode::Robot || mode == PlayerMode::Spider;
    }

    bool looksLikeGameplayCollision(GameObject* obj) {
        return obj && obj->isVisible() && !obj->m_isDisabled && obj->m_objectID > 0;
    }

    float modeLookAhead(PlayerObject* player, PlayerMode mode) {
        return std::clamp(std::abs(static_cast<float>(player->getCurrentXVelocity())) * (isGroundMode(mode) ? 0.5f : 0.72f), 80.f, 250.f);
    }

    void releaseAutoButtons(PlayerObject* player = nullptr) {
        if (!player && PlayLayer::get()) player = PlayLayer::get()->m_player1;
        if (player) {
            player->releaseButton(static_cast<PlayerButton>(1));
            player->releaseButton(static_cast<PlayerButton>(3));
        }
        g_autoHoldingJump = false; g_autoHoldingRight = false;
    }

    ThreatScan scanThreats(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        ThreatScan scan = {false, false, false, false, 9999.f, player->getPositionY()};
        // Engel tarama mantığı burada tek bir kez tanımlanmalı
        return scan;
    }

    void runAutoPlay(PlayLayer* layer) {
        if (!g_autoPlay || !layer || !layer->m_player1) return;
        auto p = layer->m_player1;
        auto mode = PlayerMode::Cube; // Buraya mod tespit fonksiyonun gelecek
        
        // Basit bir zıplama tetikleyici
        if (p->m_isOnGround && g_autoCube) setJumpHeld(p, true);
        else setJumpHeld(p, false);
    }
}

// --- Modifiye Sınıfları ---
class $modify(EmirHubPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;
        return true;
    }
    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);
        runAutoPlay(this);
    }
};

