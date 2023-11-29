/*
 * scanLed.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Minh Hieu
 */

#include "scanLed.h"


//lenh bat tat den cho nhanh
void turnoffAll(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, SET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, SET);
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, SET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, SET);
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, SET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, SET);
}
void onRed_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, RESET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, SET);
}
void onYellow_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, RESET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, RESET);
}
void onGreen_1(){
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, SET);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, RESET);
}
void onRed_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, RESET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, SET);
}
void onYellow_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, RESET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, RESET);
}
void onGreen_2(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, SET);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, RESET);
}

void onGreenPed(){
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, SET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, RESET);
}
void onRedPed(){
	HAL_GPIO_WritePin(PLA_GPIO_Port, PLA_Pin, RESET);
	HAL_GPIO_WritePin(PLB_GPIO_Port, PLB_Pin, SET);
}
void onRed_Toggle(){
	HAL_GPIO_TogglePin(TL1A_GPIO_Port, TL1A_Pin);
	HAL_GPIO_WritePin(TL1B_GPIO_Port, TL1B_Pin, SET);
	HAL_GPIO_TogglePin(TL2A_GPIO_Port, TL2A_Pin);
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin, SET);
}
void onGreen_Toggle(){
	HAL_GPIO_TogglePin(TL1B_GPIO_Port, TL1B_Pin);
	HAL_GPIO_WritePin(TL1A_GPIO_Port, TL1A_Pin, SET);
	HAL_GPIO_TogglePin(TL2B_GPIO_Port, TL2B_Pin);
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin, SET);
}
void onYellow_Toggle(){
	HAL_GPIO_TogglePin(TL1A_GPIO_Port, TL1A_Pin);
	HAL_GPIO_TogglePin(TL1B_GPIO_Port, TL1B_Pin);
	HAL_GPIO_TogglePin(TL2A_GPIO_Port, TL2A_Pin);
	HAL_GPIO_TogglePin(TL2B_GPIO_Port, TL2B_Pin);
}
void scanLed(){
	switch (status){
	case AUTO_RED_GREEN:
		onRed_1();
		onGreen_2();
		break;
	case AUTO_RED_YELLOW:
		onRed_1();
		onYellow_2();
		break;
	case AUTO_GREEN_RED:
		onGreen_1();
		onRed_2();
		break;
	case AUTO_YELLOW_RED:
		onYellow_1();
		onRed_2();
		break;
	case MANUAL_RED:
		if (timer_flag[3] == 1){
			onRed_Toggle();
			setTimer(50,3);
		}
		break;
	case MANUAL_YELLOW:
		if (timer_flag[3] == 1){
			onYellow_Toggle();
			setTimer(50,3);
		}
		break;
	case MANUAL_GREEN:
		if (timer_flag[3] == 1){
			onGreen_Toggle();
			setTimer(50,3);
		}
		break;
	default: break;
	}
}
