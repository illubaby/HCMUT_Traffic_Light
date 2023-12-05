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
void buzzer(){
    if (timer_flag[7] == 1){
    	HAL_GPIO_TogglePin(TEST_GPIO_Port,TEST_Pin);
        // Update the PWM duty cycle to increase volume
        //__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 10);
    	setTimer(100, 7);
    }
}
