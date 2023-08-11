/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/24/2023 *************/
/********SWC  : Sterpper motor *******/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"

#ifndef    STEPPER_MOTOR_INTERFACE_H

#define   STEPPER_MOTOR_INTERFACE_H

#define  STEPPER_MOTOR_CW      1
#define  STEPPER_MOTOR_CCW     0

u8 STEPPER_MOTOR_move(u8 copy_u8direction,u8 copy_u8angle);

#endif


