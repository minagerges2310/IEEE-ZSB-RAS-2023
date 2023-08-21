#include "STD_TYPES.h"
#include "BIT_Math.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "Stepper_Motor_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "DC_interface.h"

#include "TIMERS_interface.h"
#include "GI_interface.h"

#include "EXTI_interface.h"
#include  "ADC_interface.h"


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

				LCD_voideInit();

				  LCD_PrintString("1-DC 2-steper");
				  LCD_voidSendCmnd(0xC0);
				  LCD_PrintString("3-servo");
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

						else if (Local_u8Key=='3')
												{
													LCD_voideInit();
											        LCD_PrintString("1-0 2-90 3-180");

													while(1){
														KPD_u8GetKeyState(&Local_u8Key);
														if(Local_u8Key!= KPD_u8_KEY_NOT_PRESSED){
														if(Local_u8Key=='1'){
															Servo_Angel(1300);
														}
														else if (Local_u8Key=='2'){
															Servo_Angel(699);
														}
														else if (Local_u8Key=='3'){
															Servo_Angel(507);
														}
													}
											 }
												}




					 }

	}


}


	return 0;}
