/*
 * test_io.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Admin
 */


#include "main.h"
void test_IO(){
	HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin,
				HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin));
}
