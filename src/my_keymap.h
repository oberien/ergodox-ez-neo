#ifndef MY_KEYMAP_H
#define MY_KEYMAP_H

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_steno.h"

enum layers {
  NEO1_DE,
  NEO1_US,
  QWERTZ,
  QWERTY,
  NEO2_1,
  NEO2_2,
  NEO2_US,
  NEO3_DE,
  NEO3_US,
  NEO4_DE,
  NEO4_US,
  NEO5,
  NEO6,
  F_MEDIA,
  STENO,
};

enum userland_language {
  DE,
  US,
};

enum userland_language userland_language = DE;

void toggle_userland_language(void) {
  if (userland_language == DE) {
    userland_language = US;
    layer_on(NEO1_US);
  } else {
    userland_language = DE;
    layer_off(NEO1_US);
  }
}

void toggle_unicode_input_mode(void) {
  // don't persist, so don't use set_unicode_input_mode, which *does* persist
  if (get_unicode_input_mode() == UC_LNX) {
    unicode_config.input_mode = UC_WIN;
  } else {
    unicode_config.input_mode = UC_LNX;
  }
}

enum custom_keycodes {
  // Neo shifted numbers are mapped differently than DE or US, some of them are even unicode characters.
  // However, with i3-wm, the default is to use Win+Shift+Num to move the active window to workspace Num.
  // That doesn't work anymore, because the keyboard sends different keys and characters.
  // Therefore, we define our own keys to send 1-0 if win is pressed and the neo character otherwise.
  NEO_SFT_1 = SAFE_RANGE,
  NEO_SFT_2,
  NEO_SFT_3,
  NEO_SFT_4,
  NEO_SFT_5,
  NEO_SFT_6,
  NEO_SFT_7,
  NEO_SFT_8,
  NEO_SFT_9,
  NEO_SFT_0,
  TGL_RGB,
  TGL_DE_US,
  TGL_UC_MODE,
  LT_NEO4_ENTER,
  // non-dead keys in German layout (presses dead_key + space)
  ND_CIRC,
  ND_GRAVE,
  // type the current trackball color
  //TB_STATE,
  // neo greek characters with capitalization
  NEO_ALPHA,
  NEO_BETA,
  NEO_GAMMA,
  NEO_DELTA,
  NEO_EPSILON,
  NEO_EPSILON2,
  NEO_ZETA,
  NEO_ETA,
  NEO_THETA,
  NEO_THETA2,
  NEO_IOTA,
  NEO_KAPPA,
  NEO_LAMBDA,
  NEO_MU,
  NEO_NU,
  NEO_XI,
  NEO_OMICRON,
  NEO_PI,
  NEO_RHO,
  NEO_RHO2,
  NEO_SIGMA,
  NEO_SIGMA2,
  NEO_TAU,
  NEO_UPSILON,
  NEO_PHI,
  NEO_PHI2,
  NEO_CHI,
  NEO_PSI,
  NEO_OMEGA,
};

const uint16_t PROGMEM NEO_SFT_KEYS_DE[] = {
  DE_RING, DE_PARA, UC(0x2113), UC(0xbb), UC(0xab),
  DE_DLR, DE_EURO, UC(0x201e), UC(0x201c), UC(0x201d)
};
const uint16_t PROGMEM NEO_SFT_KEYS_US[] = {
  UC(0xb0), UC(0xa7), UC(0x2113), UC(0xbb), UC(0xab),
  KC_DLR, UC(0x20ac), UC(0x201e), UC(0x201c), UC(0x201d)
};

