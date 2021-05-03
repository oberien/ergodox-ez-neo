#include "my_keymap.h"
#include "lighting.c"
#include "helper.c"
//#include "leader.c"

// Run only after EEPROM is reset to initialize it with default values.
void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

// Run during firmware startup
void matrix_init_user(void) {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      tap_key(KC_NUMLOCK);
  }
}

// Runs after all basic initialization is done
void keyboard_post_init_user(void) {
  led_t led_state = host_keyboard_led_state();
  /*if (!led_state.num_lock) {*/
    /*tap_key(KC_NUMLOCK);*/
  /*}*/
  rgb_matrix_enable();
  leds_set_for_host_indicators(led_state);
  lighting_set_for_layer(NEO1_DE);
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
  if (is_neo4_pressed && !IS_LAYER_ON(NEO4_DE) && timer_elapsed(lt_neo4_timer) >= TAPPING_TERM) {
    layer_on(NEO4_DE);
  }
  //leader_matrix_scan_user();
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
      layer_off(NEO4_DE);
      is_neo4_pressed = false;
      if (!anything_pressed_during_neo4 && timer_elapsed(lt_neo4_timer) < TAPPING_TERM) {
        tap_key(KC_ENTER);
      }
    }
    return false;
  } else {
    if (is_neo4_pressed && !anything_pressed_during_neo4 && record->event.pressed) {
      layer_on(NEO4_DE);
      anything_pressed_during_neo4 = true;
      // The keycode already got translated with the wrong layer.
      // Generate the new one and discard the old one.
      process_record(record);
      return false;
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
      const uint16_t* neo_sft_keys;
      if (userland_language == DE) {
        neo_sft_keys = NEO_SFT_KEYS_DE;
      } else {
        neo_sft_keys = NEO_SFT_KEYS_US;
      }
      uint16_t keycode = pgm_read_word(&neo_sft_keys[num_index]);
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
    case TGL_DE_US:
      if (record->event.pressed) {
        toggle_userland_language();
        leds_set_for_userland_language(userland_language);
      }
      return false;
    case TGL_UC_MODE:
      if (record->event.pressed) {
        toggle_unicode_input_mode();
        leds_set_for_unicode_input_mode(get_unicode_input_mode());
      }
      return false;
    case ND_CIRC:
      if (record->event.pressed) {
        tap_key(DE_CIRC);
        tap_key(KC_SPACE);
      }
      return false;
    case ND_GRAVE:
      if (record->event.pressed) {
        tap_key(DE_GRV);
        tap_key(KC_SPACE);
      }
      return false;
    default:
      return true;
  }
}


// Runs every time the layer is changed.
uint32_t layer_state_set_user(uint32_t state) {
  // Handle Neo5 and Neo6 tri-state correctly.
  // LSFT and RSFT can both be used to enable Neo5 together with Mod-Neo3.
  state = update_tri_layer_mask_state(state, mask(NEO2_1) | mask(NEO2_2), mask(NEO3_DE), mask(NEO5));
  state = update_tri_layer_state(state, NEO3_DE, NEO4_DE, NEO6);

  // DE vs US
  state = update_tri_layer_bool_state(state, QWERTZ, userland_language == US, QWERTY);
  state = update_tri_bool_state(state, userland_language == US, NEO1_US);
  state = update_tri_layer_mask_bool_state(state, mask(NEO2_1) | mask(NEO2_2), userland_language == US, mask(NEO2_US));
  state = update_tri_layer_bool_state(state, NEO3_DE, userland_language == US, NEO3_US);
  state = update_tri_layer_bool_state(state, NEO4_DE, userland_language == US, NEO4_US);

  uint8_t layer = biton32(state);
  lighting_set_for_layer(layer);
  return state;
};

