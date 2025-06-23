
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define ES_QUES S(KC_MINS)
#define ES_CIRC ALGR(KC_QUOT)  // ^ (dead)
#define ES_RSLSH ALGR(KC_MINS)
#define ES_OTRO ALGR(KC_NUHS)  // `
#define ES_PEPE ALGR(KC_RBRC)  // ~
#define ES_BQT   ALGR(KC_GRV)    // ¬
#define ES_PCOMA    S(KC_COMM)   // ;
#define ES_IGUAL   S(KC_0)   // =
#define ES_MAYOR   S(KC_NUBS)  // >
#define ES_AT   ALGR(KC_Q)    // @

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_CUSTOM
};

// Tap Dance definitions

enum td_keycodes {
    CAPLOCK,
    ALT,
    TILQUES
};

// definiendo el keycode TD_CAPLOCK
// un pulso: Left Shift
// dos pulsos: Caps Lock
qk_tap_dance_action_t tap_dance_actions[] = {
    [CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    [TILQUES] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, ES_QUES)
};

// las keycodes en cada capa
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
      KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, TD(CAPLOCK),
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_PSCREEN,      KC_MUTE,  KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, TD(TILQUES),
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                        KC_NUBS, KC_LCMD, KC_LALT, KC_LOWER,  KC_SPC,          KC_ENT,  KC_RAISE,   KC_MINS, KC_PGUP, KC_PGDN
//                    '--------'--------'--------'--------'--------'      '--------'--------'--------'--------'--------'
    ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
    [_LOWER] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
      KC_ESC,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_0,   KC_DEL,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_TAB,   KC_F12,  KC_LEFT, KC_RIGHT, KC_HOME,  KC_END,                         KC_SLSH, KC_7,    KC_8,    KC_9,   KC_RBRC, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_F11,  KC_PSLS,   ES_PCOMA, ES_IGUAL, KC_F4,                        KC_RBRC,  KC_4,    KC_5,    KC_6,   KC_NUBS, KC_RSFT,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LCTRL, KC_F10,  KC_COMM, KC_NUBS, ES_MAYOR,  KC_F2, KC_PSCREEN,       KC_MUTE,  KC_0,    KC_1,    KC_2,    KC_3,   KC_SLSH, TD(TILQUES),
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                        KC_NUBS, KC_LCMD, KC_LALT, XXXXXXX, KC_SPC,          KC_ENT,  KC_RAISE,   KC_0,    KC_COMM, KC_DOT
//                    '--------------------------------------------'      '--------------------------------------------'
    ),

    [_RAISE] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
      KC_ESC,   KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                            KC_6,   KC_7,    KC_8,    KC_9,   KC_0,   KC_DEL,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_TAB,  ES_AT,   KC_GRV, ES_RSLSH, ES_CIRC,  KC_VOLU,                         KC_F4, KC_PGUP, KC_UP,  KC_PGDN, XXXXXXX, KC_BSPC,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LSFT, ES_PEPE, ES_BQT,  ES_OTRO, KC_SLSH,  KC_VOLD,                         KC_F2, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_RSFT,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LCTRL, KC_F10,  KC_F11, KC_MPRV, KC_MPLY, KC_MNXT,  KC_PSCREEN,  KC_MUTE, KC_MINS, KC_EQL,  KC_QUOT, KC_NUHS,  KC_GRV, TD(TILQUES),
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                        KC_NUBS, KC_LCMD, KC_LALT, KC_LOWER,  KC_SPC,         KC_ENT, XXXXXXX, KC_MINS,   KC_PGUP, KC_PGDN
//                    '--------------------------------------------'      '--------------------------------------------'
    ),

    [_ADJUST] = LAYOUT(
//  .-----------------------------------------------------.                        .-----------------------------------------------------.
     XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN1,                      KC_MS_ACCEL0, KC_WH_U, KC_MS_UP, KC_WH_D, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_HUD,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN2,                         KC_MS_ACCEL1, KC_MS_LEFT, KC_MS_DOWN,  KC_MS_RIGHT, XXXXXXX, XXXXXXX,
//  |--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_BTN3, KC_SLEP,    KC_WAKE, KC_MS_ACCEL2, KC_MS_WH_LEFT, XXXXXXX,  KC_MS_WH_RIGHT, XXXXXXX, XXXXXXX,
//  '--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------'
                        KC_NUBS, KC_LCMD, KC_LALT, XXXXXXX,  KC_SPC,       KC_ENT, XXXXXXX, KC_MINS,   KC_PGUP, KC_PGDN
//                    '--------------------------------------------'      '--------------------------------------------'
    )
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)
);

const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
// const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_INDICATORS(HSV_ORANGE),
//     SET_UNDERGLOW(HSV_ORANGE),
// 	SET_NUMPAD(HSV_BLUE),
//     {7, 4, HSV_ORANGE},
//     {25, 2, HSV_ORANGE},
//     {35+6, 4, HSV_ORANGE},
//     {35+25, 2, HSV_ORANGE}
//     );
// _SWITCHER   // light up top row
// const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
// 	SET_LAYER_ID(HSV_GREEN),
// 	SET_NUMROW(HSV_GREEN)
// );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights
	// layer_numpad_lights
	// layer_switcher_lights,  // Overrides other layers
	// layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	// rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	// rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	// rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_logo_sofle(void) {
    static const char PROGMEM logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(logo, false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("Sofle"), false);
}
static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    render_logo_sofle();
    oled_write_P(PSTR("\n"), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    // switch (get_highest_layer(default_layer_state)) {
    //     case _QWERTY:
    //         oled_write_ln_P(PSTR("Qwrt"), false);
    //         break;

    //     default:
    //         oled_write_ln_P(PSTR("Undef"), false);
    // }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return true;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
	} else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
					if (clockwise) {
						tap_code(KC_PGDOWN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _RAISE:
			case _LOWER:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
        }
    }
    return true;
}

#endif
