/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

// Define the number of timers
#define NUM_TIMERS 4

// Declare the arrays for timers' counters and flags
extern int timer_counters[NUM_TIMERS];
extern int timer_flags[NUM_TIMERS];

// Declare the function for setting timers
void setTimer(int timerNumber, int duration);

// Declare the function for running the timers
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
