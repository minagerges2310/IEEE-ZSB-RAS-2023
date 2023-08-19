/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/30/2023 *************/
/********SWC  : EXTI *****************/
/********Version : 1.0 **************/
/***********************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*define for EXTI regstir*/
#define EXTI_U8_MCUCR       *((volatile u8 *)0x55)
#define EXTI_U8_MCUCSR      *((volatile u8 *)0x54)
#define EXTI_U8_GICR        *((volatile u8 *)0x5B)   
#define EXTI_U8_GIFR        *((volatile u8 *)0x5A)


#endif