COMPOSE_ONBOARD_DICTIONARY(
    // ARROWS
    // ←
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_LESS, DE_MINS), tap_key(UC(0x2190));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_LT, KC_MINS), tap_key(UC(0x2190));)
    // ↑
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_PIPE, DE_CIRC), tap_key(UC(0x2191));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_PIPE, KC_CIRC), tap_key(UC(0x2191));)
    // →
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_MINS, DE_MORE), tap_key(UC(0x2192));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_MINS, KC_GT), tap_key(UC(0x2192));)
    // ↓
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_V, DE_PIPE), tap_key(UC(0x2193));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_V, KC_PIPE), tap_key(UC(0x2193));)
    // ↔
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_LESS, DE_MORE), tap_key(UC(0x2194));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_LT, KC_GT), tap_key(UC(0x2194));)
    // ↕
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_V, DE_CIRC), tap_key(UC(0x2195));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_V, KC_CIRC), tap_key(UC(0x2195));)

    // COMPARISON
    // ≠
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_SLSH, DE_EQL), tap_key(UC(0x2260));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_SLSH, KC_EQL), tap_key(UC(0x2260));)
    // ≡
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_EQL, DE_EQL), tap_key(UC(0x2261));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_EQL, KC_EQL), tap_key(UC(0x2261));)
    // ≤
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_LESS, DE_EQL), tap_key(UC(0x2264));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_LT, KC_EQL), tap_key(UC(0x2264));)
    // ≥
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_MORE, DE_EQL), tap_key(UC(0x2265));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_GT, KC_EQL), tap_key(UC(0x2265));)
    // ≈
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_TILD, DE_TILD), tap_key(UC(0x2248));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_TILD, KC_TILD), tap_key(UC(0x2248));)
    
    // SMILES
    // ☹
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_COLN, DE_LPRN), tap_key(UC(0x2639));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_COLN, KC_LPRN), tap_key(UC(0x2639));)
    // ☺
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(DE_COLN, DE_RPRN), tap_key(UC(0x263a));)
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_COLN, KC_RPRN), tap_key(UC(0x263a));)
    

    // OTHERS
    // shrug
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_S, KC_H, KC_R, KC_U, KC_G), {tap_key(UC(0xaf)); tap_key(UC(0x5c)); tap_key(UC(0x5f)); tap_key(UC(0x28)); tap_key(UC(0x30c4)); tap_key(UC(0x29)); tap_key(UC(0x5f)); tap_key(UC(0x2f)); tap_key(UC(0xaf));})
    // ™
    COMPOSE_ONBOARD_MAPPING(COMPOSE_ONBOARD_INPUT(KC_T, KC_M), tap_key(UC(0x2122));)
)

void compose_onboard_start() {
  ergodox_right_led_1_on();
}
void compose_onboard_end() {
  ergodox_right_led_1_off();
}
