/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/24/2023 *************/
/********SWC  : DC motor ******************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#ifndef DC_INTERFACE_H
#define DC_INTERFACE_H

void DC_Motor_Init();
void DC_Motor_Rotate_Clockwise();
void DC_Motor_Rotate_CounterClockwise();
void DC_Motor_Stop();

#endif
