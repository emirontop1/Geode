#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;
using namespace cocos2d;

namespace {
    bool g_noclip = false;
    bool g_autoPlay = false;
    bool g_showHitbox = false;
    bool g_menuOpen = false;

    DrawNode* g_drawNode = nullptr;
}

void toast(const char* txt) {
    Notification::create(
        txt,
        NotificationIcon::Info
    )->show();
}

/*
    HITBOX DRAW
*/

void drawRect(
    DrawNode* node,
    CCRect rect,
    ccColor4F color
) {
    CCPoint verts[4] = {
        {rect.getMinX(), rect.getMinY()},
        {rect.getMaxX(), rect.getMinY()},
        {rect.getMaxX(), rect.getMaxY()},
        {rect.getMinX(), rect.getMaxY()}
    };

    node->drawPoly(
        verts,
        4,
        true,
        color
    );
}

/*
    FUTURE SIMULATION
*/

bool willHitSpike(
    PlayerObject* player,
    bool jump
) {
    if (!player)
        return false;

    /*
        fake future prediction
    */

    float futureX =
        player->getPositionX() + 70.f;

    float futureY =
        player->getPositionY();

    if (jump) {
        futureY += 90.f;
    }

    auto objs =
        PlayLayer::get()->m_objects;

    for (auto obj : CCArrayExt<GameObject*>(objs)) {

        if (!obj)
            continue;

        /*
            spike/object detection
        */

        auto dist =
            fabs(obj->getPositionX() - futureX);

        if (dist > 80.f)
            continue;

        auto rect = CCRect(
            obj->getPositionX() - 20.f,
            obj->getPositionY() - 20.f,
            40.f,
            40.f
        );

        if (rect.containsPoint({
            futureX,
            futureY
        })) {
            return true;
        }
    }

    return false;
}

/*
    SMART AUTOPLAY
*/

void runSmartAutoPlay(
    PlayLayer* pl
) {
    if (!g_autoPlay)
        return;

    if (!pl)
        return;

    auto player =
        pl->m_player1;

    if (!player)
        return;

    bool noJumpDead =
        willHitSpike(player, false);

    bool jumpDead =
        willHitSpike(player, true);

    /*
        VISUAL LINES
    */

    if (g_drawNode) {
        g_drawNode->clear();

        auto pos =
            player->getPosition();

        /*
            no jump line
        */

        g_drawNode->drawLine(
            pos,
            {
                pos.x + 70.f,
                pos.y
            },
            noJumpDead ?
            ccc4f(1,0,0,1) :
            ccc4f(0,1,0,1)
        );

        /*
            jump line
        */

        g_drawNode->drawLine(
            pos,
            {
                pos.x + 70.f,
                pos.y + 90.f
            },
            jumpDead ?
            ccc4f(1,0,0,1) :
            ccc4f(0,1,0,1)
        );
    }

    /*
        DECISION SYSTEM
    */

    if (
        noJumpDead &&
        !jumpDead
    ) {
        player->pushButton(
            PlayerButton::Jump
        );
    }
    else {
        player->releaseButton(
            PlayerButton::Jump
        );
    }
}

/*
    HITBOXES
*/

void renderHitboxes(
    PlayLayer* pl
) {
    if (!g_showHitbox)
        return;

    if (!pl)
        return;

    if (!g_drawNode)
        return;

    auto objs =
        pl->m_objects;

    for (auto obj :
        CCArrayExt<GameObject*>(objs)) {

        if (!obj)
            continue;

        auto rect = CCRect(
            obj->getPositionX() - 15.f,
            obj->getPositionY() - 15.f,
            30.f,
            30.f
        );

        drawRect(
            g_drawNode,
            rect,
            ccc4f(1,0,0,1)
        );
    }
}

/*
    MENU
*/

class EmirMenu : public CCLayer {
public:
    CCMenu* m_menu = nullptr;
    CCLayerColor* m_bg = nullptr;

    static EmirMenu* create() {
        auto ret = new EmirMenu();

        if (
            ret &&
            ret->init()
        ) {
            ret->autorelease();
            return ret;
        }

        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!CCLayer::init())
            return false;

        auto win =
            CCDirector::sharedDirector()
            ->getWinSize();

        this->setTouchEnabled(false);

        /*
            BG
        */

        m_bg = CCLayerColor::create(
            {0,0,0,120},
            260.f,
            260.f
        );

        m_bg->setPosition({
            win.width/2 - 130.f,
            win.height/2 - 130.f
        });

        m_bg->setVisible(false);

        this->addChild(
            m_bg,
            100
        );

        /*
            MENU
        */

        m_menu = CCMenu::create();
        m_menu->setPosition(0,0);

        this->addChild(
            m_menu,
            101
        );

