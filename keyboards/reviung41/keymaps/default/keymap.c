/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |BackSp|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   Ñ  | ´¨{  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |  ,;  |  .:  |  -_  |Enter |
 * `-----------------------------------------/     \-----------------------------------------'
 *                          | LAlt | LOWER| / Space \ |RAISE |Command|
 *                          |      |      |/         \|      |       |
 *                          `------------------------''--------------'
 */

  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LALT,   LOWER,    KC_SPC,   RAISE,    KC_RGUI
  ),
  
/* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Tab  |   !  |   "  |   ·  |   $  |   %  |     |   &  | Up   |   (  |   )  |   =  |Delete|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LCTRL |   ?  |   ¿  |   ^  |   *  |   Ç  |     | Left | Down |Right |   /  |  ºª  |  >   |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LShift| Esc  |Comand|   @  |CapsLk|   ¨  |     | Home | Fin  |Pag Up|Pag Dw|PrintS|Space |
 * `-----------------------------------------/     \-----------------------------------------'
 *                          | LAlt | LOWER| / Enter \ |RAISE |Command|
 *                          |      |      |/         \|      |       |
 *                          `------------------------''--------------'
 */
  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_UP,    KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_RGHT , KC_AMPR,  KC_GRV,   KC_TILD,
    _______,  KC_ESC,   KC_LGUI,  A(KC_2),  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
  
/* Raise
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |Delete|
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LCTRL |   '  |   ¡  |   `  |   +  |   ç  |     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |LShift| Esc  |Comand| RAlt |CapsLk| ´¨{  |     |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * `-----------------------------------------/     \-----------------------------------------'
 *                          | LAlt | LOWER| / BackS \ |RAISE |Command|
 *                          |      |      |/         \|      |       |
 *                          `------------------------''--------------'
 */
  [_RAISE] = LAYOUT_reviung41(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),


/* Adjust
 * ,-----------------------------------------.     ,-----------------------------------------.
 * | Luz+ | Sat+ | Mat+ | Mod+ |      |RGBTog|     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * | Luz- | Sat- | Mat- | Mod- |      |      |     |      |      |      |      |      |      |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     | Reset|      |      |      |      |      |
 * `-----------------------------------------/     \-----------------------------------------'
 *                          | LAlt | LOWER| /       \ |RAISE |Command|
 *                          |      |      |/         \|      |       |
 *                          `------------------------''--------------'
 */
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

