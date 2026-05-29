#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include <algorithm>
#include <cmath>
#include <vector>

using namespace geode::prelude;
using namespace cocos2d;

namespace {
    constexpr auto kJumpButton = static_cast<PlayerButton>(1);
    constexpr auto kRightButton = static_cast<PlayerButton>(3);

    struct AutoInputState {
        bool jumpHeld = false;
        bool rightHeld = false;
        int tapFrames = 0;
        int tapCooldown = 0;
    };

    enum class PlayerMode {
        Cube,
        Ship,
        Ball,
        Ufo,
        Wave,
        Robot,
        Spider,
        Swing,
        Unknown
    };

    struct ThreatScan {
        bool obstacleAhead = false;
        bool obstacleAbove = false;
        bool obstacleBelow = false;
        bool wallAhead = false;
        float closestX = 9999.f;
        float targetY = 0.f;
        bool hasTargetY = false;
    };

    AutoInputState g_player1Input;
    AutoInputState g_player2Input;

    void setJumpHeld(PlayerObject* player, AutoInputState& input, bool held) {
        if (!player || input.jumpHeld == held) {
            return;
        }

        if (held) {
            player->pushButton(kJumpButton);
        } else {
            player->releaseButton(kJumpButton);
        }
        input.jumpHeld = held;
    }

    void setRightHeld(PlayerObject* player, AutoInputState& input, bool held) {
        if (!player || input.rightHeld == held) {
            return;
        }

        if (held) {
            player->pushButton(kRightButton);
        } else {
            player->releaseButton(kRightButton);
        }
        input.rightHeld = held;
    }

    void releaseAutoInput(PlayerObject* player, AutoInputState& input) {
        if (player) {
            setJumpHeld(player, input, false);
            setRightHeld(player, input, false);
        }
        input = {};
    }

    void releaseAllAutoInputs(PlayLayer* layer = nullptr) {
        if (!layer) {
            layer = PlayLayer::get();
        }

        releaseAutoInput(layer ? layer->m_player1 : nullptr, g_player1Input);
        releaseAutoInput(layer ? layer->m_player2 : nullptr, g_player2Input);
    }

    void startJumpTap(PlayerObject* player, AutoInputState& input, int frames, int cooldown) {
        if (!player || input.tapCooldown > 0) {
            return;
        }

        input.tapFrames = std::max(frames, 1);
        input.tapCooldown = std::max(cooldown, input.tapFrames + 1);
        setJumpHeld(player, input, true);
    }

    bool updateJumpTap(PlayerObject* player, AutoInputState& input) {
        if (input.tapCooldown > 0) {
            --input.tapCooldown;
        }

        if (input.tapFrames <= 0) {
            return false;
        }

        --input.tapFrames;
        setJumpHeld(player, input, true);
        if (input.tapFrames == 0) {
            setJumpHeld(player, input, false);
        }
        return true;
    }

    PlayerMode currentPlayerMode(PlayerObject* player) {
        if (!player) {
            return PlayerMode::Unknown;
        }
        if (player->m_isDart) {
            return PlayerMode::Wave;
        }
        if (player->m_isShip) {
            return PlayerMode::Ship;
        }
        if (player->m_isBird) {
            return PlayerMode::Ufo;
        }
        if (player->m_isSwing) {
            return PlayerMode::Swing;
        }
        if (player->m_isBall) {
            return PlayerMode::Ball;
        }
        if (player->m_isRobot) {
            return PlayerMode::Robot;
        }
        if (player->m_isSpider) {
            return PlayerMode::Spider;
        }
        if (player->isInNormalMode() || player->isInBasicMode()) {
            return PlayerMode::Cube;
        }
        return PlayerMode::Unknown;
    }

    bool isGroundMode(PlayerMode mode) {
        return mode == PlayerMode::Cube || mode == PlayerMode::Ball || mode == PlayerMode::Robot || mode == PlayerMode::Spider;
    }

    CCRect expandedRect(GameObject* object, float paddingX, float paddingY) {
        auto rect = object->getObjectRect();
        rect.origin.x -= paddingX;
        rect.origin.y -= paddingY;
        rect.size.width += paddingX * 2.f;
        rect.size.height += paddingY * 2.f;
        return rect;
    }

