/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
//#include <stdio.h>

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    LT(3,KC_TAB), KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y,                         KC_F,     KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,   KC_S,   KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LCTL_T(KC_AT),    KC_QUOT,    KC_Q,    KC_J,    KC_K,    KC_X,                    KC_B,  KC_M,    KC_W,    KC_V,   KC_Z, RSFT_T(KC_SLSH),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_SPC,   LT(2,KC_ENT), RALT_T(KC_CAPS)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_PEQL, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,                        KC_BTN1, KC_HOME,   KC_UP,  KC_END, KC_BTN2, KC_VOLU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRMU, XXXXXXX, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX,                      KC_PGUP,KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BRMD, XXXXXXX, KC_CUT, KC_COPY, KC_PSTE, XXXXXXX,                      XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, KC_VOLD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(4), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_LPRN,  KC_RPRN, KC_PERC,                     KC_EQL,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                     KC_EXLM, KC_HASH, KC_SLSH, KC_BSLS, KC_PIPE,  KC_DLR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX,                      XXXXXXX, KC_GRV, KC_CIRC,  KC_AT,  KC_AMPR, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(4),  KC_SPC,     KC_SPC, KC_TRNS, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_PPLS, KC_7,     KC_8,    KC_9,  KC_PMNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_PAST, KC_4,    KC_5,    KC_6,    KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_RALT,                      XXXXXXX, KC_1,     KC_2,    KC_3,   KC_0,   KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_SPC, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;   // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_DVORAK 0
#define L_NAVIGATE 2
#define L_SYMBOLS 4
#define L_NUMPAD 8
#define L_ADJUST 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_DVORAK:
            oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case L_NAVIGATE:
            oled_write_ln_P(PSTR("Navigate"), false);
            break;
        case L_SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_NUMPAD:
            oled_write_ln_P(PSTR("Numpad"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_NAVIGATE:
        case L_ADJUST|L_SYMBOLS:
        case L_ADJUST|L_NAVIGATE|L_SYMBOLS:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

#endif
