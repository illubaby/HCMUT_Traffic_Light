/*
 * fsm_pedestrian_light.c
 *
 *  Created on: Nov 24, 2023
 *      Author: Admin
 */

#include "fsm_pedestrian_light.h"

void fsm_pedestrian_light(){
	if(isButtonPressed(4)){
		setTimer(1000,4);
	}
}
