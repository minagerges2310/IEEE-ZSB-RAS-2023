#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"
#include "GI_interface.h"
#include "LCD_interface.h"
#include "EXTI_interface.h"



int main(void)
{
	u8 Local_u8CompareMatchValue =0;
	DIO_voidInit();

	Servo_Angel(76);
	while(1);
	return 0;
}
