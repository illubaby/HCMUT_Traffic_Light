/*
 * test_io.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Admin
 */


#include "test_io.h"
void test_IO(){
	if (isButtonPressed(1)){
		onRedPed();
	}
	else if (isButtonPressed(2)){
		onGreenPed();
	}
}