    bool looksLikeSolidHazard(GameObject* object) {
        if (!object || !object->isVisible()) {
            return false;
        }
        if (object->m_isDisabled || object->m_isGroupDisabled || object->m_isTrigger) {
            return false;
        }
        if (object->m_isDecoration || object->m_isDecoration2 || object->m_isPassable || object->m_isNoTouch || object->m_isInvisible) {
            return false;
        }
        return object->m_objectID > 0;
    }

    float modeLookAhead(PlayerObject* player, PlayerMode mode) {
        auto speed = player ? std::abs(static_cast<float>(player->getCurrentXVelocity())) : 0.f;
        auto base = isGroundMode(mode) ? 0.62f : 0.82f;
        auto minLook = isGroundMode(mode) ? 95.f : 140.f;
        auto maxLook = isGroundMode(mode) ? 195.f : 275.f;
        return std::clamp(speed * base, minLook, maxLook);
    }

    std::vector<GameObject*> collectNearbyObjects(PlayLayer* layer, PlayerObject* player, float lookAhead, float verticalRange) {
        std::vector<GameObject*> objects;
        if (!layer || !player || !layer->m_objectLayer) {
            return objects;
        }

        auto playerPos = player->getPosition();
        for (auto node : layer->m_objectLayer->getChildrenExt()) {
            auto object = typeinfo_cast<GameObject*>(node);
            if (!looksLikeSolidHazard(object)) {
                continue;
            }

            auto objectPos = object->getPosition();
            auto dx = objectPos.x - playerPos.x;
            if (dx < -65.f || dx > lookAhead) {
                continue;
            }
            if (std::abs(objectPos.y - playerPos.y) > verticalRange) {
                continue;
            }
            objects.push_back(object);
        }
        return objects;
    }

    ThreatScan scanThreats(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        ThreatScan scan;
        if (!layer || !player) {
            return scan;
        }

        auto playerPos = player->getPosition();
        auto playerRect = player->getObjectRect();
        auto lookAhead = modeLookAhead(player, mode);
        auto targetY = playerPos.y;

        for (auto object : collectNearbyObjects(layer, player, lookAhead, isGroundMode(mode) ? 260.f : 380.f)) {
            auto rect = expandedRect(object, isGroundMode(mode) ? 14.f : 22.f, isGroundMode(mode) ? 12.f : 22.f);
            if (rect.getMaxX() < playerPos.x - 18.f || rect.getMinX() > playerPos.x + lookAhead) {
                continue;
            }

            auto closeX = std::max(0.f, rect.getMinX() - playerRect.getMaxX());
            auto verticalOverlap = rect.getMaxY() > playerRect.getMinY() - 22.f && rect.getMinY() < playerRect.getMaxY() + 36.f;
            if (verticalOverlap) {
                scan.obstacleAhead = true;
                scan.closestX = std::min(scan.closestX, closeX);
            }

            auto centerY = rect.getMidY();
            if (centerY > playerPos.y + 16.f) {
                scan.obstacleAbove = true;
                targetY = std::min(targetY, rect.getMinY() - 68.f);
                scan.hasTargetY = true;
            } else if (centerY < playerPos.y - 16.f) {
                scan.obstacleBelow = true;
                targetY = std::max(targetY, rect.getMaxY() + 68.f);
                scan.hasTargetY = true;
            } else {
                scan.wallAhead = true;
                targetY += player->m_isUpsideDown ? -76.f : 76.f;
                scan.hasTargetY = true;
            }

            if (verticalOverlap && rect.size.height > playerRect.size.height * 1.10f && closeX < 80.f) {
                scan.wallAhead = true;
            }
        }

        scan.targetY = targetY;
        return scan;
    }

