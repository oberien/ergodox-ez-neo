#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

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
  STENO,
}

enum custom_keycodes {
  //FIRST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Layer 0: Neo1
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  1  │  2  │  3  │  4  │  5  │ --- │     │ --- │  6  │  7  │  8  │  9  │  0  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  X  │  V  │  L  │  C  │  W  │ --- │     │ --- │  K  │  H  │  G  │  F  │  Q  │   ß   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │   Y   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │Neo2_1 │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Neo2_2│
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ CTL │ Win │ ALT │ --- │ --- │                             │ --- │ --- │ ALT │ Win │ CTL │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │ --- │ --- │ │ --- │ --- │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │ --- │ │ --- │     │     │
//                             │SPC/ │ --- ├─────┤ ├─────┤ --- │ RTN/│
//                             │Neo4 │     │ --- │ │ --- │     │ Neo4│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO1] = LAYOUT_ergodox(
    KC_NO,                KC_1,  KC_2,  KC_3,  KC_4, KC_5, KC_NO,
    KC_TAB,               KC_X,  KC_V,  KC_L,  KC_C, KC_W, KC_NO,
    MO(NEO3),             KC_U,  KC_I,  KC_A,  KC_E, KC_O,
    LM(NEO2_1, MOD_LSFT), DE_UE, DE_OE, DE_AE, KC_P, KC_Z, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO,
    KC_NO, KC_NO,
    KC_NO,
    LT(KC_SPC, NEO4), KC_NO, KC_NO,

    KC_NO, KC_6, KC_7, KC_8,    KC_9,   KC_0, DE_MINS,
    KC_NO, KC_K, KC_H, KC_G,    KC_F,   KC_Q, DE_SS,
           KC_S, KC_N, KC_R,    KC_T,   KC_D, KC_Y,
    KC_NO, KC_B, KC_M, KC_COMM, KC_DOT, KC_J, LM(NEO2_2, MOD_LSFT),
    KC_NO, KC_NO,
    KC_NO,
    KC_NO, KC_NO, LT(KC_RTN, NEO4)
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
    KC_TRANS, DE_RING,  DE_PARA,  UC(0x2113), UC(0xbb), UC(0xab), KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS, KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS, KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,

    KC_TRANS, DE_DLR,   DE_EURO,  UC(0x201e), UC(0x201c), UC(0x201d), UC(0x2014),
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,   KC_TRANS,   UC(0x1e9e),
              KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,   KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, UC(0x2013), UC(0x2022),   KC_TRANS,   KC_CAPS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,
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
    KC_TRANS, DE_RING,  DE_PARA,  UC(0x2113), UC(0xbb), UC(0xab), KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS, KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS,
    KC_CAPS,  KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS, KC_TRANS, KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,

    KC_TRANS, DE_DLR,   DE_EURO,  UC(0x201e), UC(0x201c), UC(0x201d), UC(0x2014),
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,   KC_TRANS,   UC(0x1e9e),
              KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,   KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, UC(0x2013), UC(0x2022), KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,   KC_TRANS,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS
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
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
//   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
//                                   │     │     │ │     │     │
//                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
//                             │     │     │     │ │     │     │     │
//                             │SPC/ │     ├─────┤ ├─────┤     │ RET/│
//                             │Neo6 │     │     │ │     │     │ Neo6│
//                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
  [NEO3] = LAYOUT_ergodox(
    KC_NO,    UC(0xb9),   UC(0xb2), UC(0xb3), UC(0x203a), UC(0x2039), KC_NO,
    KC_LEAD,  UC(0x2026), DE_UNDS,  DE_LBRC,  DE_RBRC,    DE_CIRC,    KC_NO,
    KC_TRANS, DE_BSLS,    DE_SLSH,  DE_LCBR,  DE_RCBR,    DE_ASTR,
    MO(NEO5), DE_HASH,    DE_DLR,   DE_PIPE,  DE_TILD,    DE_GRV,     KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    LT(KC_SPC, NEO6), KC_TRANS, KC_TRANS,

    KC_NO, UC(0xa2), UC(0xa5), UC(0x201a), UC(0x2018), UC(0x2019), KC_NO,
    KC_NO, DE_EXLM,  DE_LESS,  DE_MORE,    DE_EQL,     DE_AMPR,    KC_NO,
           DE_QST,   DE_LPRN,  DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,
    KC_NO, DE_PLUS,  DE_PERC,  DE_DQOT,    DE_QUOT,    DE_SCLN,    KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, LT(KC_RET, NEO6)
  ),
// Layer 4: Neo4
// ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
// │  ---  │  ª  │  º  │  №  │ --- │  ·  │ --- │     │ --- │  £  │  ¤  │  ⇥  │  /  │  *  │   -   │
// ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
// │   ⇥   │  ⇞  │  ⌫  │  ↑  │  ⌦  │  ⇟  │ --- │     │ --- │  ¡  │  7  │  8  │  9  │  +  │   −   │
// ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
// │ Neo6  │  ⇱  │  ←  │  ↓  │  →  │  ⇲  ├─────┤     ├─────┤  ¿  │  4  │  5  │  6  │  ,  │   .   │
// ├───────┼─────┼─────┼─────╄─────╃─────┤ --- │     │ --- ├─────╄─────╃─────┼─────┼─────┼───────┤
// │  ---  │  ⌧  │  ⇥  │  ⎀  │  ⏎  │ --- │     │     │     │  :  │  1  │  2  │  3  │  ;  │  ---  │
// └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
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
    KC_NO,    KC_ESC,   KC_TAB,   KC_INS,     KC_RETURN, KC_NO,    KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_KP_0, KC_TRANS, KC_TRANS,
    
