/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/30/2023 *************/
/********SWC  : EXTI *****************/
/********Version : 1.0 **************/
/***********************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_INT0                 0
#define EXTI_u8_INT1                 1
#define EXTI_u8_INT2                 2

/* Macros for edge source */
#define EXTI_u8_RAISING_EDGE        0
#define EXTI_u8_FALLING_EDGE        1
#define EXTI_u8_ANY_LOGICAL_CHANGE  2
#define EXTI_u8_LOW_LEVEL           3

u8 EXTI_EXTIEnable(u8 Copy_u8EXTIIndex,u8 Copy_u8EdgeIndex);

u8 EXTI_u8EXTIDisable(u8 Copy_u8EXTIIndex);

u8 EXTI_u8EXTISetCallBack(u8 Copy_uEXTIIndex, void(*Copy_pf) (void));

#endif