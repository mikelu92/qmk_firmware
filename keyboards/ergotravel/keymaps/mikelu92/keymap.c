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
  TABU,
  TABD,
  VIMTABU,
  VIMTABD,
  SSH_SEU,
  SSH_C7,
  COL_EQL,
  KEYPAD
};

// #define KC_ KC_TRNS
#define SFT_ENT  SFT_T(KC_ENT) // Enter when tapped, shift when held
#define _______ KC_TRNS
#define CTL_ESC  CTL_T(KC_ESC) // Esc when tapped, ctrl when held
#define ALT_EQL  ALT_T(KC_EQL) // = when tapped, alt when held
#define ALT_RGT  ALT_T(KC_RIGHT) // right when tapped, alt when held
#define TAP_RSE  OSL(_RAISE) // tap to raise
#define TAP_SFT  OSM(MOD_LSFT) // tap shift
#define TAP_ALT  OSM(MOD_LALT) // tap alt
#define TAP_HPR  OSM(MOD_HYPR) // tap hyper
#define AUTOFIL  LCMD(KC_BSLS) // autofill forms in firefox(1pwd)
#define ALT_CMD  LALT(KC_LGUI) // alt + cmd (for quiver)
#define SRCHPWD  LCMD(LALT(KC_BSLS)) // open 1pwd extension in firefox
#define DSP_OFF  LCMD(LCTL(KC_Q)) // turn the display off
#define HOME_A   CTL_T(KC_A)
#define HOME_S   CTL_T(KC_S)
#define NOTE_UP  MEH(KC_TAB)
#define NOTE_DN  LCTL(LALT(KC_TAB))
#define FOCUSMD  LALT(LGUI(KC_F)) // focus mode for notable
#define LSCRN LCTL(LSFT(KC_LEFT))
#define USCRN LCTL(LSFT(KC_UP))
#define DSCRN LCTL(LSFT(KC_DOWN))
#define RSCRN LCTL(LSFT(KC_RIGHT))
#define SWPL LCTL(KC_LEFT)
#define SWPU LCTL(KC_UP)
#define SWPR LCTL(KC_RIGHT)
#define CHKESC HYPR(KC_C)
#define TMUXPRF LCTL(LALT(KC_A))
#define VIMWIND LCTL(KC_W)
#define ALT_L LALT(KC_LEFT)
#define ALT_R LALT(KC_RGHT)
#define ALT_U LALT(KC_UP)
#define ALT_D LALT(KC_DOWN)
#define WIN_L LGUI(LSFT(KC_TILD))
#define WIN_R LGUI(KC_TILD)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_HOME,          KC_PGUP, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_END,           KC_PGDN, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LALT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    CTL_ESC,          TAP_ALT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     TAP_RSE, TAP_SFT, KC_LEAD, KC_LGUI,          LOWER,   KC_SPC,           SFT_ENT, RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_A,             KC_A,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_A,             KC_SPC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LGUI, KC_LALT, ADJUST,           LOWER,   KC_SPC,           KC_SPC,  RAISE,            KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TABU,             NOTE_UP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TABD,             NOTE_DN, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_DEL,  KC_COLN, KC_TILD, KC_LCBR, KC_RCBR, KC_TILD, _______,          _______, KC_PIPE, KC_LBRC, KC_RBRC, TABU,    TABD,    COL_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     DSP_OFF, WIN_L,   WIN_R,   _______,          _______, _______,          _______, _______,          ALT_CMD, KC_VOLD, KC_VOLU, KC_MUTE
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),

  [_RAISE] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     KC_GRV,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  FOCUSMD, TABU,             VIMTABU, SSH_SEU, SSH_C7,  CHKESC,  _______, _______, KEYPAD,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, TABD,             VIMTABD, _______, AUTOFIL, TMUXPRF, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,          _______, _______, SRCHPWD, VIMWIND, SWPL,    SWPR,    KC_BTN1,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, _______,          LSCRN,   DSCRN,   USCRN,   RSCRN 
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),
  [_ADJUST] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, RESET,   _______, KC_UP,   _______, _______, _______,          _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_DEL,  _______, ALT_L,   KC_DOWN, ALT_R,   _______, _______,          _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, KC_DOWN, KEYPAD,  _______, _______,          _______, _______, _______, _______, QWERTY,  DVORAK,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  ),
  [_KEYPAD] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------.        ,--------+--------+--------+--------+--------+--------+--------.
     _______, _______, _______, _______, _______, _______, TABU,             VIMTABU, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     KC_BSPC, _______, _______, _______, _______, _______, TABD,             VIMTABD, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______, DVORAK,           DVORAK,  _______, KC_P1,   KC_P2,   KC_P3,   KC_UP,   KC_PPLS,
  //|--------+--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______,          _______, _______,          KC_PENT, KC_PDOT,          KC_P0,   KC_LEFT, KC_DOWN, KC_RGHT 
  //`--------+--------+--------+--------+--------+--------+--------/        \--------+--------+--------+--------+--------+--------+--------'
  )


};






uint16_t alt_eql_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case KEYPAD:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
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
    case VIMTABD:
      if (record->event.pressed) {
              SEND_STRING("gt");
      }
      return false;
      break;
    case VIMTABU:
      if (record->event.pressed) {
              SEND_STRING("gT");
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
    case SSH_C7:
      if (record->event.pressed) {
          SEND_STRING("ssh c7"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case SSH_SEU:
      if (record->event.pressed) {
          SEND_STRING("ssh seu1.prod"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case COL_EQL:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSHIFT)";"SS_UP(X_LSHIFT)"=");
      }
      return false;
      break;
 /*   case ALT_EQL:
      if (record->event.pressed) {
          alt_eql_timer = timer_read();
          register_code(KC_LALT);
      } else {
          unregister_code(KC_LALT);
          if (timer_elapsed(alt_eql_timer)<200){
              register_code(KC_EQL);
              unregister_code(KC_EQL);
          }
      }
      */
  }
  return true;
}

void matrix_scan_user(void) {
    leader_func();
}

