#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"
#include "LCD_interface.h"
#include "EXTI_interface.h"


void App_voidTogLed(void);
int main(void)
{
	LCD_voideInit();
	DIO_voidInit();
	GI_voidEnable();
	DIO_voidSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_OUTPUT);
	DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8PortHigh);
	TIMERS_u8Timer0CTCSetCallBack(&App_voidTogLed);
	TIMERS_voidTimer0Init();
	LCD_PrintString("counter");
	while(1);
	return 0;
}

void App_voidTogLed(void)
{
	static u8 flag=0, counter=0;
	LCD_u8GoToXY(0,9);
	counter++;
	LCD_voidSendCmnd(counter);

	if (flag==0)
	{
		DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8PortHigh);
		flag=1;
	}
	else
	{
		DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8PortLow);
		flag=0;
	}
}
