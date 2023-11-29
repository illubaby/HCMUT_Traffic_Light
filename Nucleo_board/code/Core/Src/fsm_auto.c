/*
 * fsm_auto.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Minh Hieu
 */


#include "fsm_auto.h"

int status = INIT;
int red_time = 5;
int yellow_time = 2;
int green_time = 3;
int red_time_tmp = 0 ; // temp variable for red time length
int yellow_time_tmp = 0 ;
int green_time_tmp = 0 ;

void fsm_auto(){
	switch (status){
	case INIT:
		red_time_tmp = red_time; // time length = 5s, start at 4 and end at 0
		green_time_tmp = green_time;
		setTimer(100, 0);
		status = AUTO_RED_GREEN;
		break;
	case AUTO_RED_GREEN:
		if (timer_flag[0] == 1){
			red_time_tmp --;
			green_time_tmp --;
			if (green_time_tmp == 0){
				status = AUTO_RED_YELLOW;
				yellow_time_tmp = yellow_time;
			}
			setTimer(100, 0);
		}
		break;
	case AUTO_RED_YELLOW:
		if (timer_flag[0] == 1){
			red_time_tmp --;
			yellow_time_tmp --;
			if (yellow_time_tmp == 0){
				status = AUTO_GREEN_RED;
				red_time_tmp = red_time;
				green_time_tmp = green_time;
			}
			setTimer(100, 0);
		}
		break;
	case AUTO_GREEN_RED:
		if (timer_flag[0] == 1){
			red_time_tmp --;
			green_time_tmp --;
			if (green_time_tmp == 0){
				status = AUTO_YELLOW_RED;
				yellow_time_tmp = yellow_time;
			}
			setTimer(100, 0);
		}
		break;
	case AUTO_YELLOW_RED:
		if (timer_flag[0] == 1){
			red_time_tmp --;
			yellow_time_tmp --;
			if (yellow_time_tmp == 0){
				status = AUTO_RED_GREEN;
				red_time_tmp  = red_time;
				green_time_tmp = green_time;
			}
			setTimer(100, 0);
		}
		break;
	default: break;
	}
}
