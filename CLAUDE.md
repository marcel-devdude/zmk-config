# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A ZMK firmware user config for a wireless split Corne (42 keys, nice!nano v2 controllers, nice!view displays). ZMK `main` is on Zephyr 4.1, so the board ID in `build.yaml` is `nice_nano//zmk` (the old `nice_nano_v2` no longer builds). There is no local build setup — firmware is built entirely by GitHub Actions.

## Build & CI

- **Firmware**: `.github/workflows/build.yml` runs ZMK's reusable `build-user-config.yml` on every push/PR. The build matrix comes from `build.yaml` (left half, right half, and a `settings_reset` image). Download the `.uf2` files from the workflow run's artifacts.
- **Keymap diagram**: `.github/workflows/draw-keymaps.yml` runs keymap-drawer whenever `config/*.keymap` changes and commits the regenerated `keymap-drawer/corne.yaml` and `keymap-drawer/corne.svg` back to the repo as `chore: Draw <original commit message>`. Don't hand-edit those files; after pushing, `git pull` to pick up the bot commit before making further changes.
- Since nothing builds locally, devicetree/keymap syntax errors only surface in CI — check carefully before pushing.

## Configuration layout

- `config/west.yml` — west manifest: ZMK `main` plus `urob/zmk-helpers` (`main`).
- `config/corne.conf` — Kconfig options (keyboard name `MarcelsCorne`, display widgets, sleep after 30 min, BLE TX power, debounce tuning).
- `config/corne.keymap` — the keymap, behaviors, and macros.
- `zephyr/module.yml` + `boards/shields/` — makes the repo a Zephyr module so custom boards/shields can be added (currently empty).

## Keymap notes

- The host is macOS with the classic "German" input source (same as the laptop's built-in keyboard). ZMK keycodes are US-position names, so `config/keys_de_mac.h` defines `DE_*` aliases for the character each key produces there (e.g. `DE_Z` = `Y`, `DE_AT` = Option+L). Use `DE_*` names for anything that isn't a letter, digit or plain control key. The aliases were checked against the actual layout with `UCKeyTranslate`.
- `^` `` ` `` `~` are dead keys on that layout; `&de_caret`/`&de_grave`/`&de_tilde` are macros that add a space. `<`/`>` (NUBS) depend on macOS treating the Corne as an ISO keyboard type.
- Base-layer `; ' , . /` are mod-morphs (`ms_*`) that keep US-style shift pairs (`:` `"` `<` `>` `?`).
- Don't reintroduce Unicode Hex Input (zmk-helpers `HOST_OS 2`): its Option+hex sequences reach terminal apps as Alt+F/Alt+D and move the cursor or delete words.
- Layers are referenced by index, so reordering layers breaks `&td_umlauts 3 TAB`, `&mo 1`, `&mo 2` and the `conditional_layers` node: 0 = default, 1 = lower, 2 = raise, 3 = de_umlauts (umlauts, app-launch macros, window switching, BT), 4 = functional (F-keys, reached by holding lower + raise).
- Custom hold-taps take `<hold tap>` parameters (e.g. `&td LCTRL ESC` = hold Ctrl, tap Esc). They use the `balanced` flavor on purpose: the left-thumb `&td LGUI SPACE` previously misfired as GUI during fast typing (e.g. Space→W became Cmd+W) with `tap-preferred`.
- Keep the ASCII-art comment above each layer's `bindings` in sync when changing bindings. The key-position map at the top of the file (0–41) is what combo `key-positions` use.
- The `combos` block is currently commented out.
