/*
 * fsm_pedestrian_light.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Admin
 */

#include "fsm_pedestrian_light.h"

void fsm_pedestrian_light(){
	if(isButtonPressed(3)){
		setTimer(1000,1);
	}
	if(timer_flag == 0){
		switch (status){
			case AUTO_RED_GREEN:
				onRedPed();
				break;
			case AUTO_YELLOW_RED:
				onRedPed();
				break;
			case AUTO_GREEN_RED:
				onGreenPed();
				break;
			default:
				break;
		}
	}

}

