#include "STD_TYPES.h"
#include "BIT_Math.h"
#define F_CPU  1000000UL
#include <util/delay.h>
#include "DIO_interface.h"
#include  "LCD_interface.h"

int main()
{
	DIO_voidInit();

	LCD_voideInit();

	/*code for writing special char in CGRAM*/
	/*step 1: set CGRAM address in AC*/
	LCD_voidSendCmnd(0b1000000);

	LCD_voidSendChar(0b00011111);
	LCD_voidSendChar(0b00001110);
	LCD_voidSendChar(0b00011111);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00001110);
	LCD_voidSendChar(0b00011111);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00000100);

	/*special char 2 => 16*/
	LCD_voidSendCmnd(0b01010000);

	LCD_voidSendChar(0b00000000);
	LCD_voidSendChar(0b00001110);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00001110);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00000100);
	LCD_voidSendChar(0b00000100);

	/*AC => DDRAM*/
	LCD_u8GoToXY(LCD_u8_LINE1,0);

	//LCD_voidSendChar(0);
	//LCD_voidSendChar(2);
	u8 button1,button2;
    int count;


	while(1)
	{
	DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&button1);
	DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,&button2);
	_delay_ms(25);
		if (button1)
			{count++;
			LCD_voidSendChar(0);
			 _delay_ms(500);
			 //LCD_voidClr();

			}
		else if(button2){
			count++;

			LCD_voidSendChar(2);
            _delay_ms(500);
		    //LCD_voidClr();
		}

		if (count == 17){
			LCD_u8GoToXY(LCD_u8_LINE2,0);
		}
		else if (count == 34){
			LCD_voidClr();
			LCD_u8GoToXY(LCD_u8_LINE1,0);
		}


		//LCD_voidSendCmnd(0b00011100);




}
}
