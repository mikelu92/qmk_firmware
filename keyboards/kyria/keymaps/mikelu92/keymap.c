/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "leader_macros.h"
#include <stdio.h>

enum combos {
    OEU_ARROWS
};

const uint16_t PROGMEM arrows_combo[] = {KC_O, KC_E, KC_U, COMBO_END};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  ARROWS,
  COL_EQL,
  DVWIN,
  QWWIN,
  LOWIN,
  RAWIN,
  ADWIN,
  ARWIN,
};

enum layers {
    _DVORAK = 0,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARROWS,
    _DVORAK_WIN,
    _QWERTY_WIN,
    _LOWER_WIN,
    _RAISE_WIN,
    _ADJUST_WIN,
    _ARROWS_WIN,
};

enum current_os {
    mac = 0,
    win,
};

enum current_os currentOS = mac;

// app specific macros
#define AUTOFIL  LCMD(KC_BSLS) // autofill forms in firefox(1pwd)
#define AFWIN    LCTL(KC_BSLS) // autofill forms in firefox(1pwd windows)
#define SRCHPWD  LCMD(LALT(KC_BSLS)) // open 1pwd extension in firefox
#define SPWIN    LCTL(LALT(KC_BSLS)) // open 1pwd extension in firefox on windows
#define CHKESC HYPR(KC_C) //chunkwm leader key
#define TMUXPRF LCTL(KC_A) // tmux leader key
#define VIMWIND LCTL(KC_W) // vim windows leader key
#define CTL_U LCTL(KC_U) // vim page up
#define CTL_D LCTL(KC_D) // vim page down
#define SCRNLYR LM(_ARROWS, MOD_LCTL | MOD_LSFT) // BetterTouchTools move screen arrow layer modifier

// mac macros
#define DSP_OFF  LCMD(LCTL(KC_Q)) // turn the display off
#define SWPL LCTL(KC_LEFT) // move to left workspace
#define SWPR LCTL(KC_RIGHT) // move to right workspace
#define ALT_L LALT(KC_LEFT) // move one word left
#define ALT_R LALT(KC_RGHT) // move one word right


// windows macros
#define WINSWPL  LCTL(LGUI(KC_LEFT)) // move to left workspace
#define WINSWPR  LCTL(LGUI(KC_RIGHT)) // move to right workspace
#define SCRNOFF  LGUI(KC_L) // turn the display off
#define CTL_L LCTL(KC_LEFT) // move one word left (win)
#define CTL_R LCTL(KC_RGHT) // move one word right (win)


// hybrid keys & shorthand
#define SFT_ENT  SFT_T(KC_ENT) // Enter when tapped, shift when held
#define CTL_ESC  CTL_T(KC_ESC) // Esc when tapped, ctrl when held
#define CTL_SFT  LCTL(KC_LSFT) // Ctrl + Shift
#define GUI_ESC  GUI_T(KC_ESC) // Esc when tapped, gui when held
#define TAP_SFT  OSM(MOD_LSFT) // tap shift
#define TABU_N LCTL(S(KC_TAB))
#define TABD_N LCTL(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
      KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
      KC_HYPR, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_SPC,  KC_LALT,  KC_PGUP, SFT_ENT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,
                                 TAP_SFT, KC_LGUI, LOWER,   KC_SPC,  CTL_ESC,  KC_PGDN, SFT_ENT, RAISE,   ARROWS,  KC_LEAD
    ),

    [_QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_LALT,  KC_HYPR, SFT_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 KC_HYPR, KC_LGUI, LOWER,   KC_SPC,  CTL_ESC,  KC_LALT, SFT_ENT, RAISE,   ARROWS,  KC_LEAD
    ),

    [_LOWER] = LAYOUT(
      KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT ,
      DSP_OFF, KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, ARROWS,  _______, _______,  KC_VOLU, _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU_N,  TABD_N,  COL_EQL,
                                 _______, _______, _______, _______, _______,  KC_VOLD, _______, _______, KC_LCTL, KC_LALT
    ),

    [_RAISE] = LAYOUT(
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                                      _______, _______, CHKESC,  _______, _______, _______,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,                                        _______, AUTOFIL, TMUXPRF, TABU_N,  TABD_N,  _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   _______, _______,  RGB_MOD, _______, SCRNLYR, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1,
                                 _______, _______, _______, _______, _______,  RGB_TOG, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      RESET  , QWERTY,  _______, KC_UP,   _______, _______,                                      _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______, 
      _______, _______, ALT_L,   KC_DOWN, ALT_R,   _______,                                      DVORAK,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, 
      _______, DVWIN,   _______, KC_DOWN, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,
                                 _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),

    [_ARROWS] = LAYOUT(
      _______, _______, _______, KC_UP,   _______, KC_HOME,                                      KC_PGUP, _______, KC_UP,   _______, KC_RGHT, _______, 
      _______, _______, ALT_L,   KC_DOWN, ALT_R,   KC_END,                                       KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, 
      _______, _______, _______, KC_DOWN, KC_UP,   KC_HOME, _______, KC_LALT,  CTL_SFT, KC_LCTL, _______, _______, _______, SWPL,    SWPR,    _______,
                                 _______, _______, KC_END,  _______, KC_LCTL,  _______, KC_LCTL, _______, _______, _______
    ),
    [_DVORAK_WIN] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
      KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
      KC_MEH,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_SPC,  KC_LALT,  KC_PGUP, SFT_ENT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,
                                 TAP_SFT, KC_LCTL, LOWIN,   KC_SPC,  GUI_ESC,  KC_PGDN, SFT_ENT, RAWIN,   ARWIN,   KC_LEAD
    ),

    [_QWERTY_WIN] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,  KC_LALT,  KC_HYPR, SFT_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 KC_HYPR, KC_LCTL, LOWER,   KC_SPC,  GUI_ESC,  KC_LALT, SFT_ENT, RAISE,   ARWIN,   KC_LEAD
    ),

    [_LOWER_WIN] = LAYOUT(
      KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT ,
      SCRNOFF, KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, ARWIN,  _______, _______,   KC_VOLU, _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU_N,  TABD_N,  COL_EQL,
                                 _______, _______, _______, _______, _______,  KC_VOLD, _______, _______, KC_LCTL, KC_LALT
    ),

    [_RAISE_WIN] = LAYOUT(
      _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                                      _______, _______, CHKESC,  _______, _______, _______,
      _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,                                        _______, AFWIN,   TMUXPRF, TABU_N,  TABD_N,  _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   _______, _______,  RGB_MOD, _______, SCRNLYR, SPWIN,   VIMWIND, WINSWPL, WINSWPR, KC_BTN1,
                                 _______, _______, _______, _______, _______,  RGB_TOG, _______, _______, _______, _______
    ),

    [_ADJUST_WIN] = LAYOUT(
      RESET  , QWWIN,   _______, KC_UP,   _______, _______,                                      _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______, 
      _______, _______, CTL_L,   KC_DOWN, CTL_R,   _______,                                      DVWIN,   KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, 
      _______, DVORAK,  _______, KC_DOWN, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,
                                 _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),

    [_ARROWS_WIN] = LAYOUT(
      _______, _______, _______, KC_UP,   _______, KC_HOME,                                      KC_PGUP, _______, KC_UP,   _______, KC_RGHT, _______, 
      _______, _______, CTL_L,   KC_DOWN, CTL_R,   KC_END,                                       KC_PGDN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, 
      _______, _______, _______, KC_DOWN, KC_UP,   KC_HOME, _______, KC_LALT,  CTL_SFT, KC_LCTL, _______, _______, _______, WINSWPL, WINSWPR, _______,
                                 _______, _______, KC_END,  _______, KC_LCTL,  _______, KC_LCTL, _______, _______, _______
    ),
};

