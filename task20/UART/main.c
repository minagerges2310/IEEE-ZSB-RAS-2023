#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"
#include "UART_interface.h"

#include <util/delay.h>



int main(void)
{
	u8 Local_u8Data;
	DIO_voidInit();

	UART_voidInit();

	while(1){
		UART_SendString("Choose r or y or g or s");

		UART_u8RecieveByte(&Local_u8Data);
		if(Local_u8Data == 'r')
		{
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else if (Local_u8Data == 'y')
		{
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		}

		else if (Local_u8Data == 'g')
		{
		 DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
		}
		else if (Local_u8Data == 's')
		{
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
		}
	}


	return 0;}