    KC_NO, UC(0xa3), UC(0xa4), KC_TAB,  KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
    KC_NO, UC(0xa1), KC_KP_7,  KC_KP_8, KC_KP_9,     KC_KP_PLUS,     UC(0x2212),
           UC(0xbf), KC_KP_4,  KC_KP_5, KC_KP_6,     KC_KP_COMMA,    KC_KP_DOT,
    KC_NO, DE_COLN,  KC_KP_1,  KC_KP_2, KC_KP_3,     KC_SCLN,        KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,
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
//   │ --- │ --- │ --- │ --- │ --- │                             │ --- │ --- │ --- │ --- │ --- │
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
    KC_TRANS, KC_NO,      UC(0x3b9),  UC(0x3b1),  UC(0x3b5),  UC(0x3bf),
    KC_TRANS, KC_NO,      UC(0x3f5),  UC(0x3b7),  UC(0x3c0),  UC(0x3b6), KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    UC(0xa0), KC_TRANS, KC_TRANS,

    KC_NO, UC(0x26a5), UC(0x3f0), UC(0x27e8), UC(0x27e9), UC(0x2080), UC(0x2011),
    KC_NO, UC(0x3ba),  UC(0x3c8), UC(0x3b3),  UC(0x3c6),  UC(0x3d5),  UC(0x3c2),
           UC(0x3c3),  UC(0x3bd), UC(0x3c1),  UC(0x3c4),  UC(0x3b4),  UC(0x3c5),
    KC_NO, UC(0x3b2),  UC(0x3bc), UC(0x3f1),  UC(0x3d1),  UC(0x3b8),  KC_TRANS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,
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
    KC_TRANS, UC(0x2282), UC(0x222b), UC(0x2200), UC(0x2203), UC(0x2208),
    KC_NO,    UC(0x222a), UC(0x2229), UC(0x2135), UC(0x3a0),  UC(0x2124), KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    UC(0x202f), KC_TRANS, KC_TRANS,

    KC_NO, UC(0x2225), UC(0x2192), UC(0x221e), UC(0x221d), UC(0x2205), UC(0xad),
    KC_NO, UC(0xd7),   UC(0x3a8),  UC(0x393),  UC(0x3a6),  UC(0x211a), UC(0x2218),
           UC(0x3a3),  UC(0x2115), UC(0x211d), UC(0x2202), UC(0x394),  UC(0x2207),
    KC_NO, UC(0x21d0), UC(0x21d4), UC(0x21d2), UC(0x21a6), UC(0x398),  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANS, KC_TRANS,
    KC_TRANS,
    KC_TRANS, KC_TRANS, KC_TRANS,
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

// Runs before the keycode is passed to the core.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

// Runs when any host led indicator changed (e.g. CapsLock has been pressed).
bool led_update_user(led_t led_state) {
  if (led_state.caps_lock) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

// Runs every time the layer is changed.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();

  switch (layer) {
    case NEO1:
    case NEO2_1:
    case NEO2_2:
    case NEO3:
    case NEO4:
    case NEO5:
    case NEO6:
      // no LED
      break;
    case QWERTY:
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
