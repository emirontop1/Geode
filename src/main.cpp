/**
 * main.cpp
 * EmiR Hub — Geode Mod
 *
 * Dosya yapısı:
 *   src/
 *     main.cpp                          ← burası (entry point)
 *     Handlers.hpp                      ← tüm $modify hook'ları
 *     Client/
 *       Client.hpp                      ← singleton, Hack listesi
 *     UI/
 *       EHMenuLayer.hpp / .cpp          ← sürüklenebilir GUI panel
 *     Hacks/
 *       Trajectory/
 *         Trajectory.hpp / .cpp         ← fizik sim + çizim
 */

#include <Geode/Geode.hpp>

/* UI implementasyonu — sadece bir .cpp'de include edilmeli */
#include "UI/EHMenuLayer.cpp"

/* Trajectory implementasyonu */
#include "Hacks/Trajectory/Trajectory.cpp"

/* Tüm hook'lar */
#include "Handlers.hpp"

using namespace geode::prelude;

/* ═══════════════════════════════════════════════════════
   Geode Mod yüklenince
   ═══════════════════════════════════════════════════════ */
$on_mod(Loaded) {
    log::info("[EmiR Hub] v1.0.0 yüklendi.");
    log::info("[EmiR Hub] Tab tusu ile menuyu ac/kapat.");

    /* Ayarları RAM'e yükle */
    Client::get().loadAll();
}
