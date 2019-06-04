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

#define _L2 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    L2_LOCK = SAFE_RANGE
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define LOCK LCTL(LGUI(KC_Q))
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
#define SWPL LCTL(KC_LEFT)
#define SWPU LCTL(KC_UP)
#define SWPR LCTL(KC_RIGHT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_L1] = LAYOUT( \
    LOCK, SWPL, \
    TABL, SWPU, \
    TABR, SWPR, \
    L2,   KC_8  \
),

/* Function
 */
[_L2] = LAYOUT( \
    CLOSE,   LSCRN,  \
    DSCRN,   USCRN,  \
    KC_VOLU, RSCRN,  \
    _______, _______ \
)

};


void matrix_init_user(void) {
    
}

uint16_t custom_lt_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if(keycode == L2_LOCK) {
		if(record->event.pressed) {
			custom_lt_timer = timer_read();
			layer_on(15);
		}else{
			layer_off(15);
			if (timer_elapsed(custom_lt_timer)<200) {
				register_code(KC_LGUI);
				register_code(KC_LCTL);
				register_code(KC_Q);
				unregister_code(KC_Q);
				unregister_code(KC_LCTL);
				unregister_code(KC_LGUI);
			}
		}
	}
	return true;
}
