/****************************************/
/******* Name : Mina gerges*************/
/********Date : 7/9/2023 *************/
/********SWC  : KPD ******************/
/********Version : 1.0 **************/
/***********************************/
#include "STD_TYPES.h"
#include "BIT_Math.h"
#define F_CPU  1000000L
#include <util/delay.h>


/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "KPD_INterface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

u8 KPD_Au8Keys[4][4] = KEYPAD_KEYS;

u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
u8 KPD_Au8ColsPins[4]={KPD_u8_c1_PIN,KPD_u8_c2_PIN,KPD_u8_c3_PIN,KPD_u8_c4_PIN};


u8 KPD_u8GetKeyState(u8 *Copy_pu8ReturnedKey)
{

    u8 Local_u8ErrorState = STD_TYPES_OK;
    u8 Local_u8RowsCounter,Local_u8ColsCounter,Local_u8PinValue,Local_u8Flag =0;
if(Copy_pu8ReturnedKey != NULL)
{
    *Copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
     /*activate each row*/
     for(Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3; Local_u8RowsCounter++)
     {
        DIO_voidSetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_LOW);
        /*check which input pin has 0*/
        for(Local_u8ColsCounter = 0; Local_u8ColsCounter <= 3; Local_u8ColsCounter++)
        {
            DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);
            if(Local_u8PinValue == DIO_u8_LOW)
            {
                //debouncing//
                _delay_ms(20);
                //chech if the pin is still low//
                 DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);


                while (Local_u8PinValue == DIO_u8_LOW)
                {
                  DIO_u8GetPinValue(KPD_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter],&Local_u8PinValue);

                }
                *Copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
                Local_u8Flag =1;
                break;
            }
        }
        DIO_voidSetPinValue(KPD_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],DIO_u8_HIGH);
        if(Local_u8Flag == 1)
        {
            break;
        }

     }

}
else{
    Local_u8ErrorState = STD_TYPES_NOK;
}

   return Local_u8ErrorState;
}
