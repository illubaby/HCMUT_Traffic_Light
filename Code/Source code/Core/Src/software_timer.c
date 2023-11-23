#include "software_timer.h"

#define NUM_TIMERS 4

int timer_counters[NUM_TIMERS] = {0};
int timer_flags[NUM_TIMERS] = {0};

void setTimer(int timerNumber, int duration) {
    if (timerNumber >= 0 && timerNumber < NUM_TIMERS) {
        timer_counters[timerNumber] = duration;
        timer_flags[timerNumber] = 0;
    }
}

void timerRun() {
    for (int i = 0; i < NUM_TIMERS; i++) {
        if (timer_counters[i] > 0) {
            timer_counters[i]--;
            if (timer_counters[i] == 0) {
                timer_flags[i] = 1;
            }
        }
    }
}