    bool shouldGroundJump(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto scan = scanThreats(layer, player, mode);
        if (!scan.obstacleAhead && !scan.wallAhead) {
            return false;
        }

        auto grounded = player->m_isOnGround || player->m_lastGroundObject || player->m_objectSnappedTo;
        auto yVelocity = player->getYVelocity();
        auto nearEnough = scan.closestX < (mode == PlayerMode::Robot ? 142.f : 112.f);

        if (mode == PlayerMode::Ball || mode == PlayerMode::Spider) {
            return grounded && nearEnough;
        }
        if (mode == PlayerMode::Robot) {
            return nearEnough && (grounded || (player->m_isUpsideDown ? yVelocity > 0.5 : yVelocity < -0.5));
        }
        return nearEnough && grounded;
    }

    bool shouldFlightHold(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto scan = scanThreats(layer, player, mode);
        auto playerPos = player->getPosition();
        auto yVelocity = player->getYVelocity();

        auto softTop = playerPos.y + 170.f;
        auto softBottom = playerPos.y - 170.f;
        if (layer && layer->m_objectLayer) {
            auto winSize = CCDirector::sharedDirector()->getWinSize();
            softTop = layer->m_objectLayer->convertToNodeSpace({ 0.f, winSize.height - 50.f }).y;
            softBottom = layer->m_objectLayer->convertToNodeSpace({ 0.f, 54.f }).y;
        }

        if (playerPos.y < softBottom || scan.obstacleBelow || scan.wallAhead) {
            return !player->m_isUpsideDown;
        }
        if (playerPos.y > softTop || scan.obstacleAbove) {
            return player->m_isUpsideDown;
        }
        if (scan.hasTargetY && std::abs(scan.targetY - playerPos.y) > 18.f) {
            return (scan.targetY > playerPos.y) != player->m_isUpsideDown;
        }

        return player->m_isUpsideDown ? yVelocity > 1.75 : yVelocity < -1.75;
    }

    bool shouldTapFlight(PlayLayer* layer, PlayerObject* player, PlayerMode mode, AutoInputState& input) {
        auto wantsLift = shouldFlightHold(layer, player, mode);
        auto scan = scanThreats(layer, player, mode);
        auto fallingHard = player->m_isUpsideDown ? player->getYVelocity() > 4.0 : player->getYVelocity() < -4.0;
        auto urgent = scan.obstacleBelow || scan.wallAhead || fallingHard;
        return wantsLift && (urgent || input.tapCooldown == 0);
    }

    void runAutoForPlayer(PlayLayer* layer, PlayerObject* player, AutoInputState& input) {
        if (!layer || !player || !layer->isGameplayActive()) {
            releaseAutoInput(player, input);
            return;
        }

        auto mode = currentPlayerMode(player);
        setRightHeld(player, input, true);

        if (updateJumpTap(player, input)) {
            return;
        }

        if (isGroundMode(mode)) {
            auto wantsJump = shouldGroundJump(layer, player, mode);
            if (mode == PlayerMode::Ball || mode == PlayerMode::Spider) {
                if (wantsJump) {
                    startJumpTap(player, input, 1, mode == PlayerMode::Spider ? 9 : 7);
                } else {
                    setJumpHeld(player, input, false);
                }
                return;
            }

            setJumpHeld(player, input, wantsJump);
            return;
        }

        if (mode == PlayerMode::Ufo || mode == PlayerMode::Swing) {
            if (shouldTapFlight(layer, player, mode, input)) {
                startJumpTap(player, input, 2, mode == PlayerMode::Ufo ? 10 : 8);
            } else {
                setJumpHeld(player, input, false);
            }
            return;
        }

        setJumpHeld(player, input, shouldFlightHold(layer, player, mode));
    }

    void runAutoPlay(PlayLayer* layer) {
        if (!layer || !layer->isGameplayActive()) {
            releaseAllAutoInputs(layer);
            return;
        }

        runAutoForPlayer(layer, layer->m_player1, g_player1Input);
        runAutoForPlayer(layer, layer->m_player2, g_player2Input);
    }
}

class $modify(AutoPlayOnlyLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        releaseAllAutoInputs(this);
        return true;
    }

    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);
        runAutoPlay(this);
    }

    void resetLevel() {
        releaseAllAutoInputs(this);
        PlayLayer::resetLevel();
    }

    void onQuit() {
        releaseAllAutoInputs(this);
        PlayLayer::onQuit();
    }
};
