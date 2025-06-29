#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _LOWER_MAC,
  _LOWER_WIN,
  _RAISE_MAC,
  _RAISE_WIN,
  _ADJUST
};

// Custom keycodes for layer keys
// Dual function escape with left command
#define KC_LGESC LGUI_T(KC_ESC)
#define VSCIMPMAC LGUI(LSFT(KC_1))
#define VSCFRTMAC LGUI(LSFT(KC_F))

bool mac_active = true;

enum custom_keycodes {
  MAC = SAFE_RANGE,
  WINDOWS,
  LOWER,
  RAISE,
  ADJUST,
  PLOCMAC,
  NLOCMAC,
  PLOCWIN,
  NLOCWIN,
  VSCFRTWIN,
  DATATRANS,
  RAZONSOCIAL,
  LEFT_IN,
  RIGHT_END
};


// Tap Dance definitions
enum {
    TD_CAPLOCK,
    TD_SLASH_MAC,
    TD_LEFT_PAR_BRA_MAC,
    TD_RIGHT_PAR_BRA_MAC,
    TD_SLASH_WIN,
    TD_LEFT_PAR_BRA_WIN,
    TD_RIGHT_PAR_BRA_WIN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_SLASH_MAC] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, A(KC_NUBS)),
    [TD_LEFT_PAR_BRA_MAC] = ACTION_TAP_DANCE_DOUBLE(A(KC_QUOT), A(KC_LBRC)),
    [TD_RIGHT_PAR_BRA_MAC] = ACTION_TAP_DANCE_DOUBLE(A(KC_BSLS), A(KC_RBRC)),
    [TD_SLASH_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, RALT(KC_MINS)),
    [TD_LEFT_PAR_BRA_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, S(KC_QUOT)),
    [TD_RIGHT_PAR_BRA_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_NUHS, S(KC_NUHS))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |--------.   .-------|   N  |   M  |  ,;  |  .:  |  -_  |AltGr |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[_QWERTY] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_CAPLOCK),KC_A,KC_S,  KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RALT,
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, LOWER, KC_SPC,       KC_ENT,  RAISE,  KC_LALT
                                      //|--------------------------|  |--------------------------|
  ),

