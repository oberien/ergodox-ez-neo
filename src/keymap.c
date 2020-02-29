#include "my_keymap.h"
#include "lighting.c"
#include "helper.c"

// Run only after EEPROM is reset to initialize it with default values.
void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

// Run during firmware startup
void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// Runs when any host led indicator changes (NumLock, CapsLock, ScrollLock, Compose, Kana).
bool led_update_user(led_t led_state) {
  // neo always requires for NumLock to be enabled for the KeyPad on Layer 4.
  if (!led_state.num_lock) {
    tap_key(KC_NUMLOCK);
  }
  leds_set_for_host_indicators(led_state);
  return true;
}

// Runs every matrix scan to configure rgb lighting
void rgb_matrix_indicators_user(void) {
  lighting_rgb_matrix_indicators();
}

static uint16_t lt_neo4_timer;
static bool anything_pressed_during_neo4;
static bool is_neo4_pressed;

// Runs every matrix scan
void matrix_scan_user(void) {
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
        tap_key(KC_ENTER);
      }
    }
    return false;
  } else {
    if (is_neo4_pressed && record->event.pressed) {
      layer_on(NEO4);
      anything_pressed_during_neo4 = true;
    }
  }
  
  // Win+Shift+Num fix (see custom keycode definition)
  if (NEO_SFT_1 <= keycode && keycode <= NEO_SFT_0) {
    uint8_t win_pressed = get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
    uint16_t num_index = keycode-NEO_SFT_1;
    if (win_pressed) {
      _Static_assert(KC_1 + 9 == KC_0 && NEO_SFT_1 + 9 == NEO_SFT_0, "number key mapping invalid");
      press_or_release_key(KC_1 + num_index, record->event.pressed);
    } else {
      uint16_t neo2_chars[] = { DE_RING, DE_PARA, UC(0x2113), UC(0xbb), UC(0xab),
        DE_DLR, DE_EURO, UC(0x201e), UC(0x201c), UC(0x201d) };
      uint16_t keycode = neo2_chars[num_index];
      press_or_release_key(keycode, record->event.pressed);
    }
    return false;
  }

  if (NEO_ALPHA <= keycode && keycode <= NEO_OMEGA) {
    uint16_t index = keycode - NEO_ALPHA;
    bool capslock_on = host_keyboard_led_state().caps_lock;
    uint16_t keycode = pgm_read_word(&GREEK_KEYS[index][capslock_on]);
    press_or_release_key(keycode, record->event.pressed);
  }

  switch (keycode) {
    case TGL_RGB:
      if (record->event.pressed) {
        toggle_lighting();
      }
      return false;
    default:
      return true;
  }
}


// Runs after all basic initialization is done
void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  lighting_set_for_layer(NEO1);
}

// Runs every time the layer is changed.
uint32_t layer_state_set_user(uint32_t state) {
  // Handle Neo5 and Neo6 tri-state correctly.
  // We can't use `update_tri_layer_state` for Neo5, because either of
  // LSFT and RSFT can be used to enable Neo5 together with Mod-Neo3.
  uint32_t mask_neo_2_1 = 1 << NEO2_1;
  uint32_t mask_neo_2_2 = 1 << NEO2_2;
  uint32_t mask_neo_3 = 1 << NEO3;
  uint32_t mask_neo_4 = 1 << NEO4;
  uint32_t mask_neo_5 = 1 << NEO5;
  uint32_t mask_neo_6 = 1 << NEO6;
  bool is_neo2_on = (state & mask_neo_2_1) == mask_neo_2_1 || (state & mask_neo_2_2) == mask_neo_2_2;
  bool is_neo3_on = (state & mask_neo_3) == mask_neo_3;
  bool is_neo4_on = (state & mask_neo_4) == mask_neo_4;
  if (is_neo2_on && is_neo3_on) {
    state |= mask_neo_5;
  } else {
    state &= ~mask_neo_5;
  }
  if (is_neo3_on && is_neo4_on) {
    state |= mask_neo_6;
  } else {
    state &= ~mask_neo_6;
  }

  uint8_t layer = biton32(state);
  lighting_set_for_layer(layer);
  leds_set_for_layer(layer);
  return state;
};