combo_t key_combos[COMBO_COUNT] = {
    [OEU_ARROWS] = COMBO_ACTION(arrows_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    switch(combo_index) {
        case OEU_ARROWS: ;
            enum layers l = _ARROWS;
            if (currentOS != mac) {
                l = _ARROWS_WIN;
            }
            if (pressed) {
                layer_on(l);
            } else {
                layer_off(l);
            }
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
        currentOS = mac;
      }
      return false;
      break;
    case DVWIN:
      if (record->event.pressed) {
          set_single_persistent_default_layer(_DVORAK_WIN);
          currentOS = win;
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case QWWIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_WIN);
      }
      return false;
      break;
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
    case LOWIN:
      if (record->event.pressed) {
        layer_on(_LOWER_WIN);
        update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
      } else {
        layer_off(_LOWER_WIN);
        update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
      }
      return false;
      break;
    case RAWIN:
      if (record->event.pressed) {
        layer_on(_RAISE_WIN);
        update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
      } else {
        layer_off(_RAISE_WIN);
        update_tri_layer(_LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
      }
      return false;
      break;
    case ADWIN:
      if (record->event.pressed) {
        layer_on(_ADJUST_WIN);
      } else {
        layer_off(_ADJUST_WIN);
      }
      return false;
      break;
    case ARROWS:
      if (record->event.pressed) {
          layer_on(_ARROWS);
      } else {
          layer_off(_ARROWS);
      }
      return false;
      break;
    case ARWIN:
      if (record->event.pressed) {
          layer_on(_ARROWS_WIN);
      } else {
          layer_off(_ARROWS_WIN);
      }
      return false;
      break;
    case COL_EQL:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSHIFT)";"SS_UP(X_LSHIFT)"=");
      }
      return false;
      break;
  }
  return true;
}

void matrix_scan_user(void) {
    leader_func();
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_leader_macros(void) {
    oled_write_P(PSTR("Macro Sequence\n\n"), true);
    oled_write_P(PSTR("ts: tmux window panes"), false);
    oled_write_P(PSTR("ut: update vm time\n"), false);
}

static void render_kyria_logo(void) {
    static const char PROGMEM gp_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 
        0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x3f, 
        0x3f, 0x3f, 0x3f, 0x3e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x1e, 0xfe, 
        0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x1e, 0x1e, 0x1e, 0x1e, 0x3e, 0x3e, 0x7e, 0xfc, 0xfc, 0xf8, 0xf0, 
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x03, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xf0, 0xff, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
        0xff, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0xf3, 
        0xf9, 0xfd, 0xff, 0xff, 0xff, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7e, 0x3f, 0x3f, 0x1f, 0x1f, 0x07, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(gp_logo, sizeof(gp_logo));
}

static void render_status(void) {
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _QWERTY:
        case _QWERTY_WIN:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _LOWER:
        case _LOWER_WIN:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
        case _RAISE_WIN:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
        case _ADJUST_WIN:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _ARROWS:
        case _ARROWS_WIN:
            oled_write_P(PSTR("Arrow\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef\n"), false);
    }
    oled_write_P(PSTR("OS: "), false);
    if (currentOS == win) {
        oled_write_P(PSTR("Win\n"), false);
    } else {
        oled_write_P(PSTR("Mac\n"), false);
    }
}


void oled_task_user(void) {
    if (is_keyboard_master()) {
#ifdef LEADER_ENABLE
        if (leader_started && timer_elapsed(leader_timer) < 1000) {
            render_leader_macros();
            return;
        }
#endif
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