/* LOWER_MAC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  ºª\ |  ¿   |   ?  |   ^  |  *   |                    |  7/÷ |  8(“ |  9)” |   *  |  /   |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  <>  |  [{  |  ]}  |   '  |  "   |                    |  4$¢ |  5%∞ |  6&¬ |   +  |  -   |  C   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  (   |  )   |  /\  | `^[  | +*]  |--------.    .------|  1!| |  2"@ | 3·#  |  0=≠ |  .   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
  [_LOWER_MAC] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
    KC_ESC, KC_NUBS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,                      KC_7,    KC_8,    KC_9,    KC_PAST, KC_PSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_GRV,TD(TD_LEFT_PAR_BRA_MAC),TD(TD_RIGHT_PAR_BRA_MAC),KC_MINS,S(KC_2), KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS, S(KC_C),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, S(KC_8), S(KC_9), TD(TD_SLASH_MAC), KC_LBRC, KC_RBRC,                 KC_1,    KC_2,    KC_3,    KC_0,    KC_DOT,  KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,   _______,  _______,  _______,  _______
                                      //|--------------------------|  |--------------------------|
  ),

/* LOWER_WIN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  ºª\ |  ¿   |   ?  |   ^  |  *   |                    |  7/÷ |  8(“ |  9)” |   *  |  /   |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  <>  |  [{  |  ]}  |   '  |  "   |                    |  4$¢ |  5%∞ |  6&¬ |   +  |  -   |  C   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  (   |  )   |  /\  | `^[  | +*]  |--------.    .------|  1!| |  2"@ | 3·#  |  0=≠ |  .   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
  [_LOWER_WIN] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
    KC_ESC,   KC_GRV, KC_EQL, KC_UNDS, ALGR(KC_QUOT), KC_RCBR,                      KC_7,    KC_8,    KC_9,    KC_PAST, KC_PSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_NUBS,TD(TD_LEFT_PAR_BRA_WIN),TD(TD_RIGHT_PAR_BRA_WIN),KC_MINS,S(KC_2), KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS, S(KC_C),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, S(KC_8), S(KC_9), TD(TD_SLASH_WIN), KC_LBRC, KC_RBRC,              KC_1,    KC_2,    KC_3,    KC_0,    KC_DOT,  S(KC_0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,   _______,  _______,  _______,  _______
                                      //|--------------------------|  |--------------------------|
  ),

/* RAISE_MAC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  |   |  ^   |   ̈   |  ~   |  a   |                    |MRClic|MLClic|  Up  |      |Pag UP|BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |VSCFRT|VSCIMP|      |DATRAN|RASOCI|      |                    | Home | Left | Down |Right | END  |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  | F4   | F5   | F6   |--------.   .-------|      |PLocat|      |NLocat|Pag Do|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
  [_RAISE_MAC] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  A(KC_1), KC_LCBR, S(KC_QUOT), A(KC_SCLN), S(KC_NUBS),             KC_BTN1, KC_BTN2, KC_UP,   XXXXXXX, KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     VSCFRTMAC,VSCIMPMAC,XXXXXXX,DATATRANS,RAZONSOCIAL,XXXXXXX,                LEFT_IN, KC_LEFT, KC_DOWN, KC_RIGHT, RIGHT_END,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        XXXXXXX, PLOCMAC, XXXXXXX, NLOCMAC, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,   _______,  _______,  _______,  _______
                                      //|--------------------------|  |--------------------------|
  ),

/* RAISE_WIN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |  |   |  ^   |   ̈   |  ~   |  a   |                    |MRClic|MLClic|  Up  |      |Pag UP|BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |VSCFRT|VSCIMP|      |      |      |      |                    | Home | Left | Down |Right | END  |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  | F4   | F5   | F6   |--------.   .-------|      |      |      |      |Pag Do|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
  [_RAISE_WIN] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_GRV, ALGR(KC_QUOT), S(KC_LBRC), ALGR(KC_RBRC), S(KC_GRV),      KC_BTN1, KC_BTN2, KC_UP,   XXXXXXX, KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX,KC_PSCR,VSCFRTWIN,XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        XXXXXXX, PLOCWIN, XXXXXXX, NLOCWIN, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,   _______,  _______,  _______,  _______
                                      //|--------------------------|  |--------------------------|
  ),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |Toggle|                    | MAC  | WIN  |      | Mute | VOL- | VOL+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  HUI |  SAI |  VAI |  SPI |  MOD |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  HUD |  SAD |  VAD |  SPD |      |-------.    .-------|RESET |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| LAlt |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
  [_ADJUST] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  RGB_TOG,                      MAC,    WINDOWS,  XXXXXXX,KC_MUTE, KC_VOLD, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                      XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,   _______,  _______,  _______,  _______
                                      //|--------------------------|  |--------------------------|
  )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        // return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
        // return OLED_ROTATION_270;
    }
    return rotation;
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_status_secondary(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x33, 0x0b, 0x0c, 0x34, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x01, 0x01,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x01, 0x01,
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x01, 0x01,
        0};
    oled_write_P(crkbd_logo, false);
}

// void suspend_power_down_user() {
//     oled_off();
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        //render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
        // render_status_main();
    }
    return false;
}

// bool rgb_matrix_indicators_user(void) {
void rgb_matrix_indicators_user(void) {
     switch (biton32(layer_state)) {
        // case _RAISE:
        //     for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        //         rgb_matrix_set_color(i, 255, 0, 0);
        //     }
        //     break;

        // case _LOWER:
        //     for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        //         rgb_matrix_set_color(i, 0, 0, 255);
        //     }
        //     break;

        default:
            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                // for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
                for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
                    rgb_matrix_set_color(i, 0, 255, 0);
                }
            }
            break;
    }
    // return true;
}

#endif
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        if (mac_active) {
            layer_on(_LOWER_MAC);
            update_tri_layer_RGB(_LOWER_MAC, _RAISE_MAC, _ADJUST);
        } else {
            layer_on(_LOWER_WIN);
            update_tri_layer_RGB(_LOWER_WIN, _RAISE_WIN, _ADJUST);
        }
      } else {
        if (mac_active) {
            layer_off(_LOWER_MAC);
            update_tri_layer_RGB(_LOWER_MAC, _RAISE_MAC, _ADJUST);
        } else {
            layer_off(_LOWER_WIN);
            update_tri_layer_RGB(_LOWER_WIN, _RAISE_WIN, _ADJUST);
        }
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        if (mac_active) {
            layer_on(_RAISE_MAC);
            update_tri_layer_RGB(_LOWER_MAC, _RAISE_MAC, _ADJUST);
        } else {
            layer_on(_RAISE_WIN);
            update_tri_layer_RGB(_LOWER_WIN, _RAISE_WIN, _ADJUST);
        }
      } else {
        if (mac_active) {
            layer_off(_RAISE_MAC);
            update_tri_layer_RGB(_LOWER_MAC, _RAISE_MAC, _ADJUST);
        } else {
            layer_off(_RAISE_WIN);
            update_tri_layer_RGB(_LOWER_WIN, _RAISE_WIN, _ADJUST);
        }
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
      break;
    case MAC:
        if (record->event.pressed) {
            mac_active = true;
            layer_off(_RAISE_WIN);
            layer_off(_LOWER_WIN);
            layer_on(_RAISE_MAC);
            layer_on(_LOWER_MAC);
            update_tri_layer_RGB(_LOWER_MAC, _RAISE_MAC, _ADJUST);
        }
        return false;
    case WINDOWS:
        if (record->event.pressed) {
            mac_active = false;
            layer_off(_RAISE_MAC);
            layer_off(_LOWER_MAC);
            layer_on(_RAISE_WIN);
            layer_on(_LOWER_WIN);
            update_tri_layer_RGB(_LOWER_WIN, _RAISE_WIN, _ADJUST);
        }
        return false;
    case PLOCMAC:
        tap_code16(RCTL(KC_SLSH));
        return true;
    case NLOCMAC:
        tap_code16(RCTL(LSFT(KC_SLSH)));
        return true;
    case PLOCWIN:
        tap_code16(LALT(KC_LEFT));
        return true;
    case NLOCWIN:
        tap_code16(LALT(KC_RIGHT));
        return true;
    case VSCFRTWIN:
        tap_code16(LSFT(LALT(KC_F)));
        return true;
    case DATATRANS:
        if (record->event.pressed) {
            SEND_STRING("ELECTRONICA ZK SPA\n77323649/6\nBanco Santander\nCC 88440676\nventas" SS_LALT("2") "zonekeyboards.cl\n] 56 937505920");
        }
        return false;
    case RAZONSOCIAL:
        if (record->event.pressed) {
            SEND_STRING("MANUFACTURA,VENTA DE PERIFERICOS,ELECTRO,PROGR INFORMATICOS Y EXPORT");
        }
        return false;
    case LEFT_IN:
        tap_code16(KC_HOME);
        return true;
    case RIGHT_END:
        tap_code16(KC_END);
        return true;
  }
  return true;
}

#ifdef RGB_MATRIX_ENABLE

// void suspend_power_down_keymap(void) {
//     rgb_matrix_set_suspend_state(true);
// }

// void suspend_wakeup_init_keymap(void) {
//     rgb_matrix_set_suspend_state(false);
// }

#endif
