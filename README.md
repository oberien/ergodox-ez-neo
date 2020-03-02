# Ergodox EZ neo

This is an implementation of the German [neo-layout](https://neo-layout.org/) for the QMK firmware for the [Ergodox EZ Keyboard](https://ergodox-ez.com/).

# Features

Neo:

- [x] no userland neo layout required
- [x] supports Caps-Lock via pressing both `Shift` keys at the same time
- [x] supports lowercase `ß` and uppercase `ẞ`
- [x] supports Unicode (neo layers 5/6) on Linux via ibus
- [x] keypad on Layer 4 sends keypad keycodes
* [x] Num-Lock is always enabled 
    * if it is disabled, it'll be enabled again by sending a Num-Lock key press
    * required by neo layer 4 keypad
- [x] sends Win+Shift+(1-0) instead of Win+Neo2 characters to support i3-wm move to workspace
- [x] on layer 5 writes capital Greek letters if CapsLock is active
- [x] button to switch sent keycodes to support both userland `de` and `us` keyboard layouts

QWERTZ / QWERTY:

- [x] qwertz for gaming such that key remapping isn't required for each game
- [x] qwertz / qwerty switch (via same switch to toggle `de` / `us` for neo)

Steno / Plover:

- [x] layer for English stenography
    * requires userland-driver `Plover`
    * uses GeminiPR protocol for English
- [ ] support for both English and German (English via TX Bolt and German via GeminiPR?)
* (onboard translation not possible due to very small flash of the keyboard)

Others:

- [x] F1-F12 Keys, Media Keys and Mouse Keys on extra layer
* [x] NKRO enabled
* [x] correct tri layers for neo layers 5/6 (manually implemented, *not* using `update_tri_layer_state`)
- [x] Applies the [qmk/qmk_firmware#2710](https://github.com/qmk/qmk_firmware/pull/2710) patch to allow rolling <> and similar

RGB Matrix / Lighting:

* [x] different RGB light per layer
* [x] for the F-Media and Steno layers only light up used keys
* [ ] add special lighting for qwertz / qwerty

# Build

1. Install an environment for AVR or/and ARM development as described in <https://docs.qmk.fm/>.
1. Clone the Ergodox EZ fork of qmk_firmware by zsa, making sure to also fetch submodules (`--recurse-submodules`) from <https://github.com/zsa/qmk_firmware/>.
1. Copy this repository's `src` folder to `qmk_firmware/keyboards/ergodox_ez/keymaps/neo-oberien`.
1. Change directory to `qmk_firmware`.
1. Setup QMK's environment by following the instructions at <https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment>.
1. Test that the environment is completely set up by running `make ergodox_ez:default`.
1. Actually build this repository's firmware by running `make ergodox_ez:neo-oberien`.
1. Install and set up the flash tool by following its guide at <https://ergodox-ez.com/pages/wally>.
1. Flash the firmware

On Arch Linux:

```sh
pacman -S base-devel gcc unzip wget zip avr-gcc avr-binutils avr-libc dfu-util arm-none-eabi-gcc arm-none-eabi-binutils arm-none-eabi-newlib git dfu-programmer dfu-util
git clone https://github.com/zsa/qmk_firmware/
cp -r src qmk_firmware/keyboards/ergodox_ez/keymaps/neo-oberien
cd qmk_firmware
sh util/qmk_install.sh
make ergodox_ez:default
make ergodox_ez:neo-oberien
pikaur -S zsa-wally
zsa-wally
```

# Related Work

QMK Links:

* [QMK Features](https://github.com/qmk/qmk_firmware/blob/master/docs/features.md)
* [QMK Documentation](https://beta.docs.qmk.fm/)

Keyboard Layouts:

* [coderkun_neo2](https://github.com/qmk/qmk_firmware/blob/master/layouts/community/ergodox/coderkun_neo2/keymap.c): neo-layout with userland driver active; writes qwertz characters to be mapped by the userland driver (the PMN layer writes neo directly); Layers 1/(2)/4
* [neo2--tschulte](https://github.com/tschulte/ergodox-firmware/blob/neo2/firmware/keyboard/ergodox/layout/neo2--tschulte.c): neo-layout in firmware; Layers 1/(2)/3/4
* [osx_neo2](https://github.com/qmk/qmk_firmware/blob/7c0f2ae6d1c1d3f168a5919287b6608b092b3dba/layouts/community/ergodox/osx_neo2/keymap.c): Neo2 for OSX; All in all pretty good; Layers 1/2/3/4, QWERTY, Fn
* [not-quite-neo](https://github.com/qmk/qmk_firmware/blob/ee700b2e831067bdb7584425569b61bc6329247b/keyboards/ergodox_infinity/keymaps/not-quite-neo/keymap.c): Defines neo for both Planck and Ergodox Infinity with tradeoffs; A lot of macro magic; Layers 1/2/3/4, Fn

* [Discussion around Ergodox Neo2](https://geekhack.org/index.php?topic=55407.0)
* [Neo for the Maltron](https://geekhack.org/index.php?topic=57559.msg1316000#msg1316000)
* [German](https://github.com/qmk/qmk_firmware/blob/master/layouts/community/ergodox/coderkun_neo2/keymap.c): default German keyboard layout for the Ergodox EZ
