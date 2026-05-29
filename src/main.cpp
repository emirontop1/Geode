#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

#include <array>
#include <algorithm>
#include <cmath>

using namespace geode::prelude;
using namespace cocos2d;

namespace {
    bool g_noclip = false;
    bool g_autoPlay = false;
    bool g_showHitbox = false;
    bool g_hidePlayer = false;
    bool g_platformer = false;

    bool g_holdJump = false;
    bool g_holdRight = false;

    int g_speedIndex = 2;

    constexpr std::array<float, 5> kSpeeds = {
        0.5f,
        0.75f,
        1.0f,
        1.5f,
        2.0f
    };

    float getSpeed() {
        return kSpeeds.at(
            std::clamp(g_speedIndex, 0, (int)kSpeeds.size() - 1)
        );
    }

    void toast(char const* text) {
        Notification::create(
            text,
            NotificationIcon::Info
        )->show();
    }

    void holdJump(PlayerObject* player, bool hold) {
        if (!player) return;

        if (hold == g_holdJump)
            return;

        if (hold) {
            player->pushButton(PlayerButton::Jump);
        }
        else {
            player->releaseButton(PlayerButton::Jump);
        }

        g_holdJump = hold;
    }

    void holdRight(PlayerObject* player, bool hold) {
        if (!player) return;

        if (hold == g_holdRight)
            return;

        if (hold) {
            player->pushButton(PlayerButton::Right);
        }
        else {
            player->releaseButton(PlayerButton::Right);
        }

        g_holdRight = hold;
    }

    bool shouldJump(PlayerObject* player) {
        if (!player)
            return false;

        auto yVel = player->getYVelocity();

        if (player->m_isOnGround && yVel <= 0.f)
            return true;

        return false;
    }

    void autoPlay(PlayLayer* pl) {
        if (!pl)
            return;

        auto player = pl->m_player1;

        if (!player)
            return;

        if (!g_autoPlay) {
            holdJump(player, false);
            holdRight(player, false);
            return;
        }

        if (g_platformer) {
            holdRight(player, true);
        }

        holdJump(player, shouldJump(player));
    }

    void applyVisuals(PlayLayer* pl) {
        if (!pl)
            return;

        pl->toggleIgnoreDamage(g_noclip);

        pl->updateTimeMod(
            getSpeed(),
            true,
            true
        );

        pl->togglePlayerVisibility(
            !g_hidePlayer
        );

        if (g_showHitbox) {
            pl->toggleDebugDraw();
        }
    }
}

class EmirMenu : public CCLayer {
protected:
    CCLayerColor* m_bg = nullptr;
    CCMenu* m_menu = nullptr;

    bool m_open = false;

public:
    static EmirMenu* create() {
        auto ret = new EmirMenu();

        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init())
            return false;

        this->setTouchEnabled(true);
        this->setKeypadEnabled(true);

        auto win = CCDirector::sharedDirector()->getWinSize();

        auto openSpr = ButtonSprite::create(
            "EH",
            80,
            true,
            "goldFont.fnt",
            "GJ_button_04.png",
            30.f,
            1.f
        );

        auto openBtn = CCMenuItemSpriteExtra::create(
            openSpr,
            this,
            menu_selector(EmirMenu::onOpen)
        );

        m_menu = CCMenu::create();
        m_menu->addChild(openBtn);

        m_menu->setPosition(
            {60.f, win.height / 2}
        );

        this->addChild(m_menu, 100);

        m_bg = CCLayerColor::create(
            {0, 0, 0, 150},
            320.f,
            260.f
        );

        m_bg->setPosition({
            win.width / 2 - 160.f,
            win.height / 2 - 130.f
        });

        m_bg->setVisible(false);

        this->addChild(m_bg, 99);

        createButtons();

