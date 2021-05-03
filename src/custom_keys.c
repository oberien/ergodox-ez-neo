/// Return false if the key press was handled and the key shouldn't be handled further
bool custom_keys_process_record_user(uint16_t keycode, keyrecord_t* record) {
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
