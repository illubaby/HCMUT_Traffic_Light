/*
 * test_io.c
 *
 *  Created on: Nov 21, 2023
 *      Author: Admin
 */


#include "main.h"
void test_IO(){
	HAL_GPIO_WritePin(TL2A_GPIO_Port, TL2A_Pin,
				HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin));
	HAL_GPIO_WritePin(TL2B_GPIO_Port, TL2B_Pin,
				HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin));
}
