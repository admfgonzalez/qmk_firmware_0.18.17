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

#include QMK_KEYBOARD_H

typedef enum layers {
    MACRO_LAYER,
    NAVIGATION_LAYER,
    WEB_NAVIGATION_LAYER,
    ADJUST_LAYER,
    MUSIC_LAYER,
    NUMBERS_LAYER,
} LayersEnum;

enum custom_keycodes {
    KC_MACRO1 = SAFE_RANGE,
    KC_MACRO2,
    KC_MACRO3,
    KC_MACRO_LAYER,
    WEB_BACK,
    WEB_FORW,
} ;

enum {
  TD_2 = 0,
  TD_3,
  TD_4,
  TD_5,
  TD_7,
  TD_8,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_DOT),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_PAST),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PSLS),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_PPLS),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_PMNS),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap MACRO_LAYER:
 * ,----------------------.    ENCODER 1
 * |CtlA |CtlS |CtlD |    |    + LAY U
 * |-----|-----|-----|    |    - LAY D
 * |RCtlA|RCtlS|RCtlD|----|    ENCODER 2
 * |-----|-----|-----|    |
 * | M1  | M2  | M3  |    |
 * `----------------------'
 */
  [MACRO_LAYER] = LAYOUT(
    LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),      XXXXXXX,
    RCTL_T(KC_A),   RCTL_T(KC_S),   RCTL_T(KC_D),    XXXXXXX,
    KC_MACRO1,      KC_MACRO2,      KC_MACRO3
  ),

/* Keymap NUMBERS_LAYER:
 * ,-------------------.    ENCODER 1
 * | 7 +| 8 -| 9  |Back|    + LAY U
 * |----|----|----| SP |    - LAY D
 * | 4 *| 5 /| 6  |----|    ENCODER 2
 * |----|----|----|=   |    + ENTER
 * | 1  | 2 0| 3 .|    |    - BACKSPACE
 * `-------------------'
 */
  [NUMBERS_LAYER] = LAYOUT(
    TD(TD_7),  TD(TD_8),    KC_P9, KC_BSPC,
    TD(TD_4),  TD(TD_5),    KC_P6, KC_PEQL,
    KC_P1,     TD(TD_2),    TD(TD_3)
  ),

/* Keymap NAVIGATION_LAYER:
 * ,-------------------.    ENCODER 1
 * |INS |    |HOME|MCRL|    + LAY U
 * |----|----|----|    |    - LAY D
 * |DEL | UP |END |----|    ENCODER 2
 * |----|----|----|ENT |    + PGUP
 * |LEFT|DOWN|RIGH|    |    - PGDN
 * `-------------------'
 */

  [NAVIGATION_LAYER] = LAYOUT(
    KC_INS,   XXXXXXX,  KC_HOME, KC_MACRO_LAYER,
    KC_DEL,   KC_UP,    KC_END,  KC_PENT,
    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /* Keymap WEB_NAVIGATION_LAYER:
 * ,-------------------.    ENCODER 1
 * |REFR|ROPE|HOME|MCRL|    + LAY U
 * |----|----|----|    |    - LAY D
 * |FAV |BOOK|HIST|----|    ENCODER 2
 * |----|----|----|ZDef|    + ZOOM
 * |BACK|SRCH|FWD |    |    - ZOOM
 * `-------------------'
 */

  [WEB_NAVIGATION_LAYER] = LAYOUT(
    LSFT(LGUI(KC_R)),   LSFT(LGUI(KC_T)),   LSFT(LGUI(KC_H)),   KC_MACRO_LAYER,
    LGUI(KC_D),         LALT(LGUI(KC_B)),   LGUI(KC_Y),         LGUI(KC_0),
    WEB_BACK,           LGUI(KC_F),         WEB_FORW
  ),

/* Keymap MUSIC_LAYER:
 * ,-------------------.    ENCODER 1
 * |    |STOP|    |MCRL|    + LAY U
 * |----|----|----|    |    - LAY D
 * |MRWD|PLAY|MFFD|----|    ENCODER 2
 * |----|----|----|MUTE|    + VOL U
 * |    |MUSI|    |    |    - VOL D
 * `-------------------'
 */
  [MUSIC_LAYER] = LAYOUT(
    XXXXXXX,  KC_MSTP,  XXXXXXX,   KC_MACRO_LAYER,
    KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_KB_MUTE,
    XXXXXXX,  KC_MSEL,  XXXXXXX
  ),

/* Keymap ADJUST_LAYER:
 * ,-------------------.    ENCODER 1
 * |HUI |SAI |VAI |MCRL|    + LAY U
 * |----|----|----|    |    - LAY D
 * |HUD |SAD |VAI |----|    ENCODER 2
 * |----|----|----|TOG |    + MOD U
 * |BRID|BRIU|    |    |    - MOD D
 * `-------------------'
 */
  [ADJUST_LAYER] = LAYOUT(
    RGB_HUI,  RGB_SAI,  RGB_VAI,   KC_MACRO_LAYER,
    RGB_HUD,  RGB_SAD,  RGB_VAD,   RGB_TOG,
    KC_BRID,  KC_BRIU,  XXXXXXX
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MACRO1:
            if (record->event.pressed) {
                SEND_STRING("MACRO 01");
            } else {
                // key released
            }
            break;
        case KC_MACRO2:
            if (record->event.pressed) {
                SEND_STRING("MACRO 02");
            } else {
                // key released
            }
            break;
        case KC_MACRO3:
            if (record->event.pressed) {
                SEND_STRING("MACRO 03");
            } else {
                // key released
            }
            break;
        case KC_MACRO_LAYER:
            if (record->event.pressed) {
                layer_move(0);
            }
            break;
        case WEB_BACK:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_LEFT_BRACKET));
            }
            break;
        case WEB_FORW:
            if (record->event.pressed) {
                tap_code16(LGUI(KC_RIGHT_BRACKET));
            }
            break;
    }
    return true;
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

// LOGO
void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
        0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
        0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0};
    oled_write_P(logo, false);
}

// MUSIC ICO
void render_music(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(logo, false);
}

// MACRO ICO
void render_macro(void) {
    static const char PROGMEM logo[] = {
        0x94, 0x95, 0x96, 0x97, 0x98,
        0xb4, 0xb5, 0xb6, 0xb7, 0xb8,
        0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0};
    oled_write_P(logo, false);
}

// NAVIGATION ICO
void render_navi(void) {
    static const char PROGMEM logo[] = {
        0x8f, 0x90, 0x91, 0x92, 0x93,
        0xaf, 0xb0, 0xb1, 0xb2, 0xb3,
        0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0};
    oled_write_P(logo, false);
}

// NUMBERS ICO
void render_numbers(void) {
    static const char PROGMEM logo[] = {
        0x8a, 0x8b, 0x8c, 0x8d, 0x8e,
        0xaa, 0xab, 0xac, 0xad, 0xae,
        0xca, 0xcb, 0xcc, 0xcd, 0xce, 0};
    oled_write_P(logo, false);
}

// WEB ICO
void render_web(void) {
    static const char PROGMEM logo[] = {
        0x85, 0x86, 0x87, 0x88, 0x89,
        0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
        0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0};
    oled_write_P(logo, false);
}

