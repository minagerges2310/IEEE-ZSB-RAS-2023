/****************************************/
/******* Name : Mina gerges*************/
/********Date : 8/3/2023 **************/
/********SWC  : Timer ****************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"

#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"

/*global pointer to function of timer0 OVF*/
static void(*TIMERS_pfTimer0OVF) (void) = NULL;
static void(*TIMERS_pfTimer0CTC) (void) = NULL;
void TIMERS_voidTimer0Init(void)
{
    /*select mode => normal mode*/
    //CLR_BIT(TIMERS_u8_TCCR0_REG,6);
    //CLR_BIT(TIMERS_u8_TCCR0_REG,3);

    /*select mode => CTC*/
     CLR_BIT(TIMERS_u8_TCCR0_REG,6);
     SET_BIT(TIMERS_u8_TCCR0_REG,3);

     /*set compare match unit register*/
     TIMERS_u8_OCR0_REG = 99;
    /*enable OVF interrupt*/
    SET_BIT(TIMERS_u8_TIMSK_REG,0);
    /*set preload value*/
    //TIMERS_u8_TCNT0_REG = 192;
    /*set prescaler value CLK/8 */
    CLR_BIT(TIMERS_u8_TCCR0_REG,2);
    SET_BIT(TIMERS_u8_TCCR0_REG,1);
    CLR_BIT(TIMERS_u8_TCCR0_REG,0);


}

u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf) (void))
{
    u8 Local_u8ErrorState = STD_TYPES_OK;

    if(Copy_pf != NULL)
    {
        TIMERS_pfTimer0OVF = Copy_pf;


    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}


u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf) (void))
{
	 u8 Local_u8ErrorState = STD_TYPES_OK;

	    if(Copy_pf != NULL)
	    {
	        TIMERS_pfTimer0CTC = Copy_pf;


	    }
	    else
	    {
	        Local_u8ErrorState = STD_TYPES_NOK;
	    }

	    return Local_u8ErrorState;
}


void __vector_11(void)		__attribute__((signal));

void __vector_11(void){
	static u16 Local_u16CounterOVF = 0;
	Local_u16CounterOVF++;
	if(Local_u16CounterOVF == 3907){
		/* Update Preload Value */
		TIMERS_u8_TCNT0_REG = 192;
		/* Clear Overflow Counter */
		Local_u16CounterOVF = 0;
		/* Call App Function */
		if(TIMERS_pfTimer0OVF != NULL){
			TIMERS_pfTimer0OVF();
		}
	}
}

void __vector_10(void)		__attribute__((signal));

void __vector_10(void){
	static u16 Local_u16CounterCTC = 0;
	Local_u16CounterCTC++;
	if(Local_u16CounterCTC == 10000){
		/* Clear Counter */
		Local_u16CounterCTC = 0;

		/* Call CallBack function*/
		if(TIMERS_pfTimer0CTC != NULL){
		    TIMERS_pfTimer0CTC();
			}

	}
}