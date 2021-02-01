/*
Copyright 2020 Pabile

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

#define BASE 0
#define MOUSE 1
#define NUMPAD 2
#define FN 3

// Tap Dance declarations
enum {
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
    TD_0,
    TD_CAPS,
    TD_LBRC,
    TD_RBRC,
    TD_SLSH,
    TD_MINS,
    TD_EQL,
    TD_QUOT,
    TD_SCLN,
    TD_BSLS,
    TD_COMM,
    TD_DEL,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap Dance for numpad and symbols
    [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
    [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
    [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
    [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
    [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
    [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
    [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
    [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
    [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
    [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
	// Tap Dance for left shift and caps lock
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
	// Tap Dance for other alpha symbols
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
	// Tap Dance for period to comma for base layer to make space for quot
    [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
	// Tap Dance for delete into mouse toggle
    [TD_DEL] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_DEL, MOUSE)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ortho_4x10(
		KC_Q,        	KC_W,    KC_F,    KC_P,             KC_G,                KC_J,         KC_L,       KC_U,        KC_Y,        TD(TD_SCLN), 
		KC_A,        	KC_R,    KC_S,    KC_T,             KC_D,                KC_H,         KC_N,       KC_E,        KC_I,        KC_O, 
		TD(TD_SLSH),  	KC_Z,    KC_X,    KC_C,             KC_V,                KC_B,         KC_K,       KC_M,        TD(TD_QUOT), TD(TD_COMM),
		LCTL_T(KC_GESC), KC_LALT, KC_LGUI, TD(TD_CAPS), LT(NUMPAD,KC_SPC),  LT(MOUSE,KC_BSPC),  KC_RSFT,    TD(TD_DEL),  OSL(FN),   KC_ENT),
  [MOUSE] = LAYOUT_ortho_4x10(
		XXXXXXX,    	KC_ACL0,   KC_ACL1,   KC_ACL2, XXXXXXX, KC_WH_U,   KC_BTN1,    KC_MS_U,    KC_BTN2,    KC_PGUP, 
		KC_TAB,  	XXXXXXX,   XXXXXXX,   KC_BRID, KC_BRIU, KC_WH_D,   KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_PGDN, 
		LSFT(KC_TAB),    KC_MPLY,   KC_MUTE,   KC_VOLD, KC_VOLU, XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ACL1,
    		_______,   	_______,   _______,   _______, _______, _______,   _______,    _______,    _______,    _______),
  [NUMPAD] = LAYOUT_ortho_4x10(
    		XXXXXXX,   	KC_PGDN,     KC_UP,   KC_PGUP,   TD(TD_MINS),  	TD(TD_EQL),     TD(TD_7),       TD(TD_8),       TD(TD_9),       TD(TD_0), 
		KC_TAB,  	KC_LEFT,   KC_DOWN,   KC_RGHT,   TD(TD_LBRC), 	TD(TD_RBRC),    TD(TD_4),       TD(TD_5),       TD(TD_6),    TD(TD_BSLS), 
		LSFT(KC_TAB),    KC_MPLY,   KC_MUTE,   KC_VOLD,   KC_VOLU,  	KC_GRV,         TD(TD_1),       TD(TD_2),       TD(TD_3),    TD(TD_QUOT),
    		_______,   	_______,   _______,   _______,   _______,          _______,         _______,        _______,        _______,        _______),
  [FN] = LAYOUT_ortho_4x10(
		KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,   KC_F7,     KC_F8,   KC_F9,    KC_F10, 
		KC_TAB,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX,   KC_F11,   KC_F12, 
		KC_CAPS, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,
    		_______, _______,   _______,   _______,   _______,   _______, _______,   _______,   _______, _______)
};
