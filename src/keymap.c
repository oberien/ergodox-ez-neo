#include <pointing_device.h>
#include "my_keymap.h"
#include "helper.c"
#include "trackball.c"
#include "lighting.c"
#include "neo4lthack.c"
#include "custom_keys.c"
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

// Runs every matrix scan
void matrix_scan_user(void) {
  neo4lthack_matrix_scan_user();
  //leader_matrix_scan_user();
}

// Runs every keyboard-loop, similar to matrix_scan_user but is used for pointing stuff
void pointing_device_task(void) {
  trackball_pointing_device_task();
  pointing_device_send();
}

// Runs when a key is pressed before it is forwarded to qmk.
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!neo4lthack_process_record_user(keycode, record)) { return false; }
  if (!custom_keys_process_record_user(keycode, record)) { return false; }
  return true;
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

