#define HSV_BROWN 15, 255, 150
#define HSV_BLACK 0, 0, 0

static bool lighting_disabled = false;

static void set_hsv_layer_color(uint8_t hue, uint8_t sat, uint8_t val) {
  rgblight_mode(1);
  rgblight_sethsv(hue, sat, val);
}

void lighting_set_for_layer(uint8_t layer) {
  if (lighting_disabled) {
    set_hsv_layer_color(HSV_BLACK);
    return;
  }
  switch (layer) {
    case NEO1_DE:
    case NEO1_US:
    case NEO2_1:
    case NEO2_2:
    case NEO2_US:
      set_hsv_layer_color(HSV_BLUE);
      break;
    case NEO3_DE:
    case NEO3_US:
      set_hsv_layer_color(HSV_BROWN);
      break;
    case NEO4_DE:
    case NEO4_US:
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

void toggle_lighting(void) {
  lighting_disabled = !lighting_disabled;
  lighting_set_for_layer(NEO1_DE);
}

void lighting_rgb_matrix_indicators(void) {
  if (lighting_disabled) {
    return;
  }
  const uint8_t F_MEDIA_GREEN_KEYS[] = {0, 1, 2, 3, 4, 24, 25, 26, 27, 28};
  const uint8_t F_MEDIA_SPRINGGREEN_KEYS[] = {11, 12, 13, 14, 30, 31, 32, 35, 36, 37, 40};
  const uint8_t STENO_COLORED_KEYS[] = {
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    34, 35, 36, 37, 38, 39, 40, 41, 42, 43
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

void leds_set_for_host_indicators(led_t led_state) {
  if (led_state.caps_lock) {
    ergodox_right_led_3_on();
  } else {
    ergodox_right_led_3_off();
  }
}

void leds_set_for_userland_language(enum userland_language lang) {
  if (lang == DE) {
    ergodox_right_led_2_off();
  } else {
    ergodox_right_led_2_on();
  }
}

