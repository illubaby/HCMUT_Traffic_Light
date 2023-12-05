/*
 * buzzer.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Admin
 */

#include "buzzer.h"
#include "global.h"
#include "main.h"
extern TIM_HandleTypeDef htim3;  // External declaration
int buzzer_counter=5;

float cycle;
void get_buzzer_counter(){
	buzzer_counter = red_time;
}
void cal_cycle (){
	cycle = ((float)buzzer_counter / red_time) * 100.0f;
}
void buzzer(){
	if (timer_flag[6] == 1){// just for decrease the counter, like the red time
		if (buzzer_counter>=0)
		{HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);}
		buzzer_counter--;
		setTimer(100, 6);
	}
	if (timer_flag[7] == 1){
		cal_cycle ();
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, cycle);
		setTimer(10, 7);
	}
}
