#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_INterface.h"
#include "LCD_interface.h"

int main(void)
{
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voideInit();
	u8 password[4] = "1234";
	u8 password_input[4];

	while(1)
	{

	   KPD_u8GetKeyState(&Local_u8Key);

	   if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED){

	   LCD_voidSendChar(Local_u8Key);
	   }
	   for(int i = 0; i < 3; i++){
	   		password_input[i] = Local_u8Key;}

	   for(int i = 0; i < 3; i++){
	   	   if(password[i] = password_input[i]){
	   		   LCD_PrintString("correct");}

	}
	return 0;
}}