        return true;
    }

    void createButtons() {
        auto menu = CCMenu::create();
        menu->setPosition(0, 0);

        m_bg->addChild(menu);

        createToggle(
            menu,
            "Noclip",
            {160.f, 220.f},
            menu_selector(EmirMenu::onNoclip)
        );

        createToggle(
            menu,
            "Autoplay",
            {160.f, 180.f},
            menu_selector(EmirMenu::onAutoPlay)
        );

        createToggle(
            menu,
            "Hitbox",
            {160.f, 140.f},
            menu_selector(EmirMenu::onHitbox)
        );

        createToggle(
            menu,
            "Hide Player",
            {160.f, 100.f},
            menu_selector(EmirMenu::onHidePlayer)
        );

        createToggle(
            menu,
            "Platformer",
            {160.f, 60.f},
            menu_selector(EmirMenu::onPlatformer)
        );

        auto speedBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                "Speed",
                100,
                true,
                "goldFont.fnt",
                "GJ_button_05.png",
                25.f,
                1.f
            ),
            this,
            menu_selector(EmirMenu::onSpeed)
        );

        speedBtn->setPosition({
            160.f,
            20.f
        });

        menu->addChild(speedBtn);
    }

    void createToggle(
        CCMenu* menu,
        char const* text,
        CCPoint pos,
        SEL_MenuHandler cb
    ) {
        auto btn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                text,
                140,
                true,
                "goldFont.fnt",
                "GJ_button_01.png",
                25.f,
                0.8f
            ),
            this,
            cb
        );

        btn->setPosition(pos);

        menu->addChild(btn);
    }

    void onOpen(CCObject*) {
        m_open = !m_open;

        m_bg->setVisible(m_open);
    }

    void onNoclip(CCObject*) {
        g_noclip = !g_noclip;

        toast(
            g_noclip ?
            "Noclip Enabled" :
            "Noclip Disabled"
        );
    }

    void onAutoPlay(CCObject*) {
        g_autoPlay = !g_autoPlay;

        toast(
            g_autoPlay ?
            "Autoplay Enabled" :
            "Autoplay Disabled"
        );
    }

    void onHitbox(CCObject*) {
        g_showHitbox = !g_showHitbox;

        toast(
            g_showHitbox ?
            "Hitbox Enabled" :
            "Hitbox Disabled"
        );
    }

    void onHidePlayer(CCObject*) {
        g_hidePlayer = !g_hidePlayer;

        toast(
            g_hidePlayer ?
            "Player Hidden" :
            "Player Visible"
        );
    }

    void onPlatformer(CCObject*) {
        g_platformer = !g_platformer;

        toast(
            g_platformer ?
            "Platformer Assist Enabled" :
            "Platformer Assist Disabled"
        );
    }

    void onSpeed(CCObject*) {
        g_speedIndex++;

        if (g_speedIndex >= (int)kSpeeds.size())
            g_speedIndex = 0;

        char buf[64];

        sprintf(
            buf,
            "Speed %.2fx",
            getSpeed()
        );

        toast(buf);
    }

    void registerWithTouchDispatcher() override {
        CCDirector::sharedDirector()
            ->getTouchDispatcher()
            ->addTargetedDelegate(
                this,
                -999,
                true
            );
    }
};

class $modify(MyPlayLayer, PlayLayer) {
    bool init(
        GJGameLevel* level,
        bool useReplay,
        bool dontCreateObjects
    ) {
        if (!PlayLayer::init(
            level,
            useReplay,
            dontCreateObjects
        )) {
            return false;
        }

        auto menu = EmirMenu::create();

        this->addChild(menu, 99999);

        toast("Emir Hub Loaded");

        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);

        applyVisuals(this);

        autoPlay(this);
    }

    void destroyPlayer(
        PlayerObject* player,
        GameObject* object
    ) {
        if (g_noclip)
            return;

        PlayLayer::destroyPlayer(
            player,
            object
        );
    }
};

$on_mod(Loaded) {
    log::info("Emir Hub Loaded");
}