const uint16_t PROGMEM GREEK_KEYS[][2] = {
  [NEO_ALPHA-NEO_ALPHA] =   {UC(0x3b1), UC(0x391)},
  [NEO_BETA-NEO_ALPHA] =    {UC(0x3b2), UC(0x392)},
  [NEO_GAMMA-NEO_ALPHA] =   {UC(0x3b3), UC(0x393)},
  [NEO_DELTA-NEO_ALPHA] =   {UC(0x3b4), UC(0x394)},
  [NEO_EPSILON-NEO_ALPHA] = {UC(0x3b5), UC(0x395)},
  [NEO_EPSILON2-NEO_ALPHA] ={UC(0x3f5), UC(0x395)},
  [NEO_ZETA-NEO_ALPHA] =    {UC(0x3b6), UC(0x396)},
  [NEO_ETA-NEO_ALPHA] =     {UC(0x3b7), UC(0x397)},
  [NEO_THETA-NEO_ALPHA] =   {UC(0x3b8), UC(0x398)},
  [NEO_THETA2-NEO_ALPHA] =  {UC(0x3d1), UC(0x398)},
  [NEO_IOTA-NEO_ALPHA] =    {UC(0x3b9), UC(0x399)},
  [NEO_KAPPA-NEO_ALPHA] =   {UC(0x3ba), UC(0x39a)},
  [NEO_LAMBDA-NEO_ALPHA] =  {UC(0x3bb), UC(0x39b)},
  [NEO_MU-NEO_ALPHA] =      {UC(0x3bc), UC(0x39c)},
  [NEO_NU-NEO_ALPHA] =      {UC(0x3bd), UC(0x39d)},
  [NEO_XI-NEO_ALPHA] =      {UC(0x3be), UC(0x39e)},
  [NEO_OMICRON-NEO_ALPHA] = {UC(0x3bf), UC(0x39f)},
  [NEO_PI-NEO_ALPHA] =      {UC(0x3c0), UC(0x3a0)},
  [NEO_RHO-NEO_ALPHA] =     {UC(0x3c1), UC(0x3a1)},
  [NEO_RHO2-NEO_ALPHA] =    {UC(0x3f1), UC(0x3a1)},
  [NEO_SIGMA-NEO_ALPHA] =   {UC(0x3c3), UC(0x3a3)},
  [NEO_SIGMA2-NEO_ALPHA] =  {UC(0x3c2), UC(0x3a3)},
  [NEO_TAU-NEO_ALPHA] =     {UC(0x3c4), UC(0x3a4)},
  [NEO_UPSILON-NEO_ALPHA] = {UC(0x3c5), UC(0x3a5)},
  [NEO_PHI-NEO_ALPHA] =     {UC(0x3c6), UC(0x3a6)},
  [NEO_PHI2-NEO_ALPHA] =    {UC(0x3d5), UC(0x3a6)},
  [NEO_CHI-NEO_ALPHA] =     {UC(0x3c7), UC(0x3a7)},
  [NEO_PSI-NEO_ALPHA] =     {UC(0x3c8), UC(0x3a8)},
  [NEO_OMEGA-NEO_ALPHA] =   {UC(0x3c9), UC(0x3a9)},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Neo1 (userland language DE)
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  1  │  2  │  3  │  4  │  5  │STENO│     │ RGB │  6  │  7  │  8  │  9  │  0  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  X  │  V  │  L  │  C  │  W  │ QWE │     │DE/US│  K  │  H  │  G  │  F  │  Q  │   ß   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤ RTZ │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │   Y   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │Neo2_1 │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Neo2_2│
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │LCTL │LWin │LALT │ --- │SCLK │                             │     │ Menu│ RALT│ RWin│ RCTL│
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │  ↑  │  ↓  │ │  ←  │  →  │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │NLCK │ │ --- │     │     │
//                             │ SPC │Media├─────┤ ├─────┤Media│ ENT/│
//                             │     │     │PSCR │ │KLOCK│     │ Neo4│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO1_DE] = LAYOUT_ergodox(
    KC_NO,                KC_1,  KC_2,  KC_3,  KC_4, KC_5, TO(STENO),
    KC_TAB,               KC_X,  KC_V,  KC_L,  KC_C, KC_W, TO(QWERTZ),
    MO(NEO3_DE),             KC_U,  KC_I,  KC_A,  KC_E, KC_O,
    LM(NEO2_1, MOD_LSFT), DE_UE, DE_OE, DE_AE, KC_P, DE_Z, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_SLCK,
    KC_UP, KC_DOWN,
    KC_NLCK,
    KC_SPC, MO(F_MEDIA), KC_PSCR,

    TGL_RGB,     KC_6, KC_7, KC_8,    KC_9,   KC_0, DE_MINS,
    TGL_DE_US,   KC_K, KC_H, KC_G,    KC_F,   KC_Q, DE_SS,
                 KC_S, KC_N, KC_R,    KC_T,   KC_D, DE_Y,
    TGL_UC_MODE, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, LM(NEO2_2, MOD_LSFT),
    KC_NO, KC_APP, KC_RALT, KC_RGUI, KC_RCTL,
    KC_LEFT, KC_RIGHT,
    KC_NO,
    //TB_STATE, MO(F_MEDIA), LT_NEO4_ENTER
    KC_LOCK, MO(F_MEDIA), LT_NEO4_ENTER
  ),
  [NEO1_US] = LAYOUT_ergodox(
    _______, _______,  _______,  _______,  _______, _______, _______,
    _______, _______,  _______,  _______,  _______, _______, _______,
    _______, _______,  _______,  _______,  _______, _______,
    _______, UC(0xfc), UC(0xf6), UC(0xe4), _______, KC_Z,    _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, KC_MINS,
    _______, _______, _______, _______, _______, _______, UC(0xdf),
             _______, _______, _______, _______, _______, KC_Y,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
// QWERTZ
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ^/°  │ 1/! │2/"/²│3/§/³│ 4/$ │ 5/% │ --- │     │ --- │ 6/& │7///{│8/(/[│9/(/]│0/=/}│ ß/?/\ │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │  TAB  │ Q/@ │  W  │ E/€ │  R  │  T  │ QWE │     │     │  Z  │  U  │  I  │  O  │  P  │   Ü   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤ RTZ │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo3  │  A  │  S  │  D  │  F  │  G  ├─────┤     ├─────┤  H  │  J  │  K  │  L  │  Ö  │   Ä   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ LSFT  │  Y  │  X  │  C  │  V  │  B  │     │     │     │  N  │  M  │  ,  │  .  │  -  │  RSFT │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │LCTL │LWin │LAlt │LAlt │LAlt │                             │KLOCK│ --- │ RAlt│ RWin│ RCTL│
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │ --- │ │ --- │     │     │
//                             │ SPC │Media├─────┤ ├─────┤Media│ ENT │
//                             │     │     │ --- │ │ --- │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [QWERTZ] = LAYOUT_ergodox(
    ND_CIRC,     KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
    KC_TAB,      KC_Q, KC_W, KC_E, KC_R, KC_T, TO(NEO1_DE),
    MO(NEO3_DE), KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSFT,     DE_Y, KC_X, KC_C, KC_V, KC_B, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_LALT,
    KC_TRNS, KC_TRNS,
    KC_NO,
    KC_SPC, MO(F_MEDIA), KC_NO,

    KC_NO,   KC_6, KC_7, KC_8,    KC_9,   KC_0,    DE_SS,
    KC_TRNS, DE_Z, KC_U, KC_I,    KC_O,   KC_P,    DE_UE,
             KC_H, KC_J, KC_K,    KC_L,   DE_OE,   DE_AE,
    KC_NO,   KC_N, KC_M, KC_COMM, KC_DOT, DE_MINS, KC_RSFT,
    KC_NO, KC_NO, KC_RALT, KC_RGUI, KC_RCTL,
    KC_TRNS, KC_TRNS,
    KC_NO,
    KC_LOCK, MO(F_MEDIA), LT_NEO4_ENTER
  ),
  [QWERTY] = LAYOUT_ergodox(
    KC_GRAVE, _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______,
    _______,  KC_Z,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, KC_MINS,
    _______, KC_Y,    _______, _______, _______, _______, KC_LBRC,
             _______, _______, _______, _______, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, KC_SLSH, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
// Neo2_1 (Shifted by LShift)
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │       │ 1/° │ 2/§ │ 3/ℓ │ 4/» │ 5/« │     │     │     │ 6/$ │ 7/€ │ 8/„ │ 9/“ │ 0/” │   —   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │   ẞ   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     ├─────┤     ├─────┤     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
// │XX/CAPS│     │     │     │     │     │     │     │     │     │     │  –  │  •  │     │XX/CAPS│
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │     │     ├─────┤ ├─────┤     │     │
//                             │     │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO2_1] = LAYOUT_ergodox(
    KC_TRNS, NEO_SFT_1, NEO_SFT_2, NEO_SFT_3, NEO_SFT_4, NEO_SFT_5, KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, NEO_SFT_6, NEO_SFT_7, NEO_SFT_8,  NEO_SFT_9,  NEO_SFT_0, UC(0x2014),
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   UC(0x1e9e),
             KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   UC(0x2013), UC(0x2022), KC_TRNS,   KC_CAPS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [NEO2_2] = LAYOUT_ergodox(
    KC_TRNS, NEO_SFT_1, NEO_SFT_2, NEO_SFT_3, NEO_SFT_4, NEO_SFT_5, KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_CAPS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, NEO_SFT_6, NEO_SFT_7, NEO_SFT_8,  NEO_SFT_9,   NEO_SFT_0, UC(0x2014),
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    UC(0x1e9e),
             KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   UC(0x2013), UC(0x2022), KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [NEO2_US] = LAYOUT_ergodox(
    _______, _______,  _______,  _______,  _______, _______, _______,
    _______, _______,  _______,  _______,  _______, _______, _______,
    _______, _______,  _______,  _______,  _______, _______,
    _______, UC(0xdc), UC(0xd6), UC(0xc4), _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
// Neo3
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ¹  │  ²  │  ³  │  ›  │  ‹  │ --- │     │ --- │  ¢  │  ¥  │  ‚  │  ‘  │  ’  │  ---  │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │COMPOSE│  …  │  _  │  [  │  ]  │  ^  │ --- │     │ --- │  !  │  <  │  >  │  =  │  &  │  ---  │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ XXXXX │  \  │  /  │  {  │  }  │  *  ├─────┤     ├─────┤  ?  │  (  │  )  │  -  │  :  │   @   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │(Neo5) │  #  │  $  │  |  │  ~  │  `  │     │     │     │  +  │  %  │  "  │  '  │  ;  │ (Neo5)│
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │     │     ├─────┤ ├─────┤     │(ENT/│
//                             │     │     │     │ │     │     │Neo6)│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO3_DE] = LAYOUT_ergodox(
    KC_NO,   UC(0xb9),   UC(0xb2), UC(0xb3), UC(0x203a), UC(0x2039), KC_NO,
    KC_LEAD, UC(0x2026), DE_UNDS,  DE_LBRC,  DE_RBRC,    ND_CIRC,    KC_NO,
    KC_TRNS, DE_BSLS,    DE_SLSH,  DE_LCBR,  DE_RCBR,    DE_ASTR,
    KC_TRNS, DE_HASH,    DE_DLR,   DE_PIPE,  DE_TILD,    ND_GRAVE,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_NO, UC(0xa2), UC(0xa5), UC(0x201a), UC(0x2018), UC(0x2019), KC_NO,
    KC_NO, DE_EXLM,  DE_LESS,  DE_MORE,    DE_EQL,     DE_AMPR,    KC_NO,
           DE_QST,   DE_LPRN,  DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,
    KC_NO, DE_PLUS,  DE_PERC,  DE_DQOT,    DE_QUOT,    DE_SCLN,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [NEO3_US] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______,  _______,
    _______, _______, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC,  _______,
    _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR,
    _______, KC_HASH, KC_DLR,  KC_PIPE, KC_TILD, KC_GRAVE, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM, KC_LT,   KC_GT,   KC_EQL,  KC_AMPR, _______,
             KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT,
    _______, KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
// Neo4
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ª  │  º  │  №  │ --- │  ·  │ --- │     │ --- │  £  │  ¤  │  ⇥  │  /  │  *  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  ⇞  │  ⌫  │  ↑  │  ⌦  │  ⇟  │ --- │     │ --- │  ¡  │  7  │  8  │  9  │  +  │   −   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │(Neo6) │  ⇱  │  ←  │  ↓  │  →  │  ⇲  ├─────┤     ├─────┤  ¿  │  4  │  5  │  6  │  ,  │   .   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ Shift │  ⌧  │  ⇥  │  ⎀  │  ⏎  │ --- │     │     │     │  :  │  1  │  2  │  3  │  ;  │ Shift │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │XXX/ │     ├─────┤ ├─────┤     │ XXX │
//                             │ 0   │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO4_DE] = LAYOUT_ergodox(
    KC_NO,    UC(0xaa), UC(0xba), UC(0x2116), KC_NO,     UC(0xb7), KC_NO,
    KC_TAB,   KC_PGUP,  KC_BSPC,  KC_UP,      KC_DEL,    KC_PGDN,  KC_NO,
    KC_TRNS, KC_HOME,  KC_LEFT,  KC_DOWN,    KC_RIGHT,  KC_END,
    KC_LSFT,    KC_ESC,   KC_TAB,   KC_INS,     KC_ENTER, KC_NO,    KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_KP_0, KC_TRNS, KC_TRNS,
    
    KC_NO, UC(0xa3), UC(0xa4), KC_TAB,  KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
    KC_NO, UC(0xa1), KC_KP_7,  KC_KP_8, KC_KP_9,     KC_KP_PLUS,     UC(0x2212),
           UC(0xbf), KC_KP_4,  KC_KP_5, KC_KP_6,     KC_KP_COMMA,    KC_KP_DOT,
    KC_NO, DE_COLN,  KC_KP_1,  KC_KP_2, KC_KP_3,     DE_SCLN,        KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [NEO4_US] = LAYOUT_ergodox(
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______,

    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,
    _______, KC_COLN, _______, _______, _______, KC_SCLN, _______,
    _______, _______, _______, _______, _______,
    _______, _______,
    _______,
    _______, _______, _______
  ),
// Neo5
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ₁  │  ₂  │  ₃  │  ♀  │  ♂  │ --- │     │ --- │  ⚥  │  ϰ  │  ⟨  │  ⟩  │  ₀  │  🔒‑   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │  ---  │  ξ  │ --- │  λ  │  χ  │  ω  │ --- │     │ --- │  κ  │  ψ  │  γ  │  φ  │  ϕ  │   ς   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ XXXXX │ --- │  ι  │  α  │  ε  │  ο  ├─────┤     ├─────┤  σ  │  ν  │  ρ  │  τ  │  δ  │   υ   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ XXXXX │ --- │  ϵ  │  η  │  π  │  ζ  │     │     │     │  β  │  μ  │  ϱ  │  ϑ  │  θ  │ XXXXX │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │NBSP │     ├─────┤ ├─────┤     │     │
//                             │     │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO5] = LAYOUT_ergodox(
    KC_NO,   UC(0x2081), UC(0x2082),   UC(0x2083), UC(0x2640),  UC(0x2642),  KC_NO,
    KC_NO,   NEO_XI,     KC_NO,        NEO_LAMBDA, NEO_CHI,     NEO_OMEGA,   KC_NO,
    KC_TRNS, KC_NO,      NEO_IOTA,     NEO_ALPHA,  NEO_EPSILON, NEO_OMICRON,
    KC_TRNS, KC_NO,      NEO_EPSILON2, NEO_ETA,    NEO_PI,      NEO_ZETA,    KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    UC(0xa0), KC_TRNS, KC_TRNS,

    KC_NO, UC(0x26a5), UC(0x3f0), UC(0x27e8), UC(0x27e9), UC(0x2080), UC(0x2011),
    KC_NO, NEO_KAPPA,  NEO_PSI,   NEO_GAMMA,  NEO_PHI,    NEO_PHI2,   NEO_SIGMA2,
           NEO_SIGMA,  NEO_NU,    NEO_RHO,    NEO_TAU,    NEO_DELTA,  NEO_UPSILON,
    KC_NO, NEO_BETA,   NEO_MU,    NEO_RHO2,   NEO_THETA2, NEO_THETA,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// Neo6
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ¬  │  ∨  │  ∧  │  ⊥  │  ∡  │ --- │     │ --- │  ∥  │  →  │  ∞  │  ∝  │  ∅  │   ­   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │  ---  │  Ξ  │  √  │  Λ  │  ℂ  │  Ω  │ --- │     │ --- │  ×  │  Ψ  │  Γ  │  Φ  │  ℚ  │   ∘   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ XXXXX │  ⊂  │  ∫  │  ∀  │  ∃  │  ∈  ├─────┤     ├─────┤  Σ  │  ℕ  │  ℝ  │  ∂  │  Δ  │   ∇   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │  ---  │  ∪  │  ∩  │  ℵ  │  Π  │  ℤ  │     │     │     │  ⇐  │  ⇔  │  ⇒  │  ↦  │  Θ  │  ---  │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │NAROW│     │     │ │     │     │     │
//                             │NBSP │     ├─────┤ ├─────┤     │ XXX │
//                             │     │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO6] = LAYOUT_ergodox(
    KC_NO,    UC(0xac),   UC(0x2228), UC(0x2227), UC(0x22a5), UC(0x2221), KC_NO,
    KC_NO,    UC(0x39e),  UC(0x221a), UC(0x39b),  UC(0x2102), UC(0x3a9),  KC_NO,
    KC_TRNS, UC(0x2282), UC(0x222b), UC(0x2200), UC(0x2203), UC(0x2208),
    KC_NO,    UC(0x222a), UC(0x2229), UC(0x2135), UC(0x3a0),  UC(0x2124), KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    UC(0x202f), KC_TRNS, KC_TRNS,

    KC_NO, UC(0x2225), UC(0x2192), UC(0x221e), UC(0x221d), UC(0x2205), UC(0xad),
    KC_NO, UC(0xd7),   UC(0x3a8),  UC(0x393),  UC(0x3a6),  UC(0x211a), UC(0x2218),
           UC(0x3a3),  UC(0x2115), UC(0x211d), UC(0x2202), UC(0x394),  UC(0x2207),
    KC_NO, UC(0x21d0), UC(0x21d4), UC(0x21d2), UC(0x21a6), UC(0x398),  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// F-Keys and Media
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │     │  F7 │  F8 │  F9 │ F10 │ F11 │ F12 │  ---  │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │  ---  │ --- │ LMB │ M🡅  │ RMB │ --- │ --- │     │ --- │ --- │ --- │ --- │ --- │ --- │  ---  │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │  ---  │ --- │ M🡄  │ M🡇  │ M🡆  │ --- ├─────┤     ├─────┤ --- │  ▶⏸ │  ⏹  │  ⏮  │  ⏭  │  ---  │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │  ---  │ --- │ --- │ --- │PAUSE│ --- │     │     │     │ --- │ --- │ --- │ --- │ --- │  ---  │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │ --- │ --- │ │ --- │ --- │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │ --- │ │ --- │     │     │
//                             │ --- │ XXX ├─────┤ ├─────┤ XXX │ --- │
//                             │     │     │ --- │ │ --- │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [F_MEDIA] = LAYOUT_ergodox(
    KC_NO, KC_F1, KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,
    KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2,  KC_WH_U, KC_NO,
    KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R,  KC_WH_D,
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_PAUSE, KC_NO,   KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_TRNS, KC_NO,

    KC_F7, KC_F8, KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_NO,
    KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
           KC_NO, KC_MPLY, KC_MSTP,  KC_MPRV,  KC_MNXT,  KC_NO,
    KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_TRNS, KC_NO
  ),
// Steno
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │ --- │ --- │ --- │ --- │ --- │STENO│     │ --- │ --- │ --- │ --- │ --- │ --- │  ---  │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   #   │  #  │  #  │  #  │  #  │  #  │ --- │     │ --- │  #  │  #  │  #  │  #  │  #  │   #   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │  FN   │  S  │  T  │  P  │  H  │  *  ├─────┤     ├─────┤  *  │  F  │  P  │  L  │  T  │   D   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │  ---  │  S  │  K  │  W  │  R  │  *  │     │     │     │  *  │  R  │  B  │  G  │  S  │   Z   │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │ --- │ --- │ │ --- │ --- │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │ --- │ │ --- │     │     │
//                             │  A  │  O  ├─────┤ ├─────┤  E  │  U  │
//                             │     │     │ --- │ │ --- │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [STENO] = LAYOUT_ergodox(
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   TO(NEO1_DE),
    STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, STN_N6,  KC_NO,
    STN_FN, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST2,
    KC_NO,  STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    STN_A, STN_O, KC_NO,
    
    KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO, STN_N7,  STN_N8, STN_N9, STN_NA, STN_NB, STN_NC,
           STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
    KC_NO, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, STN_E, STN_U
  ),
// XXX
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     ├─────┤     ├─────┤     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │     │     ├─────┤ ├─────┤     │     │
//                             │     │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  //[XXX] = LAYOUT_ergodox(
  //),
};
#endif
