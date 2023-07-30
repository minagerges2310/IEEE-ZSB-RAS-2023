/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/24/2023 *************/
/********SWC  : DC motor ******************/
/********Version : 1.0 **************/
/***********************************/

#include "STD_TYPES.h"
#include "BIT_Math.h"
#define F_CPU 1000000L
// #include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "DC_interface.h"
#include "DC_Private.h"
#include "DC_Config.h"

void DC_Motor_Init()
{

    DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN2, DIO_u8_LOW); // Disable the motor initially
}

// Function to rotate the DC motor clockwise
void DC_Motor_Rotate_Clockwise()
{

    DIO_voidSetPinValue(DC_MOTOR_PORT, DC_MOTOR_DIR1, DIO_u8_HIGH); // Set direction pin 1 high
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_LOW);  // Set direction pin 2 low
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH); // Enable the motor
}

// Function to rotate the DC motor counter-clockwise
void DC_Motor_Rotate_CounterClockwise()
{

    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN0, DIO_u8_LOW);  // Set direction pin 1 low
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN1, DIO_u8_HIGH); // Set direction pin 2 high
    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_HIGH); // Enable the motor
}

// Function to stop the DC motor
void DC_Motor_Stop()
{

    DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN2, DIO_u8_LOW); // Disable the motor
}