bool oled_task_user(void) {
    // ZK LOGO
    render_logo();
    oled_write_P(PSTR("ZKPAD"), false);
    oled_write_P(PSTR("-----"), false);

    // LAYER DISPLAY
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case MACRO_LAYER:
            oled_write_ln_P(PSTR(" MCR"), false);
            break;
        case NAVIGATION_LAYER:
            oled_write_ln_P(PSTR(" NAV"), false);
            break;
        case ADJUST_LAYER:
            oled_write_ln_P(PSTR(" RGB"), false);
            break;
        case MUSIC_LAYER:
            oled_write_ln_P(PSTR(" MUS"), false);
            break;
        case NUMBERS_LAYER:
            oled_write_ln_P(PSTR(" NUM"), false);
            break;
        case WEB_NAVIGATION_LAYER:
            oled_write_ln_P(PSTR(" WEB"), false);
            break;
    }

    // RGB STATUS
    oled_write_P(PSTR("-----"), false);

    // FUNCTION ON SCREEN
    if (IS_LAYER_ON(MACRO_LAYER)) {
        oled_write_P(PSTR("          "), false);
        render_macro();
        oled_write_P(PSTR("          "), false);
    } else if (IS_LAYER_ON(NAVIGATION_LAYER)) {
        oled_write_P(PSTR("          "), false);
        render_navi();
        oled_write_P(PSTR("          "), false);
    } else if (IS_LAYER_ON(ADJUST_LAYER)) {
        oled_write_P(PSTR("Light"), false);
        static char led_buf[30];
        snprintf(led_buf, sizeof(led_buf) - 1,
        "RGB:%cM: %2d\nh: %2ds: %2dv: %2d\n",
        rgblight_is_enabled() ? '*' : '.',
        (uint8_t)rgblight_get_mode(),
        (uint8_t)(rgblight_get_hue() / RGBLIGHT_HUE_STEP),
        (uint8_t)(rgblight_get_sat() / RGBLIGHT_SAT_STEP),
        (uint8_t)(rgblight_get_val() / RGBLIGHT_VAL_STEP));
        oled_write(led_buf, false);

    } else if (IS_LAYER_ON(MUSIC_LAYER)) {
        oled_write_P(PSTR("          "), false);
        render_music();
        oled_write_P(PSTR("          "), false);
    } else if (IS_LAYER_ON(NUMBERS_LAYER)) {
        oled_write_P(PSTR("          "), false);
        render_numbers();
        oled_write_P(PSTR("          "), false);
    }else if (IS_LAYER_ON(WEB_NAVIGATION_LAYER)) {
        oled_write_P(PSTR("          "), false);
        render_web();
        oled_write_P(PSTR("          "), false);
    }

    return false;
}
#endif

#ifdef ENCODER_ENABLE
int        layerIndex    = 0;
LayersEnum layersArray[] = {MACRO_LAYER, NAVIGATION_LAYER, WEB_NAVIGATION_LAYER, NUMBERS_LAYER, MUSIC_LAYER, ADJUST_LAYER};
int        arrayLenght   = (sizeof(layersArray) / sizeof(*layersArray));
bool       encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            layerIndex++;
            if (layerIndex >= arrayLenght) {
                layerIndex = 0;
            }
        } else {
            layerIndex--;
            if (layerIndex < 0) {
                layerIndex = arrayLenght - 1;
            }
        }
        layer_move(layersArray[layerIndex]);
    } else {
        if (IS_LAYER_ON(MACRO_LAYER)) {
            if (clockwise) {
                tap_code(KC_PGDOWN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (IS_LAYER_ON(NAVIGATION_LAYER)) {
            if (clockwise) {
                tap_code(KC_PGDOWN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (IS_LAYER_ON(ADJUST_LAYER)) {
            if (clockwise) {
                rgblight_step_reverse();
            } else {
                rgblight_step();
            }
        } else if (IS_LAYER_ON(MUSIC_LAYER)) {
            if (clockwise) {
                tap_code(KC_AUDIO_VOL_UP);
            } else {
                tap_code(KC_AUDIO_VOL_DOWN);
            }
        } else if (IS_LAYER_ON(NUMBERS_LAYER)) {
            if (clockwise) {
                tap_code(KC_BSPC);
            } else {
                tap_code(KC_ENT);
            }
        } else if (IS_LAYER_ON(WEB_NAVIGATION_LAYER)) {
            if (clockwise) {
                tap_code16(LGUI(KC_PMNS));
            } else {
                tap_code16(LGUI(KC_PPLS));
            }
        }
    }
    return false;
}
#endif
