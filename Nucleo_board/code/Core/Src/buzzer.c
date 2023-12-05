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
int buzzer_counter;
int state_buzzer = 1	;
int scale_buzzer=0;
float cycle;
void get_buzzer_counter(){	// for take the value of the red time
	buzzer_counter = red_time;
}
void cal_cycle (){
	//cycle = ((float)buzzer_counter / red_time) * 100.0f;	// the speaker decreases volume every 1s
	cycle = ((float)buzzer_counter / red_time) * 100.0f-scale_buzzer; // the speaker decreases volume every 100ms
	scale_buzzer++;
	if (scale_buzzer>=10){
		scale_buzzer=0;
	}
}
void buzzer(){
	switch(state_buzzer){
	case ON:
	if (timer_flag[6] == 1){// just for decrease the counter, like the red time
		if (buzzer_counter>=0)
		{HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);}
		buzzer_counter--;
		setTimer(100, 6);
	}
	if (timer_flag[7] == 1){// for update the PWM more detail
		cal_cycle ();
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, cycle);
		setTimer(10, 7);// because we want to update the speaker every 100ms, so we set 10
	}
	// for reset the buzzer_counter
	if (buzzer_counter==0){
		get_buzzer_counter();
	}
	break;
	case OFF:
		break;
	default: break;
	}
}
