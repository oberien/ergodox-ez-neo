#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_steno.h"

#define HSV_BROWN 15, 255, 150
#define HSV_BLACK 0, 0, 0

enum layers {
  NEO1,
  NEO2_1,
  NEO2_2,
  NEO3,
  NEO4,
  NEO5,
  NEO6,
  QWERTZ,
  QWERTY,
  F_MEDIA,
  STENO,
};

enum custom_keycodes {
  TGL_RGB = SAFE_RANGE,
  LT_NEO4_ENTER,
};

bool rgblight_disabled = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Layer 0: Neo1
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  1  │  2  │  3  │  4  │  5  │STENO│     │ RGB │  6  │  7  │  8  │  9  │  0  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  X  │  V  │  L  │  C  │  W  │ --- │     │ --- │  K  │  H  │  G  │  F  │  Q  │   ß   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │   Y   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │Neo2_1 │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Neo2_2│
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ CTL │ Win │ ALT │ --- │PSCR │                             │ --- │ --- │ ALT │ Win │ CTL │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │  ↑  │  ↓  │ │  ←  │  →  │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │ --- │ │ --- │     │     │
//                             │ SPC │Media├─────┤ ├─────┤Media│ ENT/│
//                             │     │     │ --- │ │ --- │     │ Neo4│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO1] = LAYOUT_ergodox(
    KC_NO,                KC_1,  KC_2,  KC_3,  KC_4, KC_5, TO(STENO),
    KC_TAB,               KC_X,  KC_V,  KC_L,  KC_C, KC_W, KC_NO,
    MO(NEO3),             KC_U,  KC_I,  KC_A,  KC_E, KC_O,
    LM(NEO2_1, MOD_LSFT), DE_UE, DE_OE, DE_AE, KC_P, DE_Z, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO,
    KC_UP, KC_DOWN,
    KC_NO,
    KC_SPC, MO(F_MEDIA), KC_PSCR,

    TGL_RGB, KC_6, KC_7, KC_8,    KC_9,   KC_0, DE_MINS,
    KC_NO,   KC_K, KC_H, KC_G,    KC_F,   KC_Q, DE_SS,
             KC_S, KC_N, KC_R,    KC_T,   KC_D, DE_Y,
    KC_NO,   KC_B, KC_M, KC_COMM, KC_DOT, KC_J, LM(NEO2_2, MOD_LSFT),
    KC_NO, KC_NO, KC_RALT, KC_RGUI, KC_RCTL,
    KC_LEFT, KC_RIGHT,
    KC_NO,
    KC_NO, MO(F_MEDIA), LT_NEO4_ENTER
  ),
// Layer 1: Neo2_1 (Shifted by LShift)
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │       │  °  │  §  │  ℓ  │  »  │  «  │     │     │     │  $  │  €  │  „  │  “  │  ”  │   —   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │   ẞ   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     ├─────┤     ├─────┤     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ XXXXX │     │     │     │     │     │     │     │     │     │     │  –  │  •  │     │  CAPS │
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
    KC_TRNS, DE_RING, DE_PARA, UC(0x2113), UC(0xbb), UC(0xab), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, DE_DLR,  DE_EURO, UC(0x201e), UC(0x201c), UC(0x201d), UC(0x2014),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    UC(0x1e9e),
             KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, UC(0x2013), UC(0x2022), KC_TRNS,    KC_CAPS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// Layer 2: Neo2_2 (Shifted by RShift)
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │       │  °  │  §  │  ℓ  │  »  │  «  │     │     │     │  $  │  €  │  „  │  “  │  ”  │   —   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     │     │     │     │     │     │     │     │     │   ẞ   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │       │     │     │     │     │     ├─────┤     ├─────┤     │     │     │     │     │       │
// ├───────┼─────┼─────┼─────╄─────╃─────┤     │     │     ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ CAPS  │     │     │     │     │     │     │     │     │     │     │  –  │  •  │     │ XXXXX │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │     │     ├─────┤ ├─────┤     │     │
//                             │     │     │     │ │     │     │     │
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO2_2] = LAYOUT_ergodox(
    KC_TRNS, DE_RING, DE_PARA, UC(0x2113), UC(0xbb), UC(0xab), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, DE_DLR,   DE_EURO,  UC(0x201e), UC(0x201c), UC(0x201d), UC(0x2014),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   UC(0x1e9e),
              KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, UC(0x2013), UC(0x2022), KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// Layer 3: Neo3
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ¹  │  ²  │  ³  │  ›  │  ‹  │ --- │     │ --- │  ¢  │  ¥  │  ‚  │  ‘  │  ’  │  ---  │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │ LEAD  │  …  │  _  │  [  │  ]  │  ^  │ --- │     │ --- │  !  │  <  │  >  │  =  │  &  │  ---  │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ XXXXX │  \  │  /  │  {  │  }  │  *  ├─────┤     ├─────┤  ?  │  (  │  )  │  -  │  :  │   @   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │ Neo5  │  #  │  $  │  |  │  ~  │  `  │     │     │     │  +  │  %  │  "  │  '  │  ;  │  ---  │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │     │     │     │     │     │                             │     │     │     │     │     │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │SPC/ │     ├─────┤ ├─────┤     │ ENT/│
//                             │Neo6 │     │     │ │     │     │ Neo6│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO3] = LAYOUT_ergodox(
    KC_NO,    UC(0xb9),   UC(0xb2), UC(0xb3), UC(0x203a), UC(0x2039), KC_NO,
    KC_LEAD,  UC(0x2026), DE_UNDS,  DE_LBRC,  DE_RBRC,    DE_CIRC,    KC_NO,
    KC_TRNS, DE_BSLS,    DE_SLSH,  DE_LCBR,  DE_RCBR,    DE_ASTR,
    MO(NEO5), DE_HASH,    DE_DLR,   DE_PIPE,  DE_TILD,    DE_GRV,     KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    LT(NEO6, KC_SPC), KC_TRNS, KC_TRNS,

    KC_NO, UC(0xa2), UC(0xa5), UC(0x201a), UC(0x2018), UC(0x2019), KC_NO,
    KC_NO, DE_EXLM,  DE_LESS,  DE_MORE,    DE_EQL,     DE_AMPR,    KC_NO,
           DE_QST,   DE_LPRN,  DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,
    KC_NO, DE_PLUS,  DE_PERC,  DE_DQOT,    DE_QUOT,    DE_SCLN,    KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, LT(NEO6, KC_ENTER)
  ),
