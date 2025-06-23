/*
MIT License

Copyright (c) 2022 Fgonzalez <administrator@fgonzalez.me>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "zkpad.h"

#if defined(OLED_ENABLE)
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
  // Layer Status
  oled_write_P(PSTR("Layer"), false);
  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_ln_P(PSTR(" BAS"), false);
      break;
    case 1:
      oled_write_ln_P(PSTR(" NAV"), false);
      break;
    case 2:
      oled_write_ln_P(PSTR(" RGB"), false);
      break;
  }

  // LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Stats"), false);
  oled_write_P(led_state.num_lock ? PSTR("num:*") : PSTR("num:."), false);
  oled_write_P(led_state.caps_lock ? PSTR("cap:*") : PSTR("cap:."), false);
  oled_write_P(led_state.scroll_lock ? PSTR("scr:*") : PSTR("scr:."), false);

  // Host Keyboard RGB backlight status
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Light"), false);

  static char led_buf[30];
  snprintf(led_buf, sizeof(led_buf) - 1, "RGB:%cM: %2d\nh: %2ds: %2dv: %2d\n",
      rgblight_is_enabled() ? '*' : '.', (uint8_t)rgblight_get_mode(),
      (uint8_t)(rgblight_get_hue() / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_get_sat() / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_get_val() / RGBLIGHT_VAL_STEP));
  oled_write(led_buf, false);

  return false;
}
#endif
