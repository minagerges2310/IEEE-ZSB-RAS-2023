/****************************************/
/******* Name : Mina gerges*************/
/********Date : 5/5/2023 **************/
/********SWC  : LCD ******************/
/********Version : 1.0 **************/
/***********************************/

#ifdef LCD_CONFIG_H
#define LCD_CONFIG_H
/* Options : 1- DIO_u8_PORTA
             2- DIO_u8_PORTB
             3- DIO_u8_PORTC
             4- DIO_u8_PORTD */
#define LCD_u8_CONTROL_PORT     DIO_u8_PORTB
#define LCD_u8_RS_PIN           DIO_u8_PIN3
#define LCD_u8_RW_PIN           DIO_u8_PIN1
#define LCD_u8_E_PIN            DIO_u8_PIN2

#define LCD_u8_DATA_PORT        DIO_u8_PORTD
/* options : 1- LCD_u8_MODE_8_BIT
             2- LCD_u8_MODE_4_BIT*/
#define LCD_u8_MODE             LCD_u8_4_BIT_MODE


#endif