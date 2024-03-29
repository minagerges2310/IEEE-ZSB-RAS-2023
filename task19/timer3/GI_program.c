/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/30/2023 *************/
/********SWC  : GI *****************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "GI_interface.h"
#define SREG   *((volatile u8*)0x5f)

void GI_voidEnable(void){
    SET_BIT(SREG,7);
}


void GI_voidDisable(void)
{
    CLR_BIT(SREG,7);
}
