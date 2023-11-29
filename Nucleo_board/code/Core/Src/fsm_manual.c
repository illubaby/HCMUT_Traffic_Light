/*
 * fsm_manual.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Minh Hieu
 */
#include "fsm_manual.h"


int red_time_tmp, yellow_time_tmp, green_time_tmp;
int reset_tmp_flag =0;

void turnbackINIT(){
	if (red_time == 1 || yellow_time == 1 ||
			green_time == 1){
		red_time = 5;
		yellow_time = 2;
		green_time = 3;
	}
	setTimer(0, 3); // turn off timer_flag for scan led
	red_time = green_time + yellow_time;
	status = INIT;
}
void resetTimetmp (){
	red_time_tmp = 0;
	yellow_time_tmp= 0;
	green_time_tmp = 0;
}
void checkButton1(){
	if(reset_tmp_flag ==0){
		resetTimetmp();
		reset_tmp_flag =1;
	}						//reset set timer
	if (isButtonPressed(0) == 1){
		if (status == MANUAL_RED) {
			setTimer(50, 3); //timer_flag for blinking led
			status = MANUAL_YELLOW;
		}
		else if (status == MANUAL_YELLOW) status = MANUAL_GREEN;
		else if (status == MANUAL_GREEN) turnbackINIT();
		else status = MANUAL_RED; //auto state -> manual state
		setTimer(1000, 2);// after 5 sec don't press button1 -> turn back to auto mode
	}
}

void checkButton2(){
	if (isButtonPressed(1) == 1){
		if (status == MANUAL_RED){
			if (red_time_tmp < 99) red_time_tmp++;
			if (red_time_tmp == 100)red_time_tmp =1;
		}
		if (status == MANUAL_YELLOW){
			if (yellow_time_tmp < 99) yellow_time_tmp++;
			if (yellow_time_tmp == 100)yellow_time_tmp =1;
		}
		if (status == MANUAL_GREEN){
			if (green_time_tmp < 99) green_time_tmp++;
			if (green_time_tmp == 100)green_time_tmp =1;
		}
	}
}
void checkButton3(){
	if (isButtonPressed(2) == 1){
		if (status == MANUAL_RED){
			red_time = red_time_tmp;
		}
		else if (status == MANUAL_YELLOW){
			yellow_time = yellow_time_tmp;
		}
		else if (status == MANUAL_GREEN){
			green_time = green_time_tmp;
		}
		//when confirm the time, flag =0 to reset timer again
		reset_tmp_flag = 0;
	}
}


void fsm_manual(){
	checkButton1();
	switch (status){
	case MANUAL_RED:
		if (timer_flag [2] == 1) {
			turnbackINIT();
			reset_tmp_flag = 0;
		}
		checkButton2();
		checkButton3();
		break;
	case MANUAL_YELLOW:
		if (timer_flag [2] == 1){
			turnbackINIT();
			reset_tmp_flag = 0;
		}
		checkButton2();
		checkButton3();
		break;
	case MANUAL_GREEN:
		if (timer_flag [2] == 1){
			turnbackINIT();
			reset_tmp_flag = 0;
		}
		checkButton2();
		checkButton3();
		break;
	default: break;
	}




}
