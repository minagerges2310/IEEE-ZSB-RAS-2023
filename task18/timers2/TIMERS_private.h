/****************************************/
/******* Name : Mina gerges*************/
/********Date : 8/3/2023 **************/
/********SWC  : Timer ****************/
/********Version : 1.0 **************/
/***********************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/*registers define*/
#define TIMERS_u8_TIMSK_REG      *((volatile u8*)0x59)
#define TIMERS_u8_TIFR_REG       *((volatile u8*)0x58)
#define TIMERS_u8_TCCR0_REG      *((volatile u8*)0x53)
#define TIMERS_u8_TCNT0_REG      *((volatile u8*)0x52)
#define TIMERS_u8_OCR0_REG       *((volatile u8*)0x5C)


#define TIMERS_u8_TCCR1A_REG       *((volatile u8*)0x4F)
#define TIMERS_u8_TCCR1B_REG       *((volatile u8*)0x4E)
#define TIMERS_u8_TCCR1H_REG       *((volatile u8*)0x4D)
#define TIMERS_u8_TCCR1L_REG       *((volatile u8*)0x4C)

#define TIMERS_u16_TCNT1_REG       *((volatile u16*) 0x4C)

#define TIMERS_u8_OCR1AH_REG       *((volatile u8*) 0x4B)
#define TIMERS_u8_OCR1AL_REG       *((volatile u8*) 0x4A)

#define TIMERS_u16_OCR1A_REG       *((volatile u16*) 0x4A)

#define TIMERS_u8_ICR1H_REG        *((volatile u8*) 0x47)
#define TIMERS_u8_ICR1L_REG        *((volatile u8*) 0x46)


#define TIMERS_u16_ICR1_REG        *((volatile u16*) 0x46)

#endif