// Layer 4: Neo4
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ª  │  º  │  №  │ --- │  ·  │ --- │     │ --- │  £  │  ¤  │  ⇥  │  /  │  *  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  ⇞  │  ⌫  │  ↑  │  ⌦  │  ⇟  │ --- │     │ --- │  ¡  │  7  │  8  │  9  │  +  │   −   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo6  │  ⇱  │  ←  │  ↓  │  →  │  ⇲  ├─────┤     ├─────┤  ¿  │  4  │  5  │  6  │  ,  │   .   │
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
  [NEO4] = LAYOUT_ergodox(
    KC_NO,    UC(0xaa), UC(0xba), UC(0x2116), KC_NO,     UC(0xb7), KC_NO,
    KC_TAB,   KC_PGUP,  KC_BSPC,  KC_UP,      KC_DEL,    KC_PGDN,  KC_NO,
    MO(NEO6), KC_HOME,  KC_LEFT,  KC_DOWN,    KC_RIGHT,  KC_END,
    KC_LSFT,    KC_ESC,   KC_TAB,   KC_INS,     KC_ENTER, KC_NO,    KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_KP_0, KC_TRNS, KC_TRNS,
    
    KC_NO, UC(0xa3), UC(0xa4), KC_TAB,  KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
    KC_NO, UC(0xa1), KC_KP_7,  KC_KP_8, KC_KP_9,     KC_KP_PLUS,     UC(0x2212),
           UC(0xbf), KC_KP_4,  KC_KP_5, KC_KP_6,     KC_KP_COMMA,    KC_KP_DOT,
    KC_NO, DE_COLN,  KC_KP_1,  KC_KP_2, KC_KP_3,     KC_SCLN,        KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// Layer 5: Neo5
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
    KC_NO,    UC(0x2081), UC(0x2082), UC(0x2083), UC(0x2640), UC(0x2642), KC_NO,
    KC_NO,    UC(0x3be),  KC_NO,      UC(0x3bb),  UC(0x3c7),  UC(0x3c9),  KC_NO,
    KC_TRNS, KC_NO,      UC(0x3b9),  UC(0x3b1),  UC(0x3b5),  UC(0x3bf),
    KC_TRNS, KC_NO,      UC(0x3f5),  UC(0x3b7),  UC(0x3c0),  UC(0x3b6), KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    UC(0xa0), KC_TRNS, KC_TRNS,

    KC_NO, UC(0x26a5), UC(0x3f0), UC(0x27e8), UC(0x27e9), UC(0x2080), UC(0x2011),
    KC_NO, UC(0x3ba),  UC(0x3c8), UC(0x3b3),  UC(0x3c6),  UC(0x3d5),  UC(0x3c2),
           UC(0x3c3),  UC(0x3bd), UC(0x3c1),  UC(0x3c4),  UC(0x3b4),  UC(0x3c5),
    KC_NO, UC(0x3b2),  UC(0x3bc), UC(0x3f1),  UC(0x3d1),  UC(0x3b8),  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),
// Layer 6: Neo6
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
// Layer 9: F-Keys and Media
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
    KC_NO, KC_F1, KC_F2,   KC_F3,   KC_F4,    KC_F5, KC_F6,
    KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2,  KC_NO, KC_NO,
    KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R,  KC_NO,
    KC_NO, KC_NO, KC_NO,   KC_NO,   KC_PAUSE, KC_NO, KC_NO,
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
// Layer 10: Steno
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
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   TO(NEO1),
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
// Layer X: XXX
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

