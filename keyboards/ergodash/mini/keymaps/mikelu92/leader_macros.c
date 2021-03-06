#include "leader_macros.h"
#include "process_leader.h"

LEADER_EXTERNS();

void leader_func(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_T, KC_S) {
            // set up my default tmux layout
            SEND_STRING(SS_LCTRL("a")SS_DOWN(X_LSHIFT)SS_TAP(X_QUOTE)SS_UP(X_LSHIFT)SS_LCTRL("a")SS_LSFT("5")SS_LCTRL("a")":resize-pane -D 15"SS_TAP(X_ENTER));
        }

        SEQ_TWO_KEYS(KC_U, KC_T) {
            // update vm time
            SEND_STRING("sudo ntpdate pool.ntp.org"SS_TAP(X_ENTER));
        }
    }
}
