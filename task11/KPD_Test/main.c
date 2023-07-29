#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_INterface.h"
#include "LCD_interface.h"
#include <util/delay.h>



int main(void)
{
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voideInit();
	LCD_PrintString("enter password");
	u8 password[4] = {'1','2','3','3'};
	u8 index = 0;

	while(1)
	{
		while(index<4)
		{
			KPD_u8GetKeyState(&Local_u8Key);

			  if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED){
           LCD_voideInit();

	         LCD_voidSendChar(Local_u8Key);
	         if (password[index] == Local_u8Key){
	        	 index++;
		}
	         else {break;}

	   }}

			  if(index >=4){

				  LCD_PrintString("correct");
				  break;
	}
			  else{
				  LCD_PrintString("incorrect");
				  break;
			  }

}
	return 0;}
