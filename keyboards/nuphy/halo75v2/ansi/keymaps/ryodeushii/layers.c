#include "action_layer.h"
#include "color.h"
#include "keycodes.h"
#include "keymap_common.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "ansi.h"
#include "user_kb.h"

extern DEV_INFO_STRUCT dev_info;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case 0:
        case 2:
            break;
        default: {
            for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                    uint8_t index = g_led_config.matrix_co[row][col];

                    if (index >= led_min && index <= led_max && index != NO_LED) {
                        int keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

                        if ((keycode >= SIDE_VAI && keycode <= SIDE_SPD) || keycode == POWER_ON_TOGGLE) {
                            rgb_matrix_set_color(index, RGB_YELLOW);
                        } else if (keycode >= DEBOUNCE_PRESS_INC && keycode <= DEBOUNCE_PRESS_SHOW) {
                            rgb_matrix_set_color(index, 0, 255, 0);
                        } else if (keycode >= DEBOUNCE_RELEASE_INC && keycode <= DEBOUNCE_RELEASE_SHOW) {
                            rgb_matrix_set_color(index, 255, 0, 0);
                        } else if (keycode == SLEEP_MODE || keycode == TOG_USB_SLP || keycode == DEEP_SLEEP_TOGGLE || (keycode >= SLEEP_TIMEOUT_INC && keycode <= SLEEP_TIMEOUT_SHOW)) {
                            rgb_matrix_set_color(index, RGB_CYAN);
                        } else if (keycode >= LNK_USB && keycode <= LNK_BLE3) {
                            if (dev_info.link_mode != LINK_USB) {
                                rgb_matrix_set_color(index, RGB_BLUE);
                            }
                        } else if (keycode > KC_NUM_LOCK && keycode <= KC_KP_DOT ) {
                            rgb_matrix_set_color(index, RGB_RED);
                        } else if (keycode > KC_TRNS) {
                            rgb_matrix_set_color(index, 225, 65, 140);
                        }
                    }
                }
            }
        }
    }

    uint8_t showNumLock = 0;
    if (dev_info.link_mode != LINK_USB) {
        showNumLock = dev_info.rf_led & 0x01;
    } else {
        showNumLock = host_keyboard_led_state().num_lock;
    }

    if (showNumLock) {
        rgb_matrix_set_color(get_led_index(0, 14), 0x00, 0x80, 0x00);
    }


    return true;
}
