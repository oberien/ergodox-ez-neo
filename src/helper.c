static bool is_unicode(uint16_t keycode) {
  return QK_UNICODE <= keycode && keycode <= QK_UNICODE_MAX;
}

void press_key(uint16_t keycode) {
  if (is_unicode(keycode)) {
    unicode_input_start();
    register_hex(keycode & 0x7fff);
    unicode_input_finish();
  } else if ((keycode & 0xff) == keycode) {
    register_code(keycode);
  } else {
    register_code16(keycode);
  }
}

void release_key(uint16_t keycode) {
  if (is_unicode(keycode)) {
    // do nothing, we already released during press
  } else if ((keycode & 0xff) == keycode) {
    unregister_code(keycode);
  } else {
    unregister_code16(keycode);
  }
}

void press_or_release_key(uint16_t keycode, bool press) {
  if (press) {
    press_key(keycode);
  } else {
    release_key(keycode);
  }
}

void tap_key(uint16_t keycode) {
  press_key(keycode);
  release_key(keycode);
}
