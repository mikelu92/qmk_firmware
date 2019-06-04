/* Copyright 2017 IslandMan93
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
#include "diverge3.h"
#include "action_layer.h"
#include "eeconfig.h"

//**************** Definitions needed for quad function to work *********************//
enum {
  SE_TAP_DANCE = 0
};
//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//**************** Definitions needed for quad function to work *********************//
// Backspace Shift TD
//instanalize an instance of 'tap' for the 'x' tap dance.
static tap se_tap_state = {
  .is_press_action = true,
  .state = 0
};

void se_finished (qk_tap_dance_state_t *state, void *user_data) {
  se_tap_state.state = cur_dance(state);
  switch (se_tap_state.state) {
    case SINGLE_TAP: register_code(KC_SPC); break;
    case SINGLE_HOLD: register_code(KC_ENT); break;
    default: register_code(KC_SPC); unregister_code(KC_SPC); register_code(KC_SPC);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void se_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (se_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SPC); break;
    case SINGLE_HOLD: unregister_code(KC_ENT); break;
    default: unregister_code(KC_SPC);
  }
  se_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SE_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, se_finished, se_reset)
};

// KEYMAP
extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  LOWER= SAFE_RANGE,
  RAISE,
  ADJUST,
  TABU,
  TABD,
  VIMTABU,
  VIMTABD,
};

// Make layer undefined do nothing
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define SFT_ENT  SFT_T(KC_ENT) // Enter when tapped, shift when held
#define CTL_ESC  CTL_T(KC_ESC) // Esc when tapped, ctrl when held
#define GUI_CTL  MT(MOD_LGUI, OSM(MOD_LCTL)) // Ctrl when tapped, gui (command) when held
#define TAP_RSE  OSL(_RAISE) // tap to raise
#define AUTOFIL  LCMD(KC_BSLS) // autofill forms in firefox(1pwd)
#define SRCHPWD  LCMD(LALT(KC_BSLS)) // open 1pwd extension in firefox

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVORAK] = KEYMAP(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                   XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_HOME,                   KC_PGUP, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_END,                    KC_PGDN, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_BSPC, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LALT,                   KC_MEH,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_MINS, \
  CTL_ESC, KC_LSFT, ADJUST,  KC_LALT, KC_LGUI, KC_SPC,  LOWER,    RAISE,   LOWER,  RAISE,   SFT_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL   \
),
[_LOWER] = KEYMAP(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TABU,                      VIMTABU, KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TABD,                      VIMTABD, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
  _______, TABU,    TABD,    KC_LCBR, KC_RCBR, _______, _______,                   _______, _______, KC_LBRC, KC_RBRC, TABU,    TABD, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______  \
),
[_RAISE] = KEYMAP(
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, TABU,                      VIMTABU, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, TABD,                      VIMTABD, AUTOFIL, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,                   _______, SRCHPWD, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P0,   KC_PENT, KC_PLUS, _______  \
),
[_ADJUST] = KEYMAP(
  _______, RESET,   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_UP,   _______, _______, TABU,                      VIMTABU, _______, _______, KC_UP,   _______, _______, _______, \
  _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, TABD,                      VIMTABD, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case VIMTABD:
      if (record->event.pressed) {
              SEND_STRING("gt");
      }
      return false;
    case VIMTABU:
      if (record->event.pressed) {
              SEND_STRING("gT");
      }
      return false;
    case TABD:
      if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_TAB)SS_UP(X_LCTRL));
      }
      return false;
    case TABU:
      if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
      }
      return false;
  }
  return true;
}
