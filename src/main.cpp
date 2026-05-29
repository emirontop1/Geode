#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace geode::prelude;
using namespace cocos2d;
using namespace cocos2d::extension;

namespace {
    bool g_ignoreDamage = false;
    bool g_practiceMode = false;
    bool g_autoPlay = false;
    bool g_autoCube = true;
    bool g_autoWave = true;
    bool g_showHitboxes = false;
    bool g_platformerAssist = false;
    bool g_hidePlayer = false;
    bool g_hideGround = false;
    bool g_hideMG = false;
    bool g_hideAttempts = false;
    bool g_bgEffects = true;
    bool g_autoHoldingJump = false;
    bool g_autoHoldingRight = false;
    int g_autoTapFrames = 0;
    int g_autoTapCooldown = 0;
    int g_speedIndex = 2;

    constexpr std::array<float, 5> kSpeedValues = { 0.50f, 0.75f, 1.00f, 1.50f, 2.00f };

    enum class HubTab {
        Player,
        Assist,
        Visual,
        Utility
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
        float safeTargetY = 0.f;
    };

    constexpr auto kJumpButton = static_cast<PlayerButton>(1);
    constexpr auto kRightButton = static_cast<PlayerButton>(3);

    void showToast(char const* text) {
        if (auto notification = Notification::create(text)) {
            notification->show();
        }
    }

    bool nodeContainsWorldPoint(CCNode* node, CCPoint worldPoint) {
        if (!node || !node->isVisible()) {
            return false;
        }

        auto parent = node->getParent();
        auto localPoint = parent ? parent->convertToNodeSpace(worldPoint) : worldPoint;
        return node->boundingBox().containsPoint(localPoint);
    }

    CCLabelBMFont* makeLabel(char const* text, char const* font, float scale, CCPoint position, CCNode* parent, int zOrder = 1) {
        auto label = CCLabelBMFont::create(text, font);
        label->setScale(scale);
        label->setPosition(position);
        parent->addChild(label, zOrder);
        return label;
    }

    void updateHubToggleLabel(CCLabelBMFont* label, char const* name, bool enabled, ccColor3B onColor = { 100, 255, 125 }, ccColor3B offColor = { 255, 135, 135 }) {
        if (!label) {
            return;
        }

        char buffer[64];
        std::snprintf(buffer, sizeof(buffer), "%s: %s", name, enabled ? "ON" : "OFF");
        label->setString(buffer);
        label->setColor(enabled ? onColor : offColor);
    }

    float currentSpeed() {
        auto safeIndex = std::clamp(g_speedIndex, 0, static_cast<int>(kSpeedValues.size()) - 1);
        return kSpeedValues.at(safeIndex);
    }

    void setDebugDrawEnabled(PlayLayer* playLayer, bool enabled) {
        if (!playLayer) {
            return;
        }

        if (playLayer->shouldDebugDraw() != enabled) {
            playLayer->toggleDebugDraw();
        }
        playLayer->updateDebugDrawSettings();
    }

    void applyPlayLayerOptions(PlayLayer* playLayer) {
        if (!playLayer) {
            return;
        }

        playLayer->toggleIgnoreDamage(g_ignoreDamage);
        if (g_practiceMode) {
            playLayer->togglePracticeMode(true);
        }
        setDebugDrawEnabled(playLayer, g_showHitboxes);
        playLayer->updateTimeMod(currentSpeed(), true, true);
        playLayer->toggleHideAttempts(g_hideAttempts);
        playLayer->togglePlayerVisibility(!g_hidePlayer);
        playLayer->toggleGroundVisibility(!g_hideGround);
        playLayer->toggleMGVisibility(!g_hideMG);
        playLayer->toggleBGEffectVisibility(g_bgEffects);
    }

    void releaseAutoButtons(PlayerObject* player = nullptr) {
        if (!player) {
            if (auto playLayer = PlayLayer::get()) {
                player = playLayer->m_player1;
            }
        }

        if (!player) {
            g_autoHoldingJump = false;
            g_autoHoldingRight = false;
            g_autoTapFrames = 0;
            g_autoTapCooldown = 0;
            return;
        }

        if (g_autoHoldingJump) {
            player->releaseButton(kJumpButton);
            g_autoHoldingJump = false;
        }
        if (g_autoHoldingRight) {
            player->releaseButton(kRightButton);
            g_autoHoldingRight = false;
        }
        g_autoTapFrames = 0;
        g_autoTapCooldown = 0;
    }

    void setJumpHeld(PlayerObject* player, bool held) {
        if (!player || g_autoHoldingJump == held) {
            return;
        }

        if (held) {
            player->pushButton(kJumpButton);
        } else {
            player->releaseButton(kJumpButton);
        }
        g_autoHoldingJump = held;
    }

    void startJumpTap(PlayerObject* player, int frames = 2, int cooldown = 7) {
        if (!player || g_autoTapCooldown > 0) {
            return;
        }

        g_autoTapFrames = std::max(frames, 1);
        g_autoTapCooldown = std::max(cooldown, g_autoTapFrames + 1);
        setJumpHeld(player, true);
    }

    bool updateJumpTap(PlayerObject* player) {
        if (g_autoTapCooldown > 0) {
            --g_autoTapCooldown;
        }

        if (g_autoTapFrames <= 0) {
            return false;
        }

        --g_autoTapFrames;
        setJumpHeld(player, true);
        if (g_autoTapFrames == 0) {
            setJumpHeld(player, false);
        }
        return true;
    }

    void setRightHeld(PlayerObject* player, bool held) {
        if (!player || g_autoHoldingRight == held) {
            return;
        }

        if (held) {
            player->pushButton(kRightButton);
        } else {
            player->releaseButton(kRightButton);
        }
        g_autoHoldingRight = held;
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

    char const* modeName(PlayerMode mode) {
        switch (mode) {
            case PlayerMode::Cube: return "Cube";
            case PlayerMode::Ship: return "Ship";
            case PlayerMode::Ball: return "Ball";
            case PlayerMode::Ufo: return "UFO";
            case PlayerMode::Wave: return "Wave";
            case PlayerMode::Robot: return "Robot";
            case PlayerMode::Spider: return "Spider";
            case PlayerMode::Swing: return "Swing";
            case PlayerMode::Unknown: return "Auto";
        }
        return "Auto";
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

    bool looksLikeGameplayCollision(GameObject* object) {
        if (!object || !object->isVisible() || object->m_isDisabled || object->m_isGroupDisabled || object->m_isTrigger) {
            return false;
        }
        if (object->m_isDecoration || object->m_isDecoration2 || object->m_isPassable || object->m_isNoTouch || object->m_isInvisible) {
            return false;
        }
        return object->m_objectID > 0;
    }

    float modeLookAhead(PlayerObject* player, PlayerMode mode) {
        auto speed = std::abs(static_cast<float>(player->getCurrentXVelocity()));
        auto base = isGroundMode(mode) ? 0.50f : 0.72f;
        auto minLook = isGroundMode(mode) ? 86.f : 125.f;
        auto maxLook = isGroundMode(mode) ? 170.f : 245.f;
        return std::clamp(speed * base, minLook, maxLook);
    }

    std::vector<GameObject*> collectNearbyCollisionObjects(PlayLayer* layer, PlayerObject* player, float lookAhead, float verticalRange = 320.f) {
        std::vector<GameObject*> objects;
        if (!layer || !player || !layer->m_objectLayer) {
            return objects;
        }

        auto playerPos = player->getPosition();
        for (auto node : layer->m_objectLayer->getChildrenExt()) {
            auto object = typeinfo_cast<GameObject*>(node);
            if (!looksLikeGameplayCollision(object)) {
                continue;
            }

            auto objectPos = object->getPosition();
            auto dx = objectPos.x - playerPos.x;
            if (dx < -55.f || dx > lookAhead) {
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
        auto desiredY = playerPos.y;

        for (auto object : collectNearbyCollisionObjects(layer, player, lookAhead)) {
            auto rect = expandedRect(object, isGroundMode(mode) ? 12.f : 18.f, isGroundMode(mode) ? 10.f : 18.f);
            auto ahead = rect.getMaxX() > playerPos.x - 18.f && rect.getMinX() < playerPos.x + lookAhead;
            if (!ahead) {
                continue;
            }

            auto verticalOverlap = rect.getMaxY() > playerRect.getMinY() - 18.f && rect.getMinY() < playerRect.getMaxY() + 32.f;
            auto closeX = std::max(0.f, rect.getMinX() - playerRect.getMaxX());
            if (verticalOverlap) {
                scan.obstacleAhead = true;
                scan.closestX = std::min(scan.closestX, closeX);
            }

            auto objectCenterY = rect.getMidY();
            if (objectCenterY > playerPos.y + 12.f) {
                scan.obstacleAbove = true;
                desiredY = std::min(desiredY, rect.getMinY() - 62.f);
            } else if (objectCenterY < playerPos.y - 12.f) {
                scan.obstacleBelow = true;
                desiredY = std::max(desiredY, rect.getMaxY() + 62.f);
            } else {
                scan.wallAhead = true;
                desiredY += player->m_isUpsideDown ? -70.f : 70.f;
            }

            if (verticalOverlap && rect.size.height > playerRect.size.height * 1.10f && closeX < 70.f) {
                scan.wallAhead = true;
            }
        }

        scan.safeTargetY = desiredY;
        return scan;
    }

    bool shouldGroundJump(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto scan = scanThreats(layer, player, mode);
        if (!scan.obstacleAhead && !scan.wallAhead) {
            return false;
        }

        auto grounded = player->m_isOnGround || player->m_lastGroundObject || player->m_objectSnappedTo;
        auto yVelocity = player->getYVelocity();
        auto nearEnough = scan.closestX < (mode == PlayerMode::Robot ? 130.f : 102.f);

        if (mode == PlayerMode::Ball || mode == PlayerMode::Spider) {
            return grounded && nearEnough;
        }
        if (mode == PlayerMode::Robot) {
            return nearEnough && (grounded || (player->m_isUpsideDown ? yVelocity > 0.5 : yVelocity < -0.5));
        }
        return nearEnough && grounded;
    }

    bool shouldFlightHold(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto playerPos = player->getPosition();
        auto scan = scanThreats(layer, player, mode);
        auto winHeight = CCDirector::sharedDirector()->getWinSize().height;
        auto softTop = layer->m_objectLayer->convertToNodeSpace({ 0.f, winHeight - 48.f }).y;
        auto softBottom = layer->m_objectLayer->convertToNodeSpace({ 0.f, 52.f }).y;

        if (playerPos.y < softBottom || scan.obstacleBelow || scan.wallAhead) {
            return !player->m_isUpsideDown;
        }
        if (playerPos.y > softTop || scan.obstacleAbove) {
            return player->m_isUpsideDown;
        }
        if (scan.safeTargetY != 0.f && std::abs(scan.safeTargetY - playerPos.y) > 16.f) {
            return (scan.safeTargetY > playerPos.y) != player->m_isUpsideDown;
        }

        auto yVelocity = player->getYVelocity();
        return player->m_isUpsideDown ? yVelocity > 2.0 : yVelocity < -2.0;
    }

    bool shouldTapFlight(PlayLayer* layer, PlayerObject* player, PlayerMode mode) {
        auto wantsLift = shouldFlightHold(layer, player, mode);
        auto scan = scanThreats(layer, player, mode);
        auto urgent = scan.obstacleBelow || scan.wallAhead || player->getYVelocity() < -4.0;
        return wantsLift && (urgent || g_autoTapCooldown == 0);
    }

    void runAutoPlay(PlayLayer* layer) {
        auto player = layer ? layer->m_player1 : nullptr;
        if (!layer || !player || !layer->isGameplayActive() || !g_autoPlay) {
            releaseAutoButtons(player);
            return;
        }

        auto mode = currentPlayerMode(player);

        if (g_platformerAssist) {
            setRightHeld(player, true);
        } else {
            setRightHeld(player, false);
        }

        if (updateJumpTap(player)) {
            return;
        }

        if (isGroundMode(mode) && g_autoCube) {
            auto wantsJump = shouldGroundJump(layer, player, mode);
            if (mode == PlayerMode::Ball || mode == PlayerMode::Spider) {
                if (wantsJump) {
                    startJumpTap(player, 1, mode == PlayerMode::Spider ? 9 : 7);
                } else {
                    setJumpHeld(player, false);
                }
                return;
            }

            setJumpHeld(player, wantsJump);
            return;
        }

        if (!isGroundMode(mode) && g_autoWave) {
            if (mode == PlayerMode::Ufo || mode == PlayerMode::Swing) {
                if (shouldTapFlight(layer, player, mode)) {
                    startJumpTap(player, 2, mode == PlayerMode::Ufo ? 10 : 8);
                } else {
                    setJumpHeld(player, false);
                }
                return;
            }

            setJumpHeld(player, shouldFlightHold(layer, player, mode));
            return;
        }

        setJumpHeld(player, false);
    }
}

class ModernMenu : public CCLayer {
protected:
    CCNode* m_floatButton = nullptr;
    CCLayerColor* m_panel = nullptr;
    CCScale9Sprite* m_background = nullptr;
    CCLabelBMFont* m_statusLabel = nullptr;
    CCLabelBMFont* m_damageLabel = nullptr;
    CCLabelBMFont* m_practiceLabel = nullptr;
    CCLabelBMFont* m_autoPlayLabel = nullptr;
    CCLabelBMFont* m_cubeLabel = nullptr;
    CCLabelBMFont* m_waveLabel = nullptr;
    CCLabelBMFont* m_platformerLabel = nullptr;
    CCLabelBMFont* m_hitboxLabel = nullptr;
    CCLabelBMFont* m_hidePlayerLabel = nullptr;
    CCLabelBMFont* m_hideGroundLabel = nullptr;
    CCLabelBMFont* m_hideMGLabel = nullptr;
    CCLabelBMFont* m_hideAttemptsLabel = nullptr;
    CCLabelBMFont* m_bgEffectsLabel = nullptr;
    CCLabelBMFont* m_speedLabel = nullptr;
    CCLabelBMFont* m_tabTitleLabel = nullptr;
    CCNode* m_playerPage = nullptr;
    CCNode* m_assistPage = nullptr;
    CCNode* m_visualPage = nullptr;
    CCNode* m_utilityPage = nullptr;
    HubTab m_tab = HubTab::Assist;
    bool m_open = false;
    bool m_dragging = false;
    bool m_movedTouch = false;
    CCPoint m_dragOffset = CCPointZero;
    CCPoint m_touchStart = CCPointZero;

public:
    static ModernMenu* create() {
        auto ret = new ModernMenu();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init()) {
            return false;
        }

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        this->setTouchEnabled(true);
        this->setKeypadEnabled(true);
        this->setID("emir-hub-layer"_spr);

        m_floatButton = ButtonSprite::create("EH", 44, true, "goldFont.fnt", "GJ_button_04.png", 28.f, 0.65f);
        m_floatButton->setPosition({ 62.f, winSize.height * 0.58f });
        m_floatButton->setID("open-emir-hub"_spr);
        this->addChild(m_floatButton, 20);

        this->createPanel(winSize);
        this->switchTab(HubTab::Assist);
        this->syncStateLabels();
        this->schedule(schedule_selector(ModernMenu::tickStatus), 0.20f);
        return true;
    }

    void registerWithTouchDispatcher() override {
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, true);
    }

    bool ccTouchBegan(CCTouch* touch, CCEvent*) override {
        auto worldPoint = touch->getLocation();
        m_touchStart = worldPoint;
        m_movedTouch = false;

        if (nodeContainsWorldPoint(m_floatButton, worldPoint)) {
            m_dragging = true;
            m_dragOffset = m_floatButton->getPosition() - this->convertToNodeSpace(worldPoint);
            return true;
        }

        if (m_open && nodeContainsWorldPoint(m_panel, worldPoint)) {
            return true;
        }

        return false;
    }

    void ccTouchMoved(CCTouch* touch, CCEvent*) override {
        if (!m_dragging) {
            return;
        }

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto worldPoint = touch->getLocation();
        if (worldPoint.getDistance(m_touchStart) > 6.f) {
            m_movedTouch = true;
        }

        auto nextPosition = this->convertToNodeSpace(worldPoint) + m_dragOffset;
        nextPosition.x = std::clamp(nextPosition.x, 28.f, winSize.width - 28.f);
        nextPosition.y = std::clamp(nextPosition.y, 28.f, winSize.height - 28.f);
        m_floatButton->setPosition(nextPosition);
    }

    void ccTouchEnded(CCTouch*, CCEvent*) override {
        if (m_dragging && !m_movedTouch) {
            this->togglePanel();
        }
        m_dragging = false;
        m_movedTouch = false;
    }

    void ccTouchCancelled(CCTouch*, CCEvent*) override {
        m_dragging = false;
        m_movedTouch = false;
    }

    void keyBackClicked() override {
        if (m_open) {
            this->closePanel();
            return;
        }
        CCLayer::keyBackClicked();
    }

private:
    void createPanel(CCSize winSize) {
        m_panel = CCLayerColor::create({ 0, 0, 0, 0 }, 332.f, 252.f);
        m_panel->setPosition({ winSize.width / 2.f - 166.f, winSize.height / 2.f - 126.f });
        m_panel->setScale(0.86f);
        m_panel->setOpacity(0);
        m_panel->setVisible(false);
        m_panel->setID("emir-hub-panel"_spr);
        this->addChild(m_panel, 15);

        m_background = CCScale9Sprite::create("GJ_square01.png");
        m_background->setContentSize({ 332.f, 252.f });
        m_background->setPosition({ 166.f, 126.f });
        m_background->setColor({ 16, 20, 34 });
        m_background->setOpacity(246);
        m_panel->addChild(m_background);

        auto glow = CCLayerColor::create({ 57, 172, 255, 50 }, 320.f, 36.f);
        glow->setPosition({ 6.f, 210.f });
        m_panel->addChild(glow, 1);

        makeLabel("Emir Hub", "goldFont.fnt", 0.76f, { 166.f, 228.f }, m_panel, 2);
        m_tabTitleLabel = makeLabel("Assist Suite", "bigFont.fnt", 0.32f, { 166.f, 207.f }, m_panel, 2);
        m_tabTitleLabel->setColor({ 165, 210, 255 });

        this->addTabButton("Player", { 49.f, 184.f }, HubTab::Player, "player-tab"_spr);
        this->addTabButton("Assist", { 127.f, 184.f }, HubTab::Assist, "assist-tab"_spr);
        this->addTabButton("Visual", { 205.f, 184.f }, HubTab::Visual, "visual-tab"_spr);
        this->addTabButton("Utils", { 283.f, 184.f }, HubTab::Utility, "utility-tab"_spr);

        m_playerPage = CCNode::create();
        m_assistPage = CCNode::create();
        m_visualPage = CCNode::create();
        m_utilityPage = CCNode::create();
        m_panel->addChild(m_playerPage, 3);
        m_panel->addChild(m_assistPage, 3);
        m_panel->addChild(m_visualPage, 3);
        m_panel->addChild(m_utilityPage, 3);

        m_damageLabel = this->addActionButton(m_playerPage, "No Death", { 73.f, 135.f }, menu_selector(ModernMenu::onToggleDamage), "damage-toggle"_spr);
        m_practiceLabel = this->addActionButton(m_playerPage, "Practice", { 166.f, 135.f }, menu_selector(ModernMenu::onTogglePractice), "practice-toggle"_spr);
        m_hidePlayerLabel = this->addActionButton(m_playerPage, "Hide P1", { 259.f, 135.f }, menu_selector(ModernMenu::onToggleHidePlayer), "hide-player"_spr);
        m_hideAttemptsLabel = this->addActionButton(m_playerPage, "Attempts", { 73.f, 82.f }, menu_selector(ModernMenu::onToggleHideAttempts), "hide-attempts"_spr);
        this->addActionButton(m_playerPage, "Progress", { 166.f, 82.f }, menu_selector(ModernMenu::onProgressbar), "progress-toggle"_spr);
        this->addActionButton(m_playerPage, "Info", { 259.f, 82.f }, menu_selector(ModernMenu::onInfoLabel), "info-toggle"_spr);

        m_autoPlayLabel = this->addActionButton(m_assistPage, "Auto Play", { 73.f, 135.f }, menu_selector(ModernMenu::onToggleAutoPlay), "autoplay-toggle"_spr);
        m_cubeLabel = this->addActionButton(m_assistPage, "Ground AI", { 166.f, 135.f }, menu_selector(ModernMenu::onToggleCube), "cube-toggle"_spr);
        m_waveLabel = this->addActionButton(m_assistPage, "Air AI", { 259.f, 135.f }, menu_selector(ModernMenu::onToggleWave), "wave-toggle"_spr);
        m_platformerLabel = this->addActionButton(m_assistPage, "Platform", { 73.f, 82.f }, menu_selector(ModernMenu::onTogglePlatformer), "platform-toggle"_spr);
        this->addActionButton(m_assistPage, "Auto All", { 166.f, 82.f }, menu_selector(ModernMenu::onAutoAll), "auto-all"_spr);
        this->addActionButton(m_assistPage, "Release", { 259.f, 82.f }, menu_selector(ModernMenu::onReleaseInputs), "release-inputs"_spr);

        m_hitboxLabel = this->addActionButton(m_visualPage, "Hitboxes", { 73.f, 135.f }, menu_selector(ModernMenu::onToggleHitboxes), "hitbox-toggle"_spr);
        m_hideGroundLabel = this->addActionButton(m_visualPage, "Ground", { 166.f, 135.f }, menu_selector(ModernMenu::onToggleHideGround), "hide-ground"_spr);
        m_hideMGLabel = this->addActionButton(m_visualPage, "MG", { 259.f, 135.f }, menu_selector(ModernMenu::onToggleHideMG), "hide-mg"_spr);
        m_bgEffectsLabel = this->addActionButton(m_visualPage, "BG FX", { 73.f, 82.f }, menu_selector(ModernMenu::onToggleBGEffects), "bg-effects"_spr);
        this->addActionButton(m_visualPage, "Debug", { 166.f, 82.f }, menu_selector(ModernMenu::onDebugPulse), "debug-pulse"_spr);
        this->addActionButton(m_visualPage, "Glitter", { 259.f, 82.f }, menu_selector(ModernMenu::onGlitter), "glitter-toggle"_spr);

        m_speedLabel = this->addActionButton(m_utilityPage, "Speed", { 73.f, 135.f }, menu_selector(ModernMenu::onSpeedUp), "speed-up"_spr);
        this->addActionButton(m_utilityPage, "Slower", { 166.f, 135.f }, menu_selector(ModernMenu::onSpeedDown), "speed-down"_spr);
        this->addActionButton(m_utilityPage, "Normal", { 259.f, 135.f }, menu_selector(ModernMenu::onSpeedNormal), "speed-normal"_spr);
        this->addActionButton(m_utilityPage, "Restart", { 73.f, 82.f }, menu_selector(ModernMenu::onRestart), "restart-level"_spr);
        this->addActionButton(m_utilityPage, "Clear CP", { 166.f, 82.f }, menu_selector(ModernMenu::onClearCheckpoints), "clear-checkpoints"_spr);
        this->addActionButton(m_utilityPage, "About", { 259.f, 82.f }, menu_selector(ModernMenu::onAbout), "about-menu"_spr);

        m_statusLabel = makeLabel("Ready", "chatFont.fnt", 0.52f, { 166.f, 20.f }, m_panel, 2);
        m_statusLabel->setColor({ 170, 240, 170 });
    }

    void addTabButton(char const* text, CCPoint position, HubTab tab, char const* nodeID) {
        auto menu = CCMenu::create();
        menu->setPosition(CCPointZero);
        m_panel->addChild(menu, 4);

        auto sprite = ButtonSprite::create(text, 70, true, "bigFont.fnt", "GJ_button_05.png", 21.f, 0.34f);
        auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(ModernMenu::onTabButton));
        button->setPosition(position);
        button->setTag(static_cast<int>(tab));
        button->setID(nodeID);
        menu->addChild(button);
    }

    CCLabelBMFont* addActionButton(CCNode* page, char const* text, CCPoint position, SEL_MenuHandler callback, char const* nodeID) {
        auto menu = CCMenu::create();
        menu->setPosition(CCPointZero);
        page->addChild(menu, 3);

        auto sprite = ButtonSprite::create(text, 82, true, "bigFont.fnt", "GJ_button_01.png", 24.f, 0.34f);
        auto button = CCMenuItemSpriteExtra::create(sprite, this, callback);
        button->setPosition(position);
        button->setID(nodeID);
        menu->addChild(button);

        auto label = CCLabelBMFont::create(text, "bigFont.fnt");
        label->setScale(0.28f);
        label->setPosition(position + CCPoint { 0.f, -22.f });
        label->setOpacity(225);
        page->addChild(label, 2);
        return label;
    }

    void togglePanel() {
        if (m_open) {
            this->closePanel();
        } else {
            this->openPanel();
        }
    }

    void openPanel() {
        m_open = true;
        m_panel->stopAllActions();
        m_panel->setVisible(true);
        m_panel->runAction(CCEaseBackOut::create(CCScaleTo::create(0.18f, 1.f)));
        m_panel->runAction(CCFadeTo::create(0.12f, 255));
        this->syncStateLabels();
    }

    void closePanel() {
        m_open = false;
        m_panel->stopAllActions();
        m_panel->runAction(CCSequence::create(
            CCSpawn::create(CCScaleTo::create(0.12f, 0.86f), CCFadeTo::create(0.12f, 0), nullptr),
            CCHide::create(),
            nullptr
        ));
    }

    void switchTab(HubTab tab) {
        m_tab = tab;
        if (m_playerPage) {
            m_playerPage->setVisible(tab == HubTab::Player);
        }
        if (m_assistPage) {
            m_assistPage->setVisible(tab == HubTab::Assist);
        }
        if (m_visualPage) {
            m_visualPage->setVisible(tab == HubTab::Visual);
        }
        if (m_utilityPage) {
            m_utilityPage->setVisible(tab == HubTab::Utility);
        }
        if (m_tabTitleLabel) {
            switch (tab) {
                case HubTab::Player:
                    m_tabTitleLabel->setString("Player Controls");
                    break;
                case HubTab::Assist:
                    m_tabTitleLabel->setString("Assist Suite");
                    break;
                case HubTab::Visual:
                    m_tabTitleLabel->setString("Visual Tools");
                    break;
                case HubTab::Utility:
                    m_tabTitleLabel->setString("Utility Deck");
                    break;
            }
        }
    }

    void syncStateLabels() {
        updateHubToggleLabel(m_damageLabel, "No Death", g_ignoreDamage);
        updateHubToggleLabel(m_practiceLabel, "Practice", g_practiceMode, { 100, 255, 125 }, { 255, 220, 120 });
        updateHubToggleLabel(m_autoPlayLabel, "Auto Play", g_autoPlay, { 100, 255, 125 }, { 255, 135, 135 });
        updateHubToggleLabel(m_cubeLabel, "Ground AI", g_autoCube, { 100, 255, 125 }, { 255, 220, 120 });
        updateHubToggleLabel(m_waveLabel, "Air AI", g_autoWave, { 100, 255, 125 }, { 255, 220, 120 });
        updateHubToggleLabel(m_platformerLabel, "Platform", g_platformerAssist, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_hitboxLabel, "Hitboxes", g_showHitboxes, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_hidePlayerLabel, "Hide P1", g_hidePlayer, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_hideGroundLabel, "Ground", g_hideGround, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_hideMGLabel, "MG", g_hideMG, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_hideAttemptsLabel, "Attempts", g_hideAttempts, { 100, 255, 125 }, { 185, 190, 255 });
        updateHubToggleLabel(m_bgEffectsLabel, "BG FX", g_bgEffects, { 100, 255, 125 }, { 255, 135, 135 });
        if (m_speedLabel) {
            char buffer[64];
            std::snprintf(buffer, sizeof(buffer), "Speed: %.2fx", currentSpeed());
            m_speedLabel->setString(buffer);
            m_speedLabel->setColor(g_speedIndex == 2 ? ccColor3B { 185, 190, 255 } : ccColor3B { 100, 255, 125 });
        }
    }

    void tickStatus(float) {
        auto playLayer = PlayLayer::get();
        if (!m_statusLabel || !playLayer) {
            return;
        }

        auto percent = playLayer->getCurrentPercent();
        char buffer[128];
        std::snprintf(
            buffer,
            sizeof(buffer),
            "%.2f%% | %s %s %.2fx %s",
            percent,
            g_autoPlay ? modeName(currentPlayerMode(playLayer->m_player1)) : "Manual",
            g_showHitboxes ? "Hitbox" : "Clean",
            currentSpeed(),
            g_ignoreDamage ? "Safe" : "Live"
        );
        m_statusLabel->setString(buffer);
        this->syncStateLabels();
    }

    void applyGameplayOptions() {
        applyPlayLayerOptions(PlayLayer::get());
    }

    void onTabButton(CCObject* sender) {
        auto tab = static_cast<HubTab>(sender ? sender->getTag() : static_cast<int>(HubTab::Assist));
        this->switchTab(tab);
    }

    void onToggleDamage(CCObject*) {
        g_ignoreDamage = !g_ignoreDamage;
        this->applyGameplayOptions();
        this->syncStateLabels();
        showToast(g_ignoreDamage ? "No Death enabled" : "No Death disabled");
    }

    void onTogglePractice(CCObject*) {
        g_practiceMode = !g_practiceMode;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->togglePracticeMode(g_practiceMode);
        }
        this->syncStateLabels();
        showToast(g_practiceMode ? "Practice Mode enabled" : "Practice Mode disabled");
    }

    void onToggleAutoPlay(CCObject*) {
        g_autoPlay = !g_autoPlay;
        if (!g_autoPlay) {
            releaseAutoButtons();
        }
        this->syncStateLabels();
        showToast(g_autoPlay ? "Auto Play enabled" : "Auto Play disabled");
    }

    void onToggleCube(CCObject*) {
        g_autoCube = !g_autoCube;
        this->syncStateLabels();
        showToast(g_autoCube ? "Ground Auto enabled" : "Ground Auto disabled");
    }

    void onToggleWave(CCObject*) {
        g_autoWave = !g_autoWave;
        this->syncStateLabels();
        showToast(g_autoWave ? "Air Auto enabled" : "Air Auto disabled");
    }

    void onTogglePlatformer(CCObject*) {
        g_platformerAssist = !g_platformerAssist;
        if (!g_platformerAssist) {
            releaseAutoButtons();
        }
        this->syncStateLabels();
        showToast(g_platformerAssist ? "Platform assist enabled" : "Platform assist disabled");
    }

    void onAutoAll(CCObject*) {
        g_autoPlay = true;
        g_autoCube = true;
        g_autoWave = true;
        g_platformerAssist = true;
        this->applyGameplayOptions();
        this->syncStateLabels();
        showToast("Auto suite enabled");
    }