        /*
            OPEN
        */

        auto openBtn =
            CCMenuItemSpriteExtra::create(
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
                menu_selector(
                    EmirMenu::onOpen
                )
            );

        openBtn->setPosition({
            60.f,
            win.height/2
        });

        m_menu->addChild(openBtn);

        /*
            AUTOPLAY
        */

        auto autoBtn =
            CCMenuItemSpriteExtra::create(
                ButtonSprite::create(
                    "Smart Auto",
                    140,
                    true,
                    "goldFont.fnt",
                    "GJ_button_05.png",
                    25.f,
                    0.8f
                ),
                this,
                menu_selector(
                    EmirMenu::onAutoPlay
                )
            );

        autoBtn->setPosition({
            win.width/2,
            win.height/2 + 50.f
        });

        m_menu->addChild(autoBtn);

        /*
            NOCLIP
        */

        auto noclipBtn =
            CCMenuItemSpriteExtra::create(
                ButtonSprite::create(
                    "Noclip",
                    140,
                    true,
                    "goldFont.fnt",
                    "GJ_button_01.png",
                    25.f,
                    0.8f
                ),
                this,
                menu_selector(
                    EmirMenu::onNoclip
                )
            );

        noclipBtn->setPosition({
            win.width/2,
            win.height/2
        });

        m_menu->addChild(noclipBtn);

        /*
            HITBOX
        */

        auto hitboxBtn =
            CCMenuItemSpriteExtra::create(
                ButtonSprite::create(
                    "Show Hitboxes",
                    170,
                    true,
                    "goldFont.fnt",
                    "GJ_button_02.png",
                    25.f,
                    0.7f
                ),
                this,
                menu_selector(
                    EmirMenu::onHitbox
                )
            );

        hitboxBtn->setPosition({
            win.width/2,
            win.height/2 - 50.f
        });

        m_menu->addChild(hitboxBtn);

        /*
            CLOSE
        */

        auto closeBtn =
            CCMenuItemSpriteExtra::create(
                ButtonSprite::create(
                    "Close",
                    140,
                    true,
                    "goldFont.fnt",
                    "GJ_button_06.png",
                    25.f,
                    0.8f
                ),
                this,
                menu_selector(
                    EmirMenu::onOpen
                )
            );

        closeBtn->setPosition({
            win.width/2,
            win.height/2 - 100.f
        });

        m_menu->addChild(closeBtn);

        autoBtn->setVisible(false);
        noclipBtn->setVisible(false);
        hitboxBtn->setVisible(false);
        closeBtn->setVisible(false);

        autoBtn->setTag(1);
        noclipBtn->setTag(2);
        hitboxBtn->setTag(3);
        closeBtn->setTag(4);

        return true;
    }

    void updateGUI() {
        for (int i = 1; i <= 4; i++) {

            auto obj =
                m_menu->getChildByTag(i);

            if (obj)
                obj->setVisible(
                    g_menuOpen
                );
        }

        if (m_bg)
            m_bg->setVisible(
                g_menuOpen
            );
    }

    void onOpen(CCObject*) {
        g_menuOpen =
            !g_menuOpen;

        updateGUI();
    }

    void onAutoPlay(CCObject*) {
        g_autoPlay =
            !g_autoPlay;

        toast(
            g_autoPlay ?
            "Smart Auto Enabled" :
            "Smart Auto Disabled"
        );
    }

    void onNoclip(CCObject*) {
        g_noclip =
            !g_noclip;

        toast(
            g_noclip ?
            "Noclip Enabled" :
            "Noclip Disabled"
        );
    }

    void onHitbox(CCObject*) {
        g_showHitbox =
            !g_showHitbox;

        toast(
            g_showHitbox ?
            "Hitboxes Enabled" :
            "Hitboxes Disabled"
        );
    }
};

/*
    PLAYLAYER
*/

class $modify(MyPlayLayer, PlayLayer) {

    bool init(
        GJGameLevel* level,
        bool useReplay,
        bool dontCreateObjects
    ) {

        if (
            !PlayLayer::init(
                level,
                useReplay,
                dontCreateObjects
            )
        ) {
            return false;
        }

        auto menu =
            EmirMenu::create();

        this->addChild(
            menu,
            99999
        );

        g_drawNode =
            DrawNode::create();

        this->addChild(
            g_drawNode,
            99998
        );

        toast(
            "Emir Smart Hub Loaded"
        );

        return true;
    }

    void update(float dt) {
        PlayLayer::update(dt);

        if (g_drawNode)
            g_drawNode->clear();

        runSmartAutoPlay(this);

        renderHitboxes(this);
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
    log::info(
        "Emir Smart Hub Loaded"
    );
}
