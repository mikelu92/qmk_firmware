#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_steno.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _PLOVER 4
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  TABU,
  TABD,
  PLOVER,
  EXT_PLV,
};

// Fillers to make layering more clear
#define _______  KC_TRNS
#define XXXXXXX  KC_NO
#define SFT_ENT  SFT_T(KC_ENT) // Enter when tapped, shift when held
#define CTL_ESC  CTL_T(KC_ESC) // Esc when tapped, ctrl when held
#define GUI_CTL  MT(MOD_LGUI, OSM(MOD_LCTL)) // Ctrl when tapped, gui (command) when held
#define TAP_RSE  OSL(_RAISE) // tap to raise
#define ST_BOLT QK_STENO_BOLT
#define ST_GEM  QK_STENO_GEMINI



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * Tap 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Raise | Hyper| Alt  | GUI  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
 *  Hold
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Hyper| Alt  | GUI  |Lower |      |Shift |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
  KC_BSPC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  CTL_ESC, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_EQL , \
  TAP_RSE, KC_HYPR, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  SFT_ENT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Raise| GUI  |  Alt |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  CTL_ESC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  TAP_RSE, KC_HYPR, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  SFT_ENT, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Bksp |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Del |   :  |   =  |   {  |   }  |      |      |   [  |   ]  |      |      |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0   , KC_BSLS, \
  KC_BSPC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, \
  KC_DEL,  TABU,    TABD,    KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, _______, _______, KC_EQL , \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |  F9  |  F10 |  F11 | F12  | HOME | PGUP | TABU |   7  |   8  |   9  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | DEL  |  F5  |  F6  |  F7  |  F8  | END  | PGDN | TABD |   4  |   5  |   6  |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |   1  |   2  |   3  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   .  |   0  | Entr |   +  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_TILD, KC_F9,   KC_F10,  KC_F11,  KC_F12 , KC_HOME, KC_PGUP, TABU,    KC_P7,   KC_P8,   KC_P9,   KC_PSLS, \
  KC_BSPC, KC_F5,   KC_F6,   KC_F7,   KC_F8  , KC_END,  KC_PGDN, TABD,    KC_P4,   KC_P5,   KC_P6,   KC_PAST, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4  , _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PDOT, KC_P0,   KC_PENT, KC_PLUS  \
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |      |   A  |   O  |   E  |   U  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = KEYMAP( \
 STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC , \
 STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR , \
 XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR , \
 EXT_PLV, XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STN_E,   STN_U,   XXXXXXX, STN_PWR, STN_RE1, STN_RE2  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|   1  |   2  |   3  | TABU | Home | PgUp | TABU |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  | TABD | End  | PgDn | TABD |   *  |   (  |   )  |  _   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|      |Qwerty|Dvorak|Plover|  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RESET,   KC_1,    KC_2,    KC_3,    TABU,    KC_HOME, KC_PGUP, TABU,    KC_8,    KC_9,    KC_0   , KC_PIPE, \
  KC_BSPC, KC_EXLM, KC_AT,   KC_HASH, TABD,    KC_END,  KC_PGDN, TABD,    KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  KC_DEL,  _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, QWERTY,  DVORAK , PLOVER , KC_PLUS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ST_BOLT, ST_GEM   \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
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
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
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
    case TABU:
      if (record->event.pressed) {
             SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_TAB)SS_UP(X_LCTRL)SS_UP(X_LSHIFT));
      }
      return false;
  }
  return true;
}
