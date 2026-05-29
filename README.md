# Emir Hub

Emir Hub is an in-level Geode playtest menu for Geometry Dash. It is built as a compact, Mega-Hack-inspired utility panel focused on quick testing, visual debugging, and safe assist toggles.

<img src="logo.png" width="150" alt="Emir Hub logo" />

## Features

### Player tab
- **No Death**: toggles `PlayLayer::toggleIgnoreDamage` for safe route testing.
- **Practice**: toggles practice mode while keeping other menu settings active.
- **Hide P1**: hides/shows the player icon for visibility checks.
- **Attempts / Progress / Info**: quick UI visibility controls.

### Assist tab
- **Auto Play**: enables the assist engine.
- **Ground AI**: detects nearby solid collision objects, spikes, and wall-like blockers, then jumps/taps for cube, ball, robot, and spider gameplay.
- **Air AI**: steers or taps around nearby obstacles and level bounds for ship, UFO, wave, and swing gameplay.
- **Platform**: holds the right movement input for platformer-style tests.
- **Auto All**: enables the full all-mode assist stack at once.
- **Release**: force-releases any auto-held inputs.

### Visual tab
- **Hitboxes**: uses Geode debug draw safely via `shouldDebugDraw` + `toggleDebugDraw`.
- **Ground / MG / BG FX**: quick visibility toggles for level layers and effects.
- **Debug**: refreshes debug draw settings.
- **Glitter**: refreshes glitter visibility.

### Utility tab
- **Speed**: cycles playtest time-mod values up to 2.00x.
- **Slower / Normal**: quick speed adjustment buttons.
- **Restart**: restarts from the beginning and reapplies active options.
- **Clear CP**: removes all practice checkpoints.
- **About**: in-game feature summary.

## Notes

Auto Play is a heuristic playtest assist, not a perfect verifier. It scans visible gameplay collision objects ahead of the player and supports cube, ship, ball, UFO, wave, robot, spider, swing, and platformer-style tests. It works best with **No Death** enabled while tuning hard levels.

## Build instructions

```sh
# Requires the Geode CLI / SDK environment
geode build
```

## Resources

- [Geode SDK Documentation](https://docs.geode-sdk.org/)
- [Geode SDK Source Code](https://github.com/geode-sdk/geode/)
- [Geode CLI](https://github.com/geode-sdk/cli)
