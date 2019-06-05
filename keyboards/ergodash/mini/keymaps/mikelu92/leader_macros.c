#include "leader_macros.h"
#include "process_leader.h"

LEADER_EXTERNS();

void leader_func(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_T, KC_S) {
            // set up my default tmux layout
            SEND_STRING(SS_LCTRL(SS_LALT("a"))SS_DOWN(X_LSHIFT)SS_TAP(X_QUOTE)SS_UP(X_LSHIFT)SS_LCTRL(SS_LALT("a"))SS_LSFT("5")SS_LCTRL(SS_LALT("a"))":resize-pane -D 15"SS_TAP(X_ENTER));
        }

        SEQ_ONE_KEY(KC_N) {
            // update vm time
            SEND_STRING("sudo ntpdate pool.ntp.org"SS_TAP(X_ENTER));
        }
    }
}
