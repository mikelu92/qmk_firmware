#ifndef LEADER_MACROS_H_
#define LEADER_MACROS_H_
char leader_started;
enum leader_funcs {
    LEAD_NONE,
    TMUX,
    VMTIME,
};
uint16_t leader_timer;
void leader_func(void);
#endif /* LEADER_MACROS_H_ */
