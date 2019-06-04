#include "leader_macros.h"
#include "process_leader.h"

LEADER_EXTERNS();

void leader_func(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_S, KC_S) {
          SEND_STRING("ssh seu1.s2prod"SS_TAP(X_ENTER));
        }
        SEQ_ONE_KEY(KC_C) {
          SEND_STRING("ssh c7"SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_S, KC_C) {
          SEND_STRING("ssh c7"SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_T, KC_S) {
            // set up my default tmux layout
            SEND_STRING(SS_LCTRL(SS_LALT("a"))SS_DOWN(X_LSHIFT)SS_TAP(X_QUOTE)SS_UP(X_LSHIFT)SS_LCTRL(SS_LALT("a"))SS_LSFT("5")SS_LCTRL(SS_LALT("a"))":resize-pane -D 15"SS_TAP(X_ENTER));
        }

        // Quiver macros
        SEQ_TWO_KEYS(KC_Q, KC_N) {
            SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        }
        SEQ_TWO_KEYS(KC_Q, KC_T) {
            // switch cell to text
            SEND_STRING(SS_LGUI(SS_LALT("1")));
        }
        SEQ_TWO_KEYS(KC_Q, KC_C) {
            // switch cell to code
            SEND_STRING(SS_LGUI(SS_LALT("2")));
        }
        SEQ_TWO_KEYS(KC_Q, KC_M) {
            // switch cell to markdown
            SEND_STRING(SS_LGUI(SS_LALT("3")));
        }
        SEQ_TWO_KEYS(KC_Q, KC_S) {
            // split cell
            SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LGUI)SS_TAP(X_ENTER)SS_UP(X_LGUI)SS_UP(X_LALT));
        }
        SEQ_ONE_KEY(KC_N) {
            // update vm time
            SEND_STRING("sudo ntpdate pool.ntp.org"SS_TAP(X_ENTER));
        }
        SEQ_ONE_KEY(KC_F) {
            SEND_STRING(SS_TAP(X_ESCAPE)"ofunc () {\n}"SS_TAP(X_ESCAPE)"kea"SS_TAP(X_SPACE));
        }
    }
}
