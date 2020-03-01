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

uint32_t mask(uint8_t layer) {
  return 1 << layer;
}

// Sets/unsets all layers in mask_layers3 in the state according to if one of
// the layers in mask_layers1 and one of the layers in mask_layers2 is active
uint32_t update_tri_layer_mask_state(
    uint32_t state, uint32_t mask_layers1, uint32_t mask_layers2, uint32_t mask_layers3
) {
  bool layers1_set = (state & mask_layers1) != 0;
  bool layers2_set = (state & mask_layers2) != 0;
  if (layers1_set && layers2_set) {
    state |= mask_layers3;
  } else {
    state &= ~mask_layers3;
  }
  return state;
}

// Sets/unsets the layer `layer2` depending on if the layer `layer` is on AND `condition` is true.
uint32_t update_tri_layer_bool_state(uint32_t state, uint8_t layer1, bool condition, uint8_t layer2) {
  uint32_t mask_layer1 = mask(layer1);
  uint32_t mask_layer2 = mask(layer2);
  bool layer1_set = (state & mask_layer1) != 0;
  if (layer1_set && condition) {
    state |= mask_layer2;
  } else {
    state &= ~mask_layer2;
  }
  return state;
}

// Sets/unsets the layer `layer` depending on whether `condition` is true or false.
uint32_t update_tri_bool_state(uint32_t state, bool condition, uint8_t layer) {
  uint32_t mask_layer = mask(layer);
  if (condition) {
    state |= mask_layer;
  } else {
    state &= ~mask_layer;
  }
  return state;
}

// Sets/unsets all layers in mask_layers2 in the state according to if one of
// the layers in mask_layers1 in on and `condition` is true or false.
uint32_t update_tri_layer_mask_bool_state(uint32_t state, uint32_t mask_layers1, bool condition, uint32_t mask_layers2) {
  bool layer1_set = (state & mask_layers1) != 0;
  if (layer1_set && condition) {
    state |= mask_layers2;
  } else {
    state &= ~mask_layers2;
  }
  return state;
}
