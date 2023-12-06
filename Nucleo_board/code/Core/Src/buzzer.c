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
int state_buzzer = INIT_BUZZER;
float scale_buzzer=0;
float cycle;
int buzzer_flag = 1;
int frequency;
void get_buzzer_counter(){	// for take the value of the red time
	buzzer_counter = red_time;
}
void toggle_buzzer(){
	if (buzzer_flag == 1){
		buzzer_flag = 0 ;
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,100- cycle);
	}
	else if (buzzer_flag == 0){
		buzzer_flag = 1 ;
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
	}
}
void cal_cycle() {
    //cycle = ((float)buzzer_counter / red_time) * 100.0f;	// the speaker decreases volume every 1s
    cycle = ((float)buzzer_counter / red_time) * 100.0f - scale_buzzer;// the speaker decreases volume every 100ms
    scale_buzzer += (float) (1 / (red_time))*100/10;
    if (scale_buzzer >= (1 / (red_time))*100) {
        scale_buzzer = 0;
    }
}


void buzzer(){
	switch(state_buzzer){
	case INIT_BUZZER:
		setTimer(10, 7);// for the PWM volume
		setTimer(10, 6);// for the buzzer counter
		setTimer(10, 8);// for the sound frequency
		state_buzzer = OFF;
	case ON:
	if (timer_flag[6] == 1){// just for decrease the counter, like the red time
		if (buzzer_counter>=0)
		{HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);}
		buzzer_counter--;
		frequency--;
		setTimer(100, 6);
	}
	if (timer_flag[7] == 1){// for update the PWM louder and louder
		cal_cycle ();
		//__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,100- cycle); // if you want the speaker only louder and louder
		setTimer(10, 7);// because we want to update the speaker every 100ms, so we set 10
	}
	if (timer_flag[8] == 1){// for update the frequency
		toggle_buzzer();
		setTimer(frequency, 8);
	}
	// for reset
	if (buzzer_counter==0){
		get_buzzer_counter();
	}
	if (frequency==0){
		frequency = red_time;
		setTimer(frequency, 8);
	}
	break;
	case OFF:
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		break;
	default: break;
	}
}
