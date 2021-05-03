static uint16_t lt_neo4_timer;
static bool anything_pressed_during_neo4;
static bool is_neo4_pressed;

void neo4lthack_matrix_scan_user(void) {
  if (is_neo4_pressed && !IS_LAYER_ON(NEO4_DE) && timer_elapsed(lt_neo4_timer) >= TAPPING_TERM) {
    layer_on(NEO4_DE);
  }
}

/// Return false if the key press was handled and the key shouldn't be handled further
bool neo4lthack_process_record_user(uint16_t keycode, keyrecord_t* record) {
  // Change behavour of LT(NEO4, KC_ENTER) to make
  // Down(LT), Down(6), Up(LT), Up(6) register as 6.
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
  return true;
}