// Run only after EEPROM is reset to initialize it with default values.
void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

// Run during firmware startup
void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// Runs when any host led indicator changed (NumLock, CapsLock, ScrollLock, Compose, Kana).
bool led_update_user(led_t led_state) {
  // neo always requires for NumLock to be enabled for the KeyPad on Layer 4.
  if (!led_state.num_lock) {
    tap_code(KC_NUMLOCK);
  }
  // set leds
  if (led_state.caps_lock) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
  return true;
}

void set_hsv_layer_color(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_mode(1);
  rgblight_sethsv(hue, sat, val);
}

// Runs every matrix scan to configure rgb lighting
void rgb_matrix_indicators_user(void) {
  if (rgblight_disabled) {
    return;
  }
  const uint8_t F_MEDIA_GREEN_KEYS[] = {0, 1, 2, 3, 4, 24, 25, 26, 27, 28};
  const uint8_t F_MEDIA_SPRINGGREEN_KEYS[] = {11, 12, 13, 14, 30, 31, 32, 35, 36, 37, 40};
  const uint8_t STENO_COLORED_KEYS[] = {
    5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43
  };
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case F_MEDIA:
      for (int i = 0; i < sizeof(F_MEDIA_GREEN_KEYS); i++) {
        rgb_matrix_set_color(F_MEDIA_GREEN_KEYS[i], RGB_GREEN);
      }
      for (int i = 0; i < sizeof(F_MEDIA_SPRINGGREEN_KEYS); i++) {
        rgb_matrix_set_color(F_MEDIA_SPRINGGREEN_KEYS[i], RGB_SPRINGGREEN);
      }
      break;
    case STENO:
      for (int i = 0; i < sizeof(STENO_COLORED_KEYS); i++) {
        rgb_matrix_set_color(STENO_COLORED_KEYS[i], RGB_MAGENTA);
      }
    default:
      return;
  }
}

void set_layer_matrix_colors(uint8_t layer) {
  if (rgblight_disabled) {
    set_hsv_layer_color(HSV_BLACK);
    return;
  }
  switch (layer) {
    case NEO1:
    case NEO2_1:
    case NEO2_2:
      set_hsv_layer_color(HSV_BLUE);
      break;
    case NEO3:
      set_hsv_layer_color(HSV_BROWN);
      break;
    case NEO4:
      set_hsv_layer_color(HSV_YELLOW);
      break;
    case NEO5:
      set_hsv_layer_color(HSV_CYAN);
      break;
    case NEO6:
      set_hsv_layer_color(HSV_RED);
      break;
    case QWERTZ:
    case QWERTY:
      set_hsv_layer_color(HSV_WHITE);
      break;
    case F_MEDIA:
    case STENO:
      set_hsv_layer_color(HSV_BLACK);
      break;
  }
}

static uint16_t lt_neo4_timer;
static bool anything_pressed_during_neo4;
static bool is_neo4_pressed;

// Runs every matrix scan
void matrix_scan_user() {
  if (is_neo4_pressed && !IS_LAYER_ON(NEO4) && timer_elapsed(lt_neo4_timer) >= TAPPING_TERM) {
    layer_on(NEO4);
  }
}

// Runs when a key is pressed before it is forwarded to qmk.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Change behavour of LT(NEO4, KC_ENTER) to make
  // Down(LT), Down(6), Up(LT), Up(6) to register as 6.
  // We needed a custom keycode for this to have perfect responsive lighting.
  if (keycode == LT_NEO4_ENTER) {
    if (record->event.pressed) {
      lt_neo4_timer = timer_read();
      anything_pressed_during_neo4 = false;
      is_neo4_pressed = true;
    } else {
      layer_off(NEO4);
      is_neo4_pressed = false;
      if (!anything_pressed_during_neo4 && timer_elapsed(lt_neo4_timer) < TAPPING_TERM) {
        tap_code(KC_ENTER);
      }
    }
    return false;
  } else {
    if (is_neo4_pressed && record->event.pressed) {
      layer_on(NEO4);
      anything_pressed_during_neo4 = true;
    }
  }
  
  switch (keycode) {
    case TGL_RGB:
      if (record->event.pressed) {
        rgblight_disabled = !rgblight_disabled;
        set_layer_matrix_colors(NEO1);
      }
      return false;
    default:
      return true;
  }
}


// Runs after all basic initialization is done
void keyboard_post_init_user() {
  rgb_matrix_enable();
  set_layer_matrix_colors(NEO1);
}

// Runs every time the layer is changed.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  set_layer_matrix_colors(layer);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();

  switch (layer) {
    // no LED, but Matrix
    case NEO1:
    case NEO2_1:
    case NEO2_2:
    case NEO3:
    case NEO4:
    case NEO5:
    case NEO6:
      break;
    case QWERTY:
    case F_MEDIA:
      ergodox_right_led_1_on();
      break;
    case QWERTZ:
      ergodox_right_led_2_on();
      break;
    case STENO:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    default:
      break;
  }
  return state;
};

