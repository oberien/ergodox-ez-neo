# Ergodox EZ neo

This is an implementation of the German [neo-layout](https://neo-layout.org/) for the QMK firmware for the [Ergodox EZ Keyboard](https://ergodox-ez.com/).

# Features

Neo:

- [x] no userland neo layout required
- [x] supports Caps-Lock via pressing both `Shift` keys at the same time
- [x] supports Unicode (neo layers 5/6) on Linux via ibus
- [ ] on layer 5 writes capital Greek letters if CapsLock is active
- [ ] switch for supporting userland `de` and `us` keyboard layouts (currently `de` required)

QWERTZ / QWERTY:

- [ ] qwertz for gaming such that key remapping isn't required for each game
- [ ] qwerty as option if userland has `us` keyboard layout

Steno / Plover:

- [ ] enables N-Key-RollOver (NKRO)
- [ ] layer for English stenography
    * requires userland-driver `Plover`
    * uses TX Bolt protocol for English
- [ ] support for both English and German (German via GeminiPR?)
* (onboard translation not possible due to very small flash of the keyboard)

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