    void onReleaseInputs(CCObject*) {
        releaseAutoButtons();
        showToast("Auto inputs released");
    }

    void onToggleHidePlayer(CCObject*) {
        g_hidePlayer = !g_hidePlayer;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->togglePlayerVisibility(!g_hidePlayer);
        }
        this->syncStateLabels();
        showToast(g_hidePlayer ? "Player hidden" : "Player visible");
    }

    void onToggleHideAttempts(CCObject*) {
        g_hideAttempts = !g_hideAttempts;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleHideAttempts(g_hideAttempts);
        }
        this->syncStateLabels();
        showToast(g_hideAttempts ? "Attempts hidden" : "Attempts visible");
    }

    void onToggleHideGround(CCObject*) {
        g_hideGround = !g_hideGround;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleGroundVisibility(!g_hideGround);
        }
        this->syncStateLabels();
        showToast(g_hideGround ? "Ground hidden" : "Ground visible");
    }

    void onToggleHideMG(CCObject*) {
        g_hideMG = !g_hideMG;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleMGVisibility(!g_hideMG);
        }
        this->syncStateLabels();
        showToast(g_hideMG ? "Middleground hidden" : "Middleground visible");
    }

    void onToggleBGEffects(CCObject*) {
        g_bgEffects = !g_bgEffects;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleBGEffectVisibility(g_bgEffects);
        }
        this->syncStateLabels();
        showToast(g_bgEffects ? "BG effects enabled" : "BG effects disabled");
    }

    void onToggleHitboxes(CCObject*) {
        g_showHitboxes = !g_showHitboxes;
        if (auto playLayer = PlayLayer::get()) {
            setDebugDrawEnabled(playLayer, g_showHitboxes);
        }
        this->syncStateLabels();
        showToast(g_showHitboxes ? "Hitboxes enabled" : "Hitboxes disabled");
    }

    void onProgressbar(CCObject*) {
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleProgressbar();
            showToast("Progress bar toggled");
        }
    }

    void onInfoLabel(CCObject*) {
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleInfoLabel();
            showToast("Info label toggled");
        }
    }

    void onDebugPulse(CCObject*) {
        if (auto playLayer = PlayLayer::get()) {
            playLayer->updateDebugDrawSettings();
            showToast("Debug draw refreshed");
        }
    }

    void onGlitter(CCObject*) {
        if (auto playLayer = PlayLayer::get()) {
            playLayer->toggleGlitter(true);
            showToast("Glitter refreshed");
        }
    }

    void onSpeedUp(CCObject*) {
        g_speedIndex = std::min(g_speedIndex + 1, static_cast<int>(kSpeedValues.size()) - 1);
        if (auto playLayer = PlayLayer::get()) {
            playLayer->updateTimeMod(currentSpeed(), true, true);
        }
        this->syncStateLabels();
        showToast("Speed increased");
    }

    void onSpeedDown(CCObject*) {
        g_speedIndex = std::max(g_speedIndex - 1, 0);
        if (auto playLayer = PlayLayer::get()) {
            playLayer->updateTimeMod(currentSpeed(), true, true);
        }
        this->syncStateLabels();
        showToast("Speed decreased");
    }

    void onSpeedNormal(CCObject*) {
        g_speedIndex = 2;
        if (auto playLayer = PlayLayer::get()) {
            playLayer->updateTimeMod(currentSpeed(), true, true);
        }
        this->syncStateLabels();
        showToast("Speed reset");
    }

    void onClearCheckpoints(CCObject*) {
        if (auto playLayer = PlayLayer::get()) {
            playLayer->removeAllCheckpoints();
            showToast("Checkpoints cleared");
        }
    }

    void onRestart(CCObject*) {
        releaseAutoButtons();
        if (auto playLayer = PlayLayer::get()) {
            playLayer->resetLevelFromStart();
            this->applyGameplayOptions();
            showToast("Level restarted");
        }
    }

    void onAbout(CCObject*) {
        FLAlertLayer::create(
            "Emir Hub",
            "<cg>Emir Hub</c> is an all-in-one playtest hub with tabs for Player, Assist, Visual and Utility tools.\n\n"
            "Includes No Death, Practice, Auto Play for cube, ship, ball, UFO, wave, robot, spider and swing, platform helpers, hitboxes, visibility toggles, speed control and checkpoint tools.",
            "OK"
        )->show();
    }
};

class $modify(EmirHubPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        if (auto menu = ModernMenu::create()) {
            this->addChild(menu, 9999);
        }

        applyPlayLayerOptions(this);
        return true;
    }

    void postUpdate(float dt) {
        PlayLayer::postUpdate(dt);
        runAutoPlay(this);
    }

    void resetLevel() {
        releaseAutoButtons(this->m_player1);
        PlayLayer::resetLevel();
        applyPlayLayerOptions(this);
    }

    void onQuit() {
        releaseAutoButtons(this->m_player1);
        PlayLayer::onQuit();
    }
};
