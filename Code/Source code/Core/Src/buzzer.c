/*
 * buzzer.c
 *
 *  Created on: Nov 23, 2023
 *      Author: ADMIN
 */
#include "software_timer.h"
#include "main.h"
int buzzer_counter;
void buzzer(){
	// the frequence is 1khz
	// input is the current counter value

	if (timer_flags[4] == 1){
		setTimer(4,100);
		HAL_GPIO_TogglePin(TEST_GPIO_Port, TEST_Pin);
		buzzer_counter--;
		if (buzzer_counter<0){// reset the counter of buzzer
			buzzer_counter = red_time/100;
		}
	}
	__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,100-(100/(red_time/100))*buzzer_counter);
}
