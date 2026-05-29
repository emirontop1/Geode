#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;
using namespace cocos2d;

namespace {
    bool g_noclip = false;
    bool g_autoPlay = false;
    bool g_menuOpen = false;
}

void toast(const char* txt) {
    Notification::create(
        txt,
        NotificationIcon::Info
    )->show();
}

bool shouldJump(PlayerObject* player) {
    if (!player)
        return false;

    /*
        Basit mantık:
        yere değince zıpla.
        cube / robot / spider için çalışır.
    */

    if (
        player->m_isOnGround &&
        player->getYVelocity() <= 0.f
    ) {
        return true;
    }

    return false;
}

void runAutoPlay(PlayLayer* pl) {
    if (!g_autoPlay)
        return;

    if (!pl)
        return;

    auto player = pl->m_player1;

    if (!player)
        return;

    /*
        Ship auto fly
    */

    if (player->m_isShip) {

        if (player->getPositionY() < 120.f) {
            player->pushButton(PlayerButton::Jump);
        }
        else {
            player->releaseButton(PlayerButton::Jump);
        }

        return;
    }

    /*
        Wave auto
    */

    if (player->m_isDart) {

        if (player->getYVelocity() < -2.f) {
            player->pushButton(PlayerButton::Jump);
        }
        else {
            player->releaseButton(PlayerButton::Jump);
        }

        return;
    }

    /*
        Cube auto
    */

    if (shouldJump(player)) {
        player->pushButton(PlayerButton::Jump);
    }
    else {
        player->releaseButton(PlayerButton::Jump);
    }
}

class EmirMenu : public CCLayer {
public:
    CCMenu* m_menu = nullptr;
    CCLayerColor* m_bg = nullptr;

    static EmirMenu* create() {
        auto ret = new EmirMenu();

        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }

        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init())
            return false;

        auto win = CCDirector::sharedDirector()->getWinSize();

        /*
            DOKUNMATİK BOZULMASIN DİYE FALSE
        */

        this->setTouchEnabled(false);

        m_bg = CCLayerColor::create(
            {0, 0, 0, 120},
            260.f,
            220.f
        );

        m_bg->setPosition({
            win.width / 2 - 130.f,
            win.height / 2 - 110.f
        });

        m_bg->setVisible(false);

        this->addChild(m_bg, 100);

        m_menu = CCMenu::create();
        m_menu->setPosition(0, 0);

        this->addChild(m_menu, 101);

        /*
            OPEN BUTTON
        */

        auto openBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                "EH",
                80,
                true,
                "goldFont.fnt",
                "GJ_button_04.png",
                30.f,
                1.f
            ),
            this,
            menu_selector(EmirMenu::onOpen)
        );

        openBtn->setPosition({
            60.f,
            win.height / 2
        });

        m_menu->addChild(openBtn);

        /*
            NOCLIP
        */

        auto noclipBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                "Noclip",
                120,
                true,
                "goldFont.fnt",
                "GJ_button_01.png",
                25.f,
                0.8f
            ),
            this,
            menu_selector(EmirMenu::onNoclip)
        );

        noclipBtn->setPosition({
            win.width / 2,
            win.height / 2 + 50.f
        });

        m_menu->addChild(noclipBtn);

        /*
            AUTOPLAY
        */

        auto autoBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                "Auto Play",
                120,
                true,
                "goldFont.fnt",
                "GJ_button_05.png",
                25.f,
                0.8f
            ),
            this,
            menu_selector(EmirMenu::onAutoPlay)
        );

        autoBtn->setPosition({
            win.width / 2,
            win.height / 2
        });

        m_menu->addChild(autoBtn);

        /*
            CLOSE
        */

        auto closeBtn = CCMenuItemSpriteExtra::create(
            ButtonSprite::create(
                "Close",
                120,
                true,
                "goldFont.fnt",
                "GJ_button_06.png",
                25.f,
                0.8f
            ),
            this,
            menu_selector(EmirMenu::onOpen)
        );

        closeBtn->setPosition({
            win.width / 2,
            win.height / 2 - 50.f
        });

        m_menu->addChild(closeBtn);

        noclipBtn->setVisible(false);
        autoBtn->setVisible(false);
        closeBtn->setVisible(false);

        noclipBtn->setTag(1000);
        autoBtn->setTag(1001);
        closeBtn->setTag(1002);

        return true;
    }

    void updateGUI() {
        auto noclipBtn = m_menu->getChildByTag(1000);
        auto autoBtn = m_menu->getChildByTag(1001);
        auto closeBtn = m_menu->getChildByTag(1002);

        if (noclipBtn)
            noclipBtn->setVisible(g_menuOpen);

        if (autoBtn)
            autoBtn->setVisible(g_menuOpen);

        if (closeBtn)
            closeBtn->setVisible(g_menuOpen);

        if (m_bg)
            m_bg->setVisible(g_menuOpen);
    }

    void onOpen(CCObject*) {
        g_menuOpen = !g_menuOpen;

        updateGUI();
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
            "AutoPlay Enabled" :
            "AutoPlay Disabled"
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

        runAutoPlay(this);
    }

    void destroyPlayer(
        PlayerObject* player,
        GameObject* obj
    ) {
        if (g_noclip)
            return;

        PlayLayer::destroyPlayer(
            player,
            obj
        );
    }
};

$on_mod(Loaded) {
    log::info("Emir Hub Loaded");
}
