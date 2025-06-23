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
  VSCFRTMAC,
  VSCFRTWIN,
  VSCIMPMAC,
  VSCIMPWIN
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
 * |VSCFRT|VSCIMP|      |      |      |      |                    | Home | Left | Down |Right | END  |  DEL |
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
     XXXXXXX,VSCIMPMAC,VSCFRTMAC,XXXXXXX,XXXXXXX, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,
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
     XXXXXXX,VSCIMPWIN,VSCFRTWIN,XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DEL,
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
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

void render_space(void) {
    oled_write_P(PSTR("     "), false);
}

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
    static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
    static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
    static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

    static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
    static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
    static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
    static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if(modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
    static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
    static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

    static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
    static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
    static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
    static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc5, 0};
    static const char PROGMEM off_off_2[] = {0xc6, 0};
    static const char PROGMEM on_off_1[] = {0xc7, 0};
    static const char PROGMEM on_off_2[] = {0xc8, 0};
    static const char PROGMEM off_on_1[] = {0xc9, 0};
    static const char PROGMEM off_on_2[] = {0xca, 0};
    static const char PROGMEM on_on_1[] = {0xcb, 0};
    static const char PROGMEM on_on_2[] = {0xcc, 0};

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if(modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

// logo zk
void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
        0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
        0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
}
// Logo corne
// void render_logo(void) {
//     static const char PROGMEM corne_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84,
//         0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
//         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
//     oled_write_P(corne_logo, false);
//     oled_write_P(PSTR("corne"), false);
// }

void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM raise_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM lower_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM adjust_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(_ADJUST)) {
        oled_write_P(adjust_layer, false);
    } else if(layer_state_is(_LOWER_MAC) || layer_state_is(_LOWER_WIN)) {
        oled_write_P(lower_layer, false);
    } else if(layer_state_is(_RAISE_MAC) || layer_state_is(_RAISE_WIN)) {
        oled_write_P(raise_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}


void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
}

void render_status_secondary(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x01, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x33, 0x0b, 0x0c, 0x34, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x01, 0x01,
        0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x01, 0x01,
        0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x01, 0x01,
        0};
    oled_write_P(crkbd_logo, false);
}

void suspend_power_down_user() {
    oled_off();
}
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
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
    case VSCIMPMAC:
        tap_code16(LSFT(LGUI(KC_O)));
        return true;
    case VSCFRTMAC:
        tap_code16(LSFT(LGUI(KC_F)));
        return true;
    case PLOCWIN:
        tap_code16(LALT(KC_LEFT));
        return true;
    case NLOCWIN:
        tap_code16(LALT(KC_RIGHT));
        return true;
    case VSCIMPWIN:
        tap_code16(LSFT(LALT(KC_O)));
        return true;
    case VSCFRTWIN:
        tap_code16(LSFT(LALT(KC_F)));
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
//MANUFACTURA,VENTA DE PERIFÉRICOS,ELECTRÓ,PROGR INFORMATICOS Y EXPORT
