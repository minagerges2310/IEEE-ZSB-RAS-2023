/****************************************/
/******* Name : Mina gerges*************/
/********Date : 26/8/2023 **************/
/********SWC  : UART ******************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);

void UART_voidSendByte(u8 Copy_u8DataByte);

u8 UART_u8RecieveByte(u8 * Copy_u8RecByte);


#endif