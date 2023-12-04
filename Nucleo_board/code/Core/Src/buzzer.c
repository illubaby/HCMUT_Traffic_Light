/*
 * buzzer.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Admin
 */

#include "buzzer.h"

int buzzer_counter=5;
void buzzer(){
	if (timer_flag[7]==1){
		buzzer_counter--;
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,buzzer_counter/red_time*100);
	setTimer(100, 7);
	}
}
