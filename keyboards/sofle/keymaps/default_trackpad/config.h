#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define RGB_DI_PIN D3
#define RGBLED_NUM 14
#define RGBLED_SPLIT {7,7}
#define RGBLIGHT_ANIMATIONS

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE

// # cirque trackpad
#define POINTING_DEVICE_ROTATION_270
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_TAP_ENABLE
