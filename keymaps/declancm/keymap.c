/* Copyright 2015-2021 Jack Humbert
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

enum preonic_layers {
    _ZERO,
    _ONE,
    _TWO
};

enum preonic_keycodes {
  ZERO = SAFE_RANGE,
  ONE,
  TWO
};

enum custom_keycodes {
  RGB_Cap = SAFE_RANGE,
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_ZERO] = LAYOUT_preonic_2x2u(
  KC_PSCR, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,  KC_F6,   KC_F7,   KC_F8,         KC_F9,          KC_F10,  KC_DEL,
  KC_TAB,  KC_Q,    KC_W,    KC_F,     KC_P,    KC_B,   KC_J,    KC_L,    KC_U,          KC_Y,           KC_SCLN, KC_BSLS,
  KC_LCTL, KC_A,    KC_R,    KC_S,     KC_T,    KC_G,   KC_M,    KC_N,    KC_E,          KC_I,           KC_O,    KC_ENT,
  KC_HOME, KC_Z,    KC_X,    KC_C,     KC_D,    KC_V,   KC_K,    KC_H,    KC_COMM,       KC_DOT,         KC_SLSH, KC_END,
  RGB_Cap, KC_LALT, KC_LGUI, MO(_ONE), LSFT_T(KC_BSPC), LT(_TWO, KC_SPC), RALT_T(KC_ESC),RGUI_T(KC_INS), KC_PGUP, KC_PGDN
),


[_ONE] = LAYOUT_preonic_2x2u(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_J,    KC_7,    KC_8,    KC_9,    KC_PLUS, XXXXXXX,
  KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_4,    KC_5,    KC_6,    KC_COMM, KC_RPRN,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_K,    KC_1,    KC_2,    KC_3,    KC_EQL,  XXXXXXX,
  XXXXXXX, KC_LALT, KC_LGUI, KC_TRNS,  LSFT_T(KC_BSPC), LT(_TWO, KC_SPC), KC_0,    KC_DOT,  KC_ENT,  XXXXXXX
),


[_TWO] = LAYOUT_preonic_2x2u(
  KC_PSCR, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_ENT,
  KC_HOME, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,
  XXXXXXX, KC_LALT, KC_LGUI, KC_ENT,   LSFT_T(KC_BSPC), LT(_TWO, KC_SPC), XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_Cap:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_toggle();
                rgblight_setrgb(RGB_RED);
                #endif
                tap_code(KC_CAPS);
            }
            else { }
            break;
    }
    return true;
}