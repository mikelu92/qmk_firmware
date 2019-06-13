#include QMK_KEYBOARD_H
#include "leader_macros.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _KEYPAD 4
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  KEYPAD,
  TABU,
  TABD,
  COL_EQL,
};

#define _______ KC_TRNS

// app specific macros
#define AUTOFIL  LCMD(KC_BSLS) // autofill forms in firefox(1pwd)
#define SRCHPWD  LCMD(LALT(KC_BSLS)) // open 1pwd extension in firefox
#define FOCUSMD  LALT(LGUI(KC_F)) // focus mode for notable
#define LSCRN LCTL(LSFT(KC_LEFT)) // BetterTouchTools move cursor left monitor
#define USCRN LCTL(LSFT(KC_UP)) // BetterTouchTools move cursor up monitor
#define DSCRN LCTL(LSFT(KC_DOWN)) // BetterTouchTools move cursor down monitor
#define RSCRN LCTL(LSFT(KC_RIGHT)) // BetterTouchTools move cursor right monitor
#define CHKESC HYPR(KC_C) //chunkwm leader key
#define TMUXPRF LCTL(KC_A) // tmux leader key
#define VIMWIND LCTL(KC_W) // vim windows leader key
#define CTL_U LCTL(KC_U) // vim page up
#define CTL_D LCTL(KC_D) // vim page down

// mac macros
#define DSP_OFF  LCMD(LCTL(KC_Q)) // turn the display off
#define SWPL LCTL(KC_LEFT) // move to left workspace
#define SWPR LCTL(KC_RIGHT) // move to right workspace
#define ALT_L LALT(KC_LEFT) // move one word left
#define ALT_R LALT(KC_RGHT) // move one word right
#define WIN_L LGUI(LSFT(KC_TILD)) // cycle backwards through same app windows
#define WIN_R LGUI(KC_TILD) // cycle through same app windows

// hybrid keys & shorthand
#define SFT_ENT  SFT_T(KC_ENT) // Enter when tapped, shift when held
#define CTL_ESC  CTL_T(KC_ESC) // Esc when tapped, ctrl when held
#define TAP_RSE  OSL(_RAISE) // tap to raise
#define TAP_SFT  OSM(MOD_LSFT) // tap shift
#define TAP_ALT  OSM(MOD_LALT) // tap alt
#define TAP_HPR  OSM(MOD_HYPR) // tap hyper

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT( \
     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_HOME,                        KC_PGUP, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
     KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_END,                         KC_PGDN, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
     KC_LALT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   TAP_ALT,                        SFT_ENT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,  \
     TAP_RSE, TAP_SFT, KC_LEAD, KC_LGUI,          LOWER,  KC_SPC,  CTL_ESC,      SFT_ENT, SFT_ENT, RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT, _______,          LOWER,   KC_SPC , KC_DEL,       KC_BSPC, KC_ENT , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  [_LOWER] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQT , \
    KC_DEL,  KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, _______, _______,                        _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU,    TABD,    COL_EQL, \
    DSP_OFF, WIN_L,   WIN_R,   _______,          _______, _______, _______,      _______, _______, _______,          _______, KC_VOLD, KC_VOLU, KC_MUTE  \
  ),

  [_RAISE] = LAYOUT( \
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  FOCUSMD, _______,                        _______, _______, _______, CHKESC,  _______, _______, KEYPAD,  \
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   CTL_U,   _______,                        _______, _______, AUTOFIL, TMUXPRF, TABU,    TABD,    _______, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   CTL_D,   _______,                        _______, _______, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          LSCRN,   DSCRN,   USCRN,   RSCRN    \
  ),

  [_ADJUST] = LAYOUT( \
    _______, RESET  , _______, KC_UP,   _______, _______, _______,                        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______, \
    _______, _______, ALT_L,   KC_DOWN, ALT_R,   _______, _______,                        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, \
    _______, _______, _______, KC_DOWN, KEYPAD,  _______, _______,                        _______, _______, _______, _______, QWERTY,  DVORAK,  _______, \
    RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,          _______, _______, _______,      _______, _______, _______,          RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI \
  ),

  [_KEYPAD] = LAYOUT(
    _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,                        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PSLS, \
    _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,                        _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PMNS, \
    _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, DVORAK,                         KC_PENT, _______, KC_P1,   KC_P2,   KC_P3,   KC_UP,   KC_PPLS, \
    _______, _______, KC_PDOT, KC_P0,            _______, _______, _______,      KC_PENT, KC_PENT, KC_PDOT,          KC_P0,   KC_LEFT, KC_DOWN, KC_RGHT  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case KEYPAD:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_KEYPAD);
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
    case TABD:
      if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LCTRL)SS_TAP(X_TAB)SS_UP(X_LCTRL));
      }
      return false;
      break;
    case TABU:
      if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
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
