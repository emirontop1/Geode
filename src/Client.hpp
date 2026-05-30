#pragma once
#include <Geode/Geode.hpp>
#include <string>
#include <vector>

using namespace geode::prelude;
using namespace cocos2d;

/* ═══════════════════════════════════════════════════════
   Hack  —  tek bir toggle özelliğini temsil eder
   ═══════════════════════════════════════════════════════ */
struct Hack {
    std::string id;       // mod.json setting key
    std::string name;     // UI'da görünen isim
    std::string desc;     // tooltip açıklama
    bool        enabled;  // anlık durum (RAM'de)

    Hack(const std::string& id, const std::string& name, const std::string& desc)
        : id(id), name(name), desc(desc), enabled(false) {}

    /* Geode settings ile senkronize et */
    void load()  { enabled = Mod::get()->getSettingValue<bool>(id); }
    void save()  { (void)Mod::get()->setSettingValue<bool>(id, enabled); }
    void toggle(){ enabled = !enabled; save(); }
};

/* ═══════════════════════════════════════════════════════
   Client  —  merkezi singleton
   Tüm hack'leri tutar, UI layer'a referans verir.
   ═══════════════════════════════════════════════════════ */
class Client {
public:
    /* Hack listesi — buraya yeni özellik eklersin */
    std::vector<Hack> hacks = {
        { "trajectory_enabled", "Trajectory",   "Zıplayınca yol tahmini gösterir" },
        { "show_mode_label",    "Mod Etiketi",  "Trajectory üstünde mod adını gösterir" },
    };

    bool menuOpen = false;   // menü şu an açık mı?

    /* ── Singleton erişimi ── */
    static Client& get() {
        static Client inst;
        return inst;
    }

    /* Tüm hack'leri Geode settings'ten yükle */
    void loadAll() {
        for (auto& h : hacks) h.load();
    }

    /* id ile hack bul */
    Hack* find(const std::string& id) {
        for (auto& h : hacks) if (h.id == id) return &h;
        return nullptr;
    }

    /* id ile enabled durumu sorgula */
    bool isEnabled(const std::string& id) {
        auto* h = find(id);
        return h ? h->enabled : false;
    }

private:
    Client() { loadAll(); }
    Client(const Client&)            = delete;
    Client& operator=(const Client&) = delete;
};
