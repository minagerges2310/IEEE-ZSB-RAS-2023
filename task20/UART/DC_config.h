/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/24/2023 *************/
/********SWC  : DC motor ******************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "DC_interface.h"
#include "DC_Private.h"

#ifndef DC_CONFIG_H
#define DC_CONFIG_H

#define DC_MOTOR_PORT           DIO_u8_PORTC

#define DC_MOTOR_DIR1           DIO_u8_PIN0 // Direction pin 1 for DC motor
#define DC_MOTOR_DIR2           DIO_u8_PIN1 // Direction pin 2 for DC motor
#define DC_MOTOR_EN             DIO_u8_PIN2 // Enable pin for DC motor

#endif
