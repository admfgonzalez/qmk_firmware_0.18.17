#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _HIGHER,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   `  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |   ´  |
 * |------+------+------+------+------+------|   {   |    |  }    |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |AltGr |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |HIGHER|Space |ADJUST|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC, \
  KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, \
  KC_LSHIFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, \
  KC_LCTRL,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, A(KC_QUOT),  A(KC_BSLS), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ALGR, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,            KC_ENT, MO(_HIGHER), KC_SPC, MO(_ADJUST) \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   C  |      |   %  |   /  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  ºª\ |   ¿  |   ?  |   ^  |  *   |                    |   7  |   8  |   9  |   *  |  <<  | Vol+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  <>  |   [  |   ]  |   '  |  "   |-------.    ,-------|   4  |   5  |   6  |   -  | PLAY | Mute |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |LCTRL |      |  (   |   )  |  /   |   \  |-------|    |-------|   1  |   2  |   3  |   +  |  >>  | Vol- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |  0   | .    |  =   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT( \
  _______, KC_F1,    KC_F2,     KC_F3,     KC_F4,     KC_F5,                             S(KC_C), XXXXXXX, KC_PERC, KC_PSLS, XXXXXXX, _______,\
  _______, KC_GRV,   KC_PLUS,   KC_UNDS,   KC_LCBR,   KC_RCBR,                           KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_MRWD, KC__VOLUP, \
  _______, KC_NUBS,  A(KC_LBRC),A(KC_RBRC),KC_MINS,   S(KC_2),                           KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_MPLY, KC__MUTE, \
  _______, XXXXXXX,  S(KC_8),   S(KC_9),   KC_PSLS,   A(KC_GRV),   _______,         _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, KC_MFFD, KC__VOLDOWN, \
                             _______, _______, _______, _______,                          _______, KC_KP_0, KC_DOT, KC_PEQL\
),

/* HIGHER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |  5   |                    |  6   |  7   |  8   |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |Mouse2|      |  Up  |      | Home |Pag UP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------|      | Left | Down |Right | END  |Pag Do|
 * |------+------+------+------+------+------|    {  |    |   }   |------+------+------+------+------+------|
 * |LCTRL |  F11 |  F12 | F13  | F14  | F15  |-------|    |-------|      |      |      |      | DEL  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |HIGHER|Space | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_HIGHER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,                     KC_BTN2, XXXXXXX,   KC_UP, XXXXXXX, KC_HOME , KC_PGUP, \
  _______, KC_F6,    KC_F7,    KC_F8,   KC_F9,  KC_F10,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PGDOWN, \
  _______, KC_F11,   KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,   XXXXXXX, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |  TOG |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|  HUI |  SAI |  VAI |  SPI |  MOD |-------.    ,-------|      |      |      |      |      |RESET |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * | LCTRL|  HUD |  SAD |  VAD |  SPD |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |HIGHER|Space | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, \
  _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;
  return rotation;
}

const char *read_logo(void);
bool oled_task_user(void) {
  if (!is_keyboard_master()) {
    oled_write(read_logo(), false);
    }
  return true;
}
#endif
