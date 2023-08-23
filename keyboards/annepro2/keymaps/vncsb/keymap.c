 /* Copyright 2021 OpenAnnePro community
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

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

enum LAYERS {
    BASE,
    HOME_MOD,
    UTILS,
    LAYER_SELECT,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi(
    QK_GESC,                   KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,                    KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    LT(LAYER_SELECT, KC_CAPS), KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT,                   KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_UP,
    KC_LCTL,                   KC_LGUI, KC_LALT,                   KC_SPC,           KC_RALT, LT(UTILS, KC_LEFT), KC_DOWN, KC_RGHT
),
 [HOME_MOD] = LAYOUT_60_ansi(
    QK_GESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______,  _______,
    _______, HOME_A,  HOME_S,  HOME_D,  HOME_F,  _______, _______, HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
    _______, _______, _______,                            _______,                   _______, _______,   _______, _______
),
 [UTILS] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2, KC_F3, KC_F4,   KC_F5,         KC_F6,         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, KC_7,    KC_8,  KC_9,  KC_PSLS, _______,       _______,       KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______, _______,
    _______, KC_4,    KC_5,  KC_6,  KC_PAST, KC_AP_RGB_MOD, KC_AP_RGB_TOG, KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______,
    _______, KC_1,    KC_2,  KC_3,  KC_PPLS, KC_PMNS,       KC_F9,         KC_F10,  KC_F11,  KC_F12, _______, _______,
    _______, _______, KC_0,                            KC_PENT,                   _______, _______, _______, _______
),
 [LAYER_SELECT] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, TG(HOME_MOD), TG(UTILS), _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______, _______
)
};

// clang-format on

void keyboard_post_init_user(void) {
    ap2_led_enable();
    ap2_led_set_profile(27);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case LAYER_SELECT:
            // Set the leds to yellow
            ap2_led_set_foreground_color(0xFF, 0xFF, 0x00);
            break;
        case BASE:
            // Set the leds to red
            ap2_led_set_foreground_color(0xFF, 0x00, 0x00);
            break;
        case UTILS:
            // Set the leds to green
            ap2_led_set_foreground_color(0x00, 0xFF, 0x00);
            break;
        default:
            // Reset back to the current profile
            ap2_led_reset_foreground_color();
            break;
    }
    return state;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        // Set left special keys to blue
        const ap2_led_t color = {.p.red = 0x00, .p.green = 0x00, .p.blue = 0xff, .p.alpha = 0xff};
        ap2_led_sticky_set_key(0, 0, color);
        ap2_led_sticky_set_key(1, 0, color);
        ap2_led_sticky_set_key(2, 0, color);
        ap2_led_sticky_set_key(3, 0, color);
        ap2_led_sticky_set_key(4, 0, color);
        ap2_led_sticky_set_key(4, 1, color);
        ap2_led_sticky_set_key(4, 2, color);
    } else {
        // Reset the left side if there is no layer active
        ap2_led_unset_sticky_key(0, 0);
        ap2_led_unset_sticky_key(1, 0);
        ap2_led_unset_sticky_key(2, 0);
        ap2_led_unset_sticky_key(3, 0);
        ap2_led_unset_sticky_key(4, 0);
        ap2_led_unset_sticky_key(4, 1);
        ap2_led_unset_sticky_key(4, 2);
    }

    return true;
}
