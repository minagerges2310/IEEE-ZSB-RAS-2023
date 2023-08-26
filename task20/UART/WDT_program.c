/****************************************/
/******* Name : Mina gerges*************/
/********Date : 8/20/2023 *************/
/********SWC  : WDT ******************/
/********Version : 1.0 **************/
/***********************************/

#include "STD_TYPES.h"
#include  "BIT_Math.h"

#include "WDT_interface.h"

#define WDTCR   *((volatile u8*)0x41)

void WDT_voidEnable(void)
{
	/* enable WDT = 2.1 sec*/
	WDTCR = 0b00001111;
}

void WDT_voidDisable(void)
{
	WDTCR |= ((1<<4) | (1<<3));

	WDTCR = 0x00;
}


