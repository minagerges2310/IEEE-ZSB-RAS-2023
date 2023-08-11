/****************************************/
/******* Name : Mina gerges*************/
/********Date : 8/3/2023 **************/
/********SWC  : Timer ****************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);

u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf) (void));

u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf) (void));

#endif
