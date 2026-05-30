#pragma once
#include <Geode/Geode.hpp>
#include "../Client/Client.hpp"

using namespace geode::prelude;
using namespace cocos2d;

/* Renk sabitleri */
static const ccColor4B  EH_BG_COLOR     = { 15,  12,  28, 230 };
static const ccColor4B  EH_HEADER_COLOR = { 38,  28,  72, 255 };
static const ccColor4B  EH_ROW_HOVER    = { 50,  40,  90, 120 };
static const ccColor4B  EH_SEPARATOR    = { 80,  70, 130, 100 };
static const ccColor3B  EH_TITLE_COLOR  = { 210, 190, 255 };
static const ccColor3B  EH_ON_COLOR     = {  80, 220, 120 };
static const ccColor3B  EH_OFF_COLOR    = { 210,  70,  70 };
static const ccColor3B  EH_LABEL_COLOR  = { 200, 200, 230 };

/* Panel boyutları */
static constexpr float EH_MENU_W    = 310.f;
static constexpr float EH_MENU_H    = 220.f;
static constexpr float EH_HEADER_H  = 26.f;
static constexpr float EH_ROW_H     = 32.f;
static constexpr float EH_PAD       = 12.f;

/* ═══════════════════════════════════════════════════════
   EHMenuLayer  —  GeodeMenu stilinde sürüklenebilir panel
   ═══════════════════════════════════════════════════════ */
class EHMenuLayer : public CCLayer {
public:
    /* ── Singleton referansı (sahnede tek örnek) ── */
    static EHMenuLayer* s_instance;

    /* Menüyü aç/kapat */
    static void toggle();
    /* Sahneden temizle (oyun kapandığında) */
    static void destroy();

    static EHMenuLayer* create();
    bool init() override;

    /* CCLayer touch */
    bool ccTouchBegan   (CCTouch*, CCEvent*) override;
    void ccTouchMoved   (CCTouch*, CCEvent*) override;
    void ccTouchEnded   (CCTouch*, CCEvent*) override;
    void ccTouchCancelled(CCTouch* t, CCEvent* e) override;
    void registerWithTouchDispatcher() override;

private:
    /* Her satır için tuttuğumuz veri */
    struct Row {
        int            hackIndex;      // Client::hacks[] indeksi
        CCLayerColor*  bg      = nullptr;
        CCLabelBMFont* nameL   = nullptr;
        CCLabelBMFont* stateL  = nullptr;
    };
    std::vector<Row> m_rows;

    /* Sürükleme */
    bool    m_dragging   = false;
    CCPoint m_dragOffset = CCPointZero;

    /* Yardımcılar */
    void _buildRows();
    void _addRow(int idx, float y);
    void _refreshRow(Row& r);
    void _onRowTap(CCObject* sender);   // menu_selector için CCObject* şart
    void _onClose(CCObject* sender);    // menu_selector için CCObject* şart
};
