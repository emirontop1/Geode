#include "EHMenuLayer.hpp"

/* ═══════════════════════════════════════════════════════
   Static instance
   ═══════════════════════════════════════════════════════ */
EHMenuLayer* EHMenuLayer::s_instance = nullptr;

/* ═══════════════════════════════════════════════════════
   toggle()  —  Tab'a basıldığında çağrılır
   ═══════════════════════════════════════════════════════ */
void EHMenuLayer::toggle() {
    if (s_instance) {
        s_instance->removeFromParent();
        s_instance = nullptr;
        Client::get().menuOpen = false;
        return;
    }

    auto* scene = CCDirector::get()->getRunningScene();
    if (!scene) return;

    auto* menu = EHMenuLayer::create();
    if (!menu) return;

    /* Ekranın ortasına yerleştir */
    CCSize ws = CCDirector::get()->getWinSize();
    menu->setPosition(ccp(
        ws.width  * .5f - EH_MENU_W * .5f,
        ws.height * .5f - EH_MENU_H * .5f
    ));

    /* Yüksek Z: oyun içeriğinin üstünde */
    scene->addChild(menu, 9999);
    s_instance = menu;
    Client::get().menuOpen = true;
}

void EHMenuLayer::destroy() {
    if (s_instance) {
        s_instance->removeFromParent();
        s_instance = nullptr;
    }
    Client::get().menuOpen = false;
}

/* ═══════════════════════════════════════════════════════
   create / init
   ═══════════════════════════════════════════════════════ */
EHMenuLayer* EHMenuLayer::create() {
    auto* l = new EHMenuLayer();
    if (l && l->init()) { l->autorelease(); return l; }
    CC_SAFE_DELETE(l);
    return nullptr;
}

bool EHMenuLayer::init() {
    if (!CCLayer::init()) return false;

    setContentSize({ EH_MENU_W, EH_MENU_H });

    /* ── Arka plan ── */
    auto* bg = CCLayerColor::create(EH_BG_COLOR, EH_MENU_W, EH_MENU_H);
    bg->setPosition(CCPointZero);
    addChild(bg, 0);

    /* ── Yuvarlatılmış köşe efekti: ince kenarlık şeridi ── */
    auto* border = CCLayerColor::create({ 90, 70, 160, 180 }, EH_MENU_W, 2.f);
    border->setPosition(ccp(0, EH_MENU_H - 2.f));
    addChild(border, 1);

    /* ── Başlık bandı ── */
    auto* header = CCLayerColor::create(EH_HEADER_COLOR, EH_MENU_W, EH_HEADER_H);
    header->setPosition(ccp(0, EH_MENU_H - EH_HEADER_H));
    addChild(header, 1);

    /* ── Başlık yazısı ── */
    auto* title = CCLabelBMFont::create("EmiR Hub", "goldFont.fnt");
    title->setScale(.48f);
    title->setColor(EH_TITLE_COLOR);
    title->setPosition(ccp(EH_MENU_W * .5f, EH_MENU_H - EH_HEADER_H * .5f));
    addChild(title, 2);

    /* ── Kapat düğmesi ── */
    auto* xSpr = CCLabelBMFont::create("X", "bigFont.fnt");
    xSpr->setScale(.40f);
    xSpr->setColor({ 200, 160, 255 });

    auto* xBtn = CCMenuItemSpriteExtra::create(
        xSpr,
        this,
        menu_selector(EHMenuLayer::_onClose)
    );
    auto* xMenu = CCMenu::create(xBtn, nullptr);
    xMenu->setPosition(ccp(EH_MENU_W - 14.f, EH_MENU_H - EH_HEADER_H * .5f));
    addChild(xMenu, 3);

    /* ── Hack satırları ── */
    _buildRows();

    /* ── Dokunma ── */
    setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);

    return true;
}

/* ═══════════════════════════════════════════════════════
   Satır oluşturma
   ═══════════════════════════════════════════════════════ */
void EHMenuLayer::_buildRows() {
    auto& hacks = Client::get().hacks;
    for (int i = 0; i < (int)hacks.size(); i++) {
        float y = EH_MENU_H - EH_HEADER_H - EH_PAD - i * EH_ROW_H - EH_ROW_H * .5f;
        _addRow(i, y);
    }
}

