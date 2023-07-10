/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/9/2023 *************/
/********SWC  : KPD ******************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "KPD_INterface.h"
#include "KPD_Private.h"

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

#define KPD_u8_PORT              DIO_u8_PORTA

#define KPD_u8_R1_PIN            DIO_u8_PIN0
#define KPD_u8_R2_PIN            DIO_u8_PIN1
#define KPD_u8_R3_PIN            DIO_u8_PIN2
#define KPD_u8_R4_PIN            DIO_u8_PIN3

#define KPD_u8_c1_PIN            DIO_u8_PIN4
#define KPD_u8_c2_PIN            DIO_u8_PIN5
#define KPD_u8_c3_PIN            DIO_u8_PIN6
#define KPD_u8_c4_PIN            DIO_u8_PIN7


#define KEYPAD_KEYS             {{'7','8','9','/'},\
                                 {'4','5','6','*'},\
                                 {'1','2','3','-'},\
                                 {'C','0','=','+'}}

#endif
