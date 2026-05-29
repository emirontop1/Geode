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

    std::vector<CCRect> collectDangerRects(PlayLayer* layer, PlayerObject* player, PlayerMode mode, float lookAhead) {
        std::vector<CCRect> rects;
        auto padX = isGroundMode(mode) ? 18.f : 26.f;
        auto padY = isGroundMode(mode) ? 16.f : 26.f;
        for (auto object : collectNearbyObjects(layer, player, lookAhead, isGroundMode(mode) ? 320.f : 520.f)) {
            rects.push_back(expandedRect(object, padX, padY));
        }
        return rects;
    }

    bool pointHitsDanger(CCPoint point, std::vector<CCRect> const& rects) {
        return std::any_of(rects.begin(), rects.end(), [point](CCRect const& rect) {
            return rect.containsPoint(point);
        });
    }

    CorridorSample findBestCorridor(PlayerObject* player, std::vector<CCRect> const& rects, float lookAhead) {
        CorridorSample best;
        if (!player) {
            return best;
        }

        auto origin = player->getPosition();
        auto minY = origin.y - 210.f;
        auto maxY = origin.y + 210.f;
        auto xStep = std::max(28.f, lookAhead / 7.f);

        for (auto x = origin.x + 46.f; x <= origin.x + lookAhead; x += xStep) {
            std::vector<CCRect> blockers;
            for (auto const& rect : rects) {
                if (rect.getMinX() <= x && rect.getMaxX() >= x) {
                    blockers.push_back(rect);
                    minY = std::min(minY, rect.getMinY() - 70.f);
                    maxY = std::max(maxY, rect.getMaxY() + 70.f);
                }
            }

            for (auto y = minY; y <= maxY; y += 14.f) {
                auto clearance = std::numeric_limits<float>::max();
                auto blocked = false;
                for (auto const& rect : blockers) {
                    if (rect.containsPoint({ x, y })) {
                        blocked = true;
                        break;
                    }
                    auto dx = std::max({ rect.getMinX() - x, 0.f, x - rect.getMaxX() });
                    auto dy = std::max({ rect.getMinY() - y, 0.f, y - rect.getMaxY() });
                    clearance = std::min(clearance, std::sqrt(dx * dx + dy * dy));
                }
                if (blocked) {
                    continue;
                }

                auto centeredScore = clearance - std::abs(y - origin.y) * 0.08f;
                if (!best.foundGap || centeredScore > best.clearance) {
                    best.foundGap = true;
                    best.clearance = centeredScore;
                    best.targetY = y;
                }
            }
        }

        return best;
    }

    float simulatedVerticalAcceleration(PlayerMode mode, bool hold, bool upsideDown) {
        auto direction = upsideDown ? -1.f : 1.f;
        switch (mode) {
            case PlayerMode::Wave:
                return hold ? 0.f : 0.f;
            case PlayerMode::Ship:
                return (hold ? 0.72f : -0.64f) * direction;
            case PlayerMode::Swing:
                return (hold ? 0.84f : -0.72f) * direction;
            case PlayerMode::Ufo:
                return -0.58f * direction;
            default:
                return (hold ? 0.62f : -0.56f) * direction;
        }
    }

    float simulatedVerticalVelocity(PlayerMode mode, float currentVelocity, bool hold, bool upsideDown, int step) {
        if (mode == PlayerMode::Wave) {
            auto waveSpeed = 6.9f * (upsideDown ? -1.f : 1.f);
            return hold ? waveSpeed : -waveSpeed;
        }

        auto velocity = currentVelocity + simulatedVerticalAcceleration(mode, hold, upsideDown) * static_cast<float>(step);
        auto limit = mode == PlayerMode::Ship ? 11.f : 10.f;
        return std::clamp(velocity, -limit, limit);
    }

    TrajectoryCandidate simulateTrajectory(PlayerObject* player, PlayerMode mode, std::vector<CCRect> const& rects, bool hold, float targetY) {
        TrajectoryCandidate candidate;
        candidate.hold = hold;
        if (!player) {
            return candidate;
        }

        auto pos = player->getPosition();
        auto xVelocity = std::max(5.2f, std::abs(static_cast<float>(player->getCurrentXVelocity())) / 60.f);
        auto yVelocity = static_cast<float>(player->getYVelocity());
        auto horizon = isContinuousFlightMode(mode) ? 54 : 34;
        auto survived = 0;
        auto minClearance = 9999.f;
        candidate.endPoint = pos;

        for (auto step = 1; step <= horizon; ++step) {
            auto vy = simulatedVerticalVelocity(mode, yVelocity, hold, player->m_isUpsideDown, step);
            pos.x += xVelocity;
            pos.y += vy;
            candidate.endPoint = pos;

            if (pointHitsDanger(pos, rects)) {
                candidate.firstHitX = pos.x;
                candidate.score -= 6000.f - static_cast<float>(step) * 80.f;
                break;
            }

            for (auto const& rect : rects) {
                auto dx = std::max({ rect.getMinX() - pos.x, 0.f, pos.x - rect.getMaxX() });
                auto dy = std::max({ rect.getMinY() - pos.y, 0.f, pos.y - rect.getMaxY() });
                minClearance = std::min(minClearance, std::sqrt(dx * dx + dy * dy));
            }
            survived = step;
        }

        candidate.score += static_cast<float>(survived) * 120.f;
        candidate.score += std::min(minClearance, 220.f) * 4.f;
        candidate.score -= std::abs(candidate.endPoint.y - targetY) * 1.8f;
        return candidate;
    }

    bool chooseSimulatedFlightHold(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto lookAhead = modeLookAhead(player, mode);
        auto rects = collectDangerRects(layer, player, mode, lookAhead);
        auto scan = scanThreats(layer, player, mode);
        auto corridor = findBestCorridor(player, rects, lookAhead);
        auto targetY = player->getPositionY();

        if (corridor.foundGap) {
            targetY = corridor.targetY;
        } else if (scan.hasTargetY) {
            targetY = scan.targetY;
        }

        auto hold = simulateTrajectory(player, mode, rects, true, targetY);
        auto release = simulateTrajectory(player, mode, rects, false, targetY);
        return hold.score >= release.score;
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
        rayNode->clear();

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