void EHMenuLayer::_addRow(int idx, float y) {
    Row row;
    row.hackIndex = idx;

    /* Arka plan şeridi (hover efekti için) */
    row.bg = CCLayerColor::create(EH_ROW_HOVER, EH_MENU_W - EH_PAD * 2.f, EH_ROW_H - 4.f);
    row.bg->setPosition(ccp(EH_PAD, y - (EH_ROW_H - 4.f) * .5f));
    row.bg->setOpacity(0);   // normalde şeffaf, touch'ta gösterilir
    addChild(row.bg, 1);

    /* İsim etiketi (sol) */
    row.nameL = CCLabelBMFont::create(Client::get().hacks[idx].name.c_str(), "bigFont.fnt");
    row.nameL->setScale(.40f);
    row.nameL->setColor(EH_LABEL_COLOR);
    row.nameL->setAnchorPoint({ 0.f, .5f });
    row.nameL->setPosition(ccp(EH_PAD + 6.f, y));
    addChild(row.nameL, 2);

    /* Durum etiketi (sağ) */
    bool on = Client::get().hacks[idx].enabled;
    row.stateL = CCLabelBMFont::create(on ? "ON" : "OFF", "bigFont.fnt");
    row.stateL->setScale(.38f);
    row.stateL->setColor(on ? EH_ON_COLOR : EH_OFF_COLOR);
    row.stateL->setAnchorPoint({ 1.f, .5f });
    row.stateL->setPosition(ccp(EH_MENU_W - EH_PAD - 4.f, y));
    addChild(row.stateL, 2);

    /* Ayırıcı çizgi */
    auto* sep = CCLayerColor::create(EH_SEPARATOR, EH_MENU_W - EH_PAD * 2.f, 1.f);
    sep->setPosition(ccp(EH_PAD, y - EH_ROW_H * .5f));
    addChild(sep, 1);

    /* Tıklanabilir şeffaf buton (satırın tamamı) */
    auto* hitSpr = CCScale9Sprite::create("square02_small.png");
    hitSpr->setContentSize({ EH_MENU_W - EH_PAD * 2.f, EH_ROW_H - 4.f });
    hitSpr->setOpacity(0);

    auto* btn = CCMenuItemSpriteExtra::create(
        hitSpr, this, menu_selector(EHMenuLayer::_onRowTap));
    btn->setTag(idx);
    btn->setPosition(ccp(EH_MENU_W * .5f, y));

    auto* rowMenu = CCMenu::create(btn, nullptr);
    rowMenu->setPosition(CCPointZero);
    addChild(rowMenu, 4);

    m_rows.push_back(row);
}

void EHMenuLayer::_refreshRow(Row& r) {
    bool on = Client::get().hacks[r.hackIndex].enabled;
    r.stateL->setString(on ? "ON" : "OFF");
    r.stateL->setColor(on ? EH_ON_COLOR : EH_OFF_COLOR);

    /* Küçük pulse animasyonu */
    r.stateL->runAction(CCSequence::create(
        CCScaleTo::create(.05f, 1.25f),
        CCScaleTo::create(.05f, 1.00f),
        nullptr
    ));
}

void EHMenuLayer::_onRowTap(CCObject* sender) {
    int idx = sender->getTag();
    if (idx < 0 || idx >= (int)Client::get().hacks.size()) return;
    Client::get().hacks[idx].toggle();
    if (idx < (int)m_rows.size()) _refreshRow(m_rows[idx]);
}

void EHMenuLayer::_onClose() {
    s_instance = nullptr;
    Client::get().menuOpen = false;
    removeFromParent();
}

/* ═══════════════════════════════════════════════════════
   Touch — sürükleme (başlık bandından)
   ═══════════════════════════════════════════════════════ */
bool EHMenuLayer::ccTouchBegan(CCTouch* touch, CCEvent*) {
    CCPoint lp = convertTouchToNodeSpace(touch);

    /* Başlık bandı → sürüklemeye başla */
    CCRect headerRect{ 0, EH_MENU_H - EH_HEADER_H, EH_MENU_W, EH_HEADER_H };
    if (headerRect.containsPoint(lp)) {
        m_dragging   = true;
        m_dragOffset = lp;
        return true;
    }

    /* Panel içindeyse yut (arkasına geçmesin) */
    CCRect panelRect{ 0, 0, EH_MENU_W, EH_MENU_H };
    return panelRect.containsPoint(lp);
}

void EHMenuLayer::ccTouchMoved(CCTouch* touch, CCEvent*) {
    if (!m_dragging) return;
    setPosition(touch->getLocation() - m_dragOffset);
}

void EHMenuLayer::ccTouchEnded(CCTouch*, CCEvent*) {
    m_dragging = false;
}

void EHMenuLayer::ccTouchCancelled(CCTouch* t, CCEvent* e) {
    ccTouchEnded(t, e);
}

void EHMenuLayer::registerWithTouchDispatcher() {
    CCDirector::get()->getTouchDispatcher()->addTargetedDelegate(this, -500, true);
}
