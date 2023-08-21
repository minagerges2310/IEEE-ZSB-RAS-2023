/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/24/2023 *************/
/********SWC  : Sterpper motor *******/
/********Version : 1.0 **************/
/***********************************/

/*Lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 1000000UL
#include<util/delay.h>
/* MCAL*/
#include "DIO_interface.h"
/*HAL*/
#include "Stepper_Motor_interface.h"
#include "Stepper_Moter_config.h"
#include "Stepper_Motor_private.h"


//u8 stepper_motor_init ()
//{
//	DIO_voidSetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_OUTPUT);
//	DIO_voidSetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_OUTPUT);
//	DIO_voidSetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_OUTPUT);
//	DIO_voidSetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_OUTPUT);
//	DIO_voidSetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
//	DIO_voidSetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
//	DIO_voidSetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
//	DIO_voidSetPinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);
//
//}

u8 STEPPER_MOTOR_move(u8 copy_u8direction,u8 copy_u8angle)
{
    u8 LocalErrorState = STD_TYPES_OK;
    u8 Local_u8Steps = (copy_u8angle *DEGREE_PER_STEP)/360;
    if((copy_u8angle>=0 && copy_u8angle<=360) && (copy_u8direction==STEPPER_MOTOR_CW || copy_u8direction==STEPPER_MOTOR_CCW ))
    {
         if(copy_u8direction==STEPPER_MOTOR_CW)
            {
                for(int i=0; i>=Local_u8Steps; i++)
                {
                    
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);
                    _delay_ms(10);
                }
            }
                else if (copy_u8direction==STEPPER_MOTOR_CCW)
                {
                    for(int i=0; i>=Local_u8Steps; i++){
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_voidSetPinValue (STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    }
                }
                
    }
    

else{u8 LocalErrorState = STD_TYPES_NOK;}
return LocalErrorState;
}
