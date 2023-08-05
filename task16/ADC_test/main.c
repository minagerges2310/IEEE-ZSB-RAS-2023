#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "GI_interface.h"


#include<util/delay.h>
#define F_CPU 16000000UL

void App_voidADCCallBack(u16 Copy_u16ADCValue);
static u16 App_u16DigitalValue;


int main(void)
{
	LCD_voideInit();
	ADC_voidInit();

	u16 DigitalValue, AnalogValue;
	u32 Res;

	LCD_u8GoToXY(0,0);
	LCD_PrintString("volt");
	LCD_u8GoToXY(1,0);
	LCD_PrintString("res");
	while (1)
	{
		ADC_u8GetDigitalValueSynchNonBlocking(0, &DigitalValue);
		AnalogValue = (DigitalValue * 5000UL) / 1024;
		Res = ((10000*1024UL)/DigitalValue) - 10000;
		LCD_u8GoToXY(0,5);
		LCD_voidSendCmnd(AnalogValue);
		LCD_u8GoToXY(1,5);
		LCD_voidSendCmnd(Res);

	}
	return 0;
}

void App_voidADCCallBack(u16 Copy_u16ADCValue){
	App_u16DigitalValue = Copy_u16ADCValue;
}