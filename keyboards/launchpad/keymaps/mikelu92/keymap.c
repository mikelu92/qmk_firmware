// Below layout is based upon /u/That-Canadian's planck layout
#include "launchpad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _L1 0
#define _L2 1
#define _L3 2
#define _L4 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    LOCK = SAFE_RANGE,
    SWPL,
    SWPU,
    SWPR,
    TGGLOS
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define TABL LCTL(LSFT(KC_TAB))
#define TABR LCTL(KC_TAB)
#define CLOSE LGUI(KC_W)
#define SFT_F5 SFT_T(KC_F5) // F5 when tapped, shift when held
#define ALTTAB LGUI(KC_TAB) 
#define SCRSHT LSFT(LGUI(KC_4))
#define LSCRN LCTL(LSFT(KC_LEFT))
#define USCRN LCTL(LSFT(KC_UP))
#define DSCRN LCTL(LSFT(KC_DOWN))
#define RSCRN LCTL(LSFT(KC_RIGHT))
#define L2 MO(_L2)

enum current_os {
    mac = 0,
    win,
};

enum current_os currentOS = mac;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_L1] = LAYOUT( \
    LOCK,    KC_MPRV, \
    KC_VOLD, KC_VOLU, \
    KC_MPLY, KC_MNXT, \
    L2,      _______  \
),
[_L2] = LAYOUT( \
    CLOSE,   SWPL,  \
    TGGLOS,  SWPU,  \
    TG(_L3), SWPR,  \
    _______, _______ \
),
[_L3] = LAYOUT( \
    KC_1,    KC_4,   \
    KC_2,    KC_5,   \
    KC_3,    KC_6,   \
    MO(_L4), _______ \
),
[_L4] = LAYOUT( \
    KC_0,    KC_7,   \
    KC_ENT,  KC_8,   \
    TG(_L3), KC_9,   \
    _______, _______ \
)

};


void matrix_init_user(void) {
    
}

uint16_t custom_lt_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TGGLOS:
            if(record->event.pressed) {
                if (currentOS == win) {
                    currentOS = mac;
                } else {
                    currentOS = win;
                }
            }
            return false;
            break;
        case LOCK:
            if(record->event.pressed) {
                if(currentOS == mac) {
                    SEND_STRING(SS_LCTL(SS_LGUI("q")));
                } else {
                    SEND_STRING(SS_LGUI("l"));
                }
            }
            return false;
            break;
        case SWPL:
            if(record->event.pressed) {
                if(currentOS == mac) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_LEFT))));
                }
            }
            return false;
            break;
        case SWPR:
            if(record->event.pressed) {
                if(currentOS == mac) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
                } else {
                    SEND_STRING(SS_LCTL(SS_LGUI(SS_TAP(X_RIGHT))));
                }
            }
            return false;
            break;
        case SWPU:
            if(record->event.pressed) {
                if(currentOS == mac) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_UP)));
                } else {
                    SEND_STRING(SS_LGUI(SS_TAP(X_TAB)));
                }
            }
            return false;
            break;
	}
	return true;
}
