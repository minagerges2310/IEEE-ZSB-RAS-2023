/****************************************/
/******* Name : Mina gerges*************/
/********Date : 26/8/2023 **************/
/********SWC  : UART ******************/
/********Version : 1.0 **************/
/***********************************/

#include "STD_TYPES.h"
#include "BIT_Math.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


void UART_voidInit(void)
{
    u16 Local_u16BaudRate = 51;
    u8 Local_u8UCSRCValue = 0b10000000;

    /*baud Rate = 9600*/
    UART_u8_UBRRL_REG = (u8)Local_u16BaudRate;
    UART_u8_UBRRH_REG = (u8)(Local_u16BaudRate >> 8);

    /* normal speed */
    CLR_BIT(UART_u8_UCSRA_REG,1);
    /* disable MCU*/
    CLR_BIT(UART_u8_UCSRA_REG,0);
    /*enable Rx,Tx*/
    SET_BIT(UART_u8_UCSRB_REG,4);
    SET_BIT(UART_u8_UCSRB_REG,3);
    /* select 8 bit data */
    CLR_BIT(UART_u8_UCSRB_REG,2);
    SET_BIT(Local_u8UCSRCValue,2);
    SET_BIT(Local_u8UCSRCValue,1);
    /* select Asynch mode */
    CLR_BIT(Local_u8UCSRCValue,6);
    /* no parity bit*/
    CLR_BIT(Local_u8UCSRCValue,5);
    CLR_BIT(Local_u8UCSRCValue,4);

    /*enable 2 stop bits*/
    SET_BIT(Local_u8UCSRCValue,3);
    /*update UCSRC Reg*/
    UART_u8_UCSRC_REG = Local_u8UCSRCValue;


}

void UART_voidSendByte(u8 Copy_u8DataByte)
{
    /*wait until the transmit refister is empty*/
    while((GET_BIT(UART_u8_UCSRA_REG,5))==0);
    /*send data byte*/
    UART_u8_UDR_REG = Copy_u8DataByte;
}


u8 UART_u8RecieveByte(u8 * Copy_u8RecByte)
{
    u8 Local_u8ErrorState = STD_TYPES_NOK;

    if(Copy_u8RecByte != NULL)
    {
        /*waiy until the data is recieved*/
        while((GET_BIT(UART_u8_UCSRA_REG,7))==0);
        /*read data*/
        *Copy_u8RecByte = UART_u8_UDR_REG;

        Local_u8ErrorState = STD_TYPES_OK;
    }

    return Local_u8ErrorState;
}



u8 UART_SendString(u8 * Copy_u8String)
 {
	 for(u8 i =0 ; Copy_u8String[i] != '\0' ; i++ )
	 {
		 
		 while(GET_BIT(UART_u8_UCSRA_REG,5)==0);
		 
		 UART_u8_UDR_REG=Copy_u8String[i];
	 }
	 return  STD_TYPES_OK;
 }

u8 UART_RecieveString(u8 *Copy_u8RxString)
{
	u8 Local_u8StartChar,Local_u8Endchar ;
	u8 count = 0 ;
	if(Copy_u8RxString!=NULL)
	{
		// wait the data is resived finised
	while(GET_BIT(UART_u8_UCSRA_REG,7)==0);
	Local_u8StartChar=UART_u8_UDR_REG;
	// Wait for UDRE flag
	while(GET_BIT(UART_u8_UCSRA_REG,5)==0);
	UART_u8_UDR_REG = Local_u8StartChar ;
	
	while(1)
	{
		while(GET_BIT(UART_u8_UCSRA_REG,7)==0);
		Local_u8Endchar=UART_u8_UDR_REG;
		// Wait for UDRE flag
		while(GET_BIT(UART_u8_UCSRA_REG,5)==0);
		UART_u8_UDR_REG = Local_u8Endchar ;
		
		if(Local_u8StartChar==Local_u8Endchar)
		{
			Copy_u8RxString[count++]=0;
			break;
		}
		else
		{
			Copy_u8RxString[count++]=Local_u8Endchar;
		}
		count++;
		
	}
	}
	return STD_TYPES_OK ;
}