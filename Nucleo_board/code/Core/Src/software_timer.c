/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Minh Hieu
 */

//used timer: 0 (Hieu), 1 (Tuan Anh), 2,3 (Hieu)
#include "software_timer.h"


int timer_counter[10] ={ 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0};
int timer_flag [10] ={ 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0};

void setTimer(int duration, int index){
	timer_counter[index] = duration;
	timer_flag [index] = 0;
}

void timerRun(){
	for (int i =0 ;i < 10; i++){
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] == 0){
				timer_flag [i] = 1;
			}
		}
	}
}
