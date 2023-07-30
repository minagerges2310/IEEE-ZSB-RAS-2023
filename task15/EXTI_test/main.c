#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "KPD_INterface.h"
#include "LCD_interface.h"
#include "GI_interface.h"
#include <util/delay.h>
#define SREG   *((volatile u8*)0x5f)


void login(void);

int main (void)
{
	//DIO_voidInit();
	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_INPUT);

	GI_voidEnable();
	EXTI_EXTIEnable(EXTI_u8_INT2,EXTI_u8_RAISING_EDGE);
	SET_BIT(SREG,7);
	EXTI_u8EXTISetCallBack(EXTI_u8_INT2,&login);

	while(1);
	return 0;

}




 void login(void)
{
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voideInit();
	LCD_PrintString("enter password");
	u8 password[4] = {'1','2','3','3'};
	u8 index = 0;

	while(1)
	{
		LCD_voidSendCmnd(0xC0);
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
				LCD_voideInit();

				  LCD_PrintString("1-DC 2-steper");
				  LCD_voidSendCmnd(0xC0);
				  LCD_PrintString("3-exit");
				  while(1){
					KPD_u8GetKeyState(&Local_u8Key);
					 if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED){
						if(Local_u8Key=='1'){
							LCD_voideInit();
							LCD_PrintString("1-ccw");
							LCD_voidSendCmnd(0xC0);
							LCD_PrintString("1-cw");
							while(1){
								KPD_u8GetKeyState(&Local_u8Key);
								if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED){
									if(Local_u8Key=='1'){
										DC_Motor_Rotate_Clockwise();
										break;
									}
									else if (Local_u8Key=='2')
									{
										DC_Motor_Rotate_CounterClockwise();
										break;
									}

								}
							}
						}
						else if (Local_u8Key=='2')
						{
							LCD_voideInit();
							LCD_PrintString("1-cw");
							LCD_voidSendCmnd(0xC0);
							LCD_PrintString("1-ccw");
							while(1){
								KPD_u8GetKeyState(&Local_u8Key);
								if(Local_u8Key!= KPD_u8_KEY_NOT_PRESSED){
									if(Local_u8Key =='1'){
										LCD_voideInit();
							            LCD_PrintString("1-90 2-180 3-270");
							            LCD_voidSendCmnd(0xC0);
							            LCD_PrintString("4-360");
										while(1){
											KPD_u8GetKeyState(&Local_u8Key);
											if(Local_u8Key!= KPD_u8_KEY_NOT_PRESSED){
												if(Local_u8Key=='1'){
												DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
												_delay_ms(200);
												DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
												break;
												}
												else if (Local_u8Key=='2')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													break;
												}
												else if (Local_u8Key=='3')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													break;
												}
												else if (Local_u8Key=='4')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													_delay_ms(200);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_LOW);
													break;
												}




											}

										break;}
									}
									else if(Local_u8Key=='2'){
										LCD_voideInit();
							            LCD_PrintString("1-90 2-180 3-270");
							            LCD_voidSendCmnd(0xC0);
							            LCD_PrintString("4-360");
										while(1){
											KPD_u8GetKeyState(&Local_u8Key);
											if(Local_u8Key!= KPD_u8_KEY_NOT_PRESSED){
												if(Local_u8Key=='1'){
												DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
												_delay_ms(200);
												DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
												break;
												}
												else if (Local_u8Key=='2')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													break;
												}
												else if (Local_u8Key=='3')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_LOW);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
													break;
												}
												else if (Local_u8Key=='4')
												{
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
													_delay_ms(200);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_LOW);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
													_delay_ms(2000);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN6,DIO_u8_HIGH);
													DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
													break;
												}




											}

										break;}

									}
								}
							}

						}


					 }

	}
			  }else{
				LCD_voideInit();
				  LCD_PrintString("incorrect");
				  break;
			  }

}
}


