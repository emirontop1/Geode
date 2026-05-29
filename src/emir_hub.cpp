/*
 * Emir Hub — Huge Mod Menu
 * Geode / GD 2.2081 / Android aarch64
 */
#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/modify/PauseLayer.hpp>
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

        auto categoryMenu = CCMenu::create();
        categoryMenu->setPosition({0.0f, 0.0f});
        m_mainLayer->addChild(categoryMenu);

        for (size_t i = 0; i < kCategories.size(); ++i) {
            auto label = CCLabelBMFont::create(kCategories[i].name, "bigFont.fnt");
            label->setScale(0.32f);
            auto item = CCMenuItemSpriteExtra::create(label, this, menu_selector(EmirHubPopup::onCategory));
            item->setTag(static_cast<int>(i));
            item->setPosition({43.0f + static_cast<float>(i % 4) * 83.0f, 224.0f - static_cast<float>(i / 4) * 21.0f});
            categoryMenu->addChild(item);
        }

        auto navMenu = CCMenu::create();
        navMenu->setPosition({0.0f, 0.0f});
        m_mainLayer->addChild(navMenu);

        auto prevLabel = CCLabelBMFont::create("< Prev", "bigFont.fnt");
        prevLabel->setScale(0.44f);
        auto prevItem = CCMenuItemSpriteExtra::create(prevLabel, this, menu_selector(EmirHubPopup::onPrevPage));
        prevItem->setPosition({52.0f, 24.0f});
        navMenu->addChild(prevItem);

        auto nextLabel = CCLabelBMFont::create("Next >", "bigFont.fnt");
        nextLabel->setScale(0.44f);
        auto nextItem = CCMenuItemSpriteExtra::create(nextLabel, this, menu_selector(EmirHubPopup::onNextPage));
        nextItem->setPosition({368.0f, 24.0f});
        navMenu->addChild(nextItem);

        m_statusLabel = CCLabelBMFont::create("", "chatFont.fnt");
        m_statusLabel->setScale(0.52f);
        m_statusLabel->setAnchorPoint({0.5f, 0.5f});
        m_statusLabel->setPosition({210.0f, 45.0f});
        m_mainLayer->addChild(m_statusLabel);

        refreshContent();
        return true;
    }

    void refreshContent() {
        clampNavigation();
        m_contentLayer->removeAllChildrenWithCleanup(true);

        auto title = fmt::format("{} | page {}/{}", kCategories[g_category].name, g_page + 1, maxPageForCategory(g_category) + 1);
        makeLabel(title.c_str(), 0.45f, {210.0f, 181.0f}, m_contentLayer);

        auto description = CCLabelBMFont::create(kCategories[g_category].description, "chatFont.fnt");
        description->setScale(0.45f);
        description->setPosition({210.0f, 162.0f});
        m_contentLayer->addChild(description);

        auto featureMenu = CCMenu::create();
        featureMenu->setPosition({0.0f, 0.0f});
        m_contentLayer->addChild(featureMenu);

        for (size_t row = 0; row < kRowsPerPage; ++row) {
            auto index = absoluteFeatureIndex(g_category, g_page, static_cast<int>(row));
            if (index >= kFeatures.size()) {
                continue;
            }

            auto const& feature = kFeatures[index];
            auto enabled = g_enabled[index];
            auto prefix = enabled ? "[ON]" : (isMomentaryAction(feature.action) ? "[>>]" : "[--]");
            auto text = fmt::format("{} {}", prefix, feature.title);
            auto label = CCLabelBMFont::create(text.c_str(), enabled ? "goldFont.fnt" : "bigFont.fnt");
            label->setScale(0.28f);
            auto item = CCMenuItemSpriteExtra::create(label, this, menu_selector(EmirHubPopup::onFeature));
            item->setTag(static_cast<int>(index));
            auto col = static_cast<float>(row / 6);
            auto localRow = static_cast<float>(row % 6);
            item->setPosition({112.0f + col * 202.0f, 139.0f - localRow * 17.0f});
            featureMenu->addChild(item);

            auto desc = CCLabelBMFont::create(feature.description, "chatFont.fnt");
            desc->setScale(0.23f);
            desc->setAnchorPoint({0.0f, 0.5f});
            desc->setPosition({18.0f + col * 202.0f, 130.5f - localRow * 17.0f});
            desc->setOpacity(130);
            m_contentLayer->addChild(desc);
        }

        auto status = fmt::format(
            "{} active here | {} active total | {} rows | speed {:.2f}x",
            g_profile.activeByCategory[g_category], g_profile.totalActive, kFeatureCount, g_timeWarp
        );
        m_statusLabel->setString(status.c_str());
    }

    void onFeature(CCObject* sender) {
        auto item = static_cast<CCNode*>(sender);
        auto index = static_cast<size_t>(item->getTag());
        runAction(index);
        refreshContent();
    }

    void onCategory(CCObject* sender) {
        auto item = static_cast<CCNode*>(sender);
        g_category = item->getTag();
        g_page = 0;
        refreshContent();
    }

    void onPrevPage(CCObject*) {
        --g_page;
        refreshContent();
    }

    void onNextPage(CCObject*) {
        ++g_page;
        refreshContent();
    }

public:
    static EmirHubPopup* create() {
        auto ret = new EmirHubPopup();
        if (ret && ret->initAnchored(420.0f, 280.0f)) {
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }
};
} // namespace emir_hub

class $modify(EmirHubPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = CCMenu::create();
        menu->setPosition({0.0f, 0.0f});
        this->addChild(menu, 9999);

        auto label = CCLabelBMFont::create("Emir Hub XXL", "bigFont.fnt");
        label->setScale(0.42f);
        auto button = CCMenuItemSpriteExtra::create(label, this, menu_selector(EmirHubPauseLayer::onOpenEmirHub));
        button->setPosition({CCDirector::sharedDirector()->getWinSize().width - 70.0f, 32.0f});
        menu->addChild(button);
    }

    void onOpenEmirHub(CCObject*) {
        emir_hub::EmirHubPopup::create()->show();
    }
};

class $modify(EmirHubPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) {
            return false;
        }

        emir_hub::g_playLayer = this;
        emir_hub::applyPersistentFeatures(this);
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
