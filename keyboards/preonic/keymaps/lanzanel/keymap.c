/* Copyright 2015-2017 Jack Humbert
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
// #include "muse.h"

enum preonic_layers {
  _BASE,
  _MOUSE,
  _FNNUMPAD,
  _GAME,
  _ADJUST
};

enum preonic_keycodes {
  BACKLIT
};

enum my_keycodes {
  MOD_SPC = LT(_FNNUMPAD,KC_SPC),
  MOD_BSPC = LT(_MOUSE,KC_BSPC)
};

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
    TD_DEL
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
    [TD_DEL] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_DEL, _MOUSE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_preonic_grid(
  KC_GESC, TD(TD_1),   TD(TD_2), TD(TD_3), TD(TD_4), TD(TD_5),  TD(TD_6),	  TD(TD_7), TD(TD_8),   TD(TD_9),    TD(TD_0),    	TO(_GAME),
  KC_TAB,  KC_Q,        KC_W,    KC_F,     KC_P,    KC_G,  		 KC_J,		    KC_L,     KC_U,       KC_Y,        TD(TD_SCLN), 	KC_HOME,
  KC_DEL,  KC_A,        KC_R,    KC_S,     KC_T,    KC_D,   	 KC_H,		    KC_N,     KC_E,       KC_I,        KC_O,    	    KC_END,
  KC_PGUP, TD(TD_SLSH), KC_Z,    KC_X,     KC_C,    KC_V, 		 KC_B,    	  KC_K,     KC_M,       TD(TD_QUOT), TD(TD_COMM),  	KC_ENT,
  KC_LCTL, KC_LGUI,     KC_LALT, KC_LSFT,  MOD_SPC, MOD_SPC,   MOD_BSPC,    MOD_BSPC, KC_CAPS,    KC_RALT,     KC_RCTL,       OSL(_FNNUMPAD)
),

[_MOUSE] = LAYOUT_preonic_grid(
  _______, KC_NO,	KC_NO,   KC_NO,   KC_NO,    KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_NO,	KC_ACL0, KC_ACL1, KC_ACL2,  KC_NO,       KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO,   _______,
  _______, KC_TAB,KC_NO,   KC_NO,   KC_BRID,  KC_BRIU,     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,   _______,
  _______, LSFT(KC_TAB),	KC_MPLY, KC_MUTE, KC_VOLD,  KC_VOLU,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______, _______, 	_______,  _______, MO(_ADJUST), MO(_ADJUST), _______, _______, _______, _______, _______, _______
),

[_FNNUMPAD] = LAYOUT_preonic_grid(
  _______, KC_F1,	KC_F2,    KC_F3,    KC_F4,    KC_F5,	 KC_F6,       KC_F7, KC_F8,  KC_F9,     KC_F10,       KC_F11,
  _______, KC_NO,	KC_PGDN,  KC_UP,    KC_PGUP,  TD(TD_MINS), TD(TD_EQL),  KC_7,  KC_8,   KC_9,      KC_0,         KC_F12,
  _______, KC_TAB,   	KC_LEFT,  KC_DOWN,  KC_RGHT,  TD(TD_LBRC), TD(TD_RBRC), KC_4,  KC_5,   KC_6,      TD(TD_BSLS),  _______,
  _______, LSFT(KC_TAB),	KC_MPLY,  KC_MUTE,  KC_VOLD,  KC_VOLU,     KC_GRV,      KC_1,  KC_2,   KC_3,      TD(TD_QUOT),  _______,
  _______, _______, 	_______,  _______,  _______,  _______,     MO(_ADJUST), MO(_ADJUST),  _______,    _______,   _______,      _______
),

[_GAME] = LAYOUT_preonic_grid(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TO(_BASE),
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PSCR,
  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_END,
  KC_PGUP, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_ENT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  KC_BSPC, KC_BSPC, KC_CAPS, KC_RALT, KC_RCTL, OSL(_FNNUMPAD),   
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_MOUSE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}


/* this has raise and lower which i deleted so idk if need ko pa
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
*/