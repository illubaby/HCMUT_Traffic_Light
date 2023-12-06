/*
 * scanLed.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Minh Hieu
 */

#include "scanLed.h"

int enable_change = 0;
//lenh bat tat den cho nhanh
void turnoffAll(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, RESET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, RESET);
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, RESET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, RESET);
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, RESET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, RESET);
}
void onRed_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, SET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, RESET);
}
void onYellow_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, SET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, SET);
}
void onGreen_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, RESET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, SET);
}
void onRed_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, SET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, RESET);
}
void onYellow_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, SET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, SET);
}
void onGreen_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, RESET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, SET);
}
void offPed(){
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, RESET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, RESET);
}

void onGreenPed(){
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, RESET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, SET);
}
void onRedPed(){
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, SET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, RESET);
}
void onRed_Toggle(){
	if (enable_change == 0){
		onRed_1();
		onRed_2();
		enable_change = 1;
	}
	else if (enable_change == 1){
		turnoffAll();
		enable_change = 0;
	}
}
void onGreen_Toggle(){
	if (enable_change == 0){
		onGreen_1();
		onGreen_2();
		enable_change = 1;
	}
	else if (enable_change == 1){
		turnoffAll();
		enable_change = 0;
	}
}
void onYellow_Toggle(){
	if (enable_change == 0){
		onYellow_1();
		onYellow_2();
		enable_change = 1;
	}
	else if (enable_change == 1){
		turnoffAll();
		enable_change = 0;
	}
}
void scanLed(){
	switch (status){
	case AUTO_RED_GREEN:
		onRed_1();
		onGreen_2();
		if(timer_flag[4] == 0){
			onGreenPed();
			state_buzzer =OFF;//buzzer
		}else if(timer_flag[4] == 1){
			offPed();
			state_buzzer =OFF;//buzzer
		}
		break;
	case AUTO_RED_YELLOW:
		onRed_1();
		onYellow_2();
		if(timer_flag[4] == 0){
			onGreenPed();
			state_buzzer =OFF;//buzzer
		}else if(timer_flag[4] == 1){
			offPed();
			state_buzzer =OFF;//buzzer
		}
		break;
	case AUTO_GREEN_RED:
		onGreen_1();
		onRed_2();
		if(timer_flag[4] == 0){
			state_buzzer =ON;//buzzer
			onRedPed();
		}else if(timer_flag[4] == 1){
			state_buzzer =OFF;//buzzer
			offPed();
		}
		break;
	case AUTO_YELLOW_RED:
		onYellow_1();
		onRed_2();
		if(timer_flag[4] == 0){
			state_buzzer =ON;//buzzer
			onRedPed();
		}else if(timer_flag[4] == 1){
			state_buzzer =OFF;//buzzer
			offPed();
		}
		break;
	case MANUAL_RED:
		offPed();
		state_buzzer =OFF;//buzzer
		if (timer_flag[3] == 1){
			onRed_Toggle();
			setTimer(50,3);
		}
		break;
	case MANUAL_YELLOW:
		offPed();
		state_buzzer =OFF;//buzzer
		if (timer_flag[3] == 1){
			onYellow_Toggle();
			setTimer(50,3);
		}
		break;
	case MANUAL_GREEN:
		offPed();
		state_buzzer =OFF; //buzzer
		if (timer_flag[3] == 1){
			onGreen_Toggle();
			setTimer(50,3);
		}
		break;
	default: break;
	}
}
