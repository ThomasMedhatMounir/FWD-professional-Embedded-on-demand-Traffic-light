/*
 * led.c
 *
 * Created: 10/7/2022 9:55:43 PM
 *  Author: Thomas Medhat Mounir Botros
 */

 /*include led.h*/
#include "led.h"


/*led init function is used to set the pin the led on it output */
EN_LED_Error_t LED_init(uint8_t portNumber,uint8_t pinNumber)
{
	/*call DIO_init function and put the pin as output*/
	DIO_init(portNumber,pinNumber,OUT);
	/*this function will always return ok*/
	return LED_OK;
}

/*led on is used to set the led on*/
EN_LED_Error_t LED_on(uint8_t portNumber,uint8_t pinNumber)
{
	/*call DIO_write and put the pin HIGH*/
	DIO_write(portNumber,pinNumber,HIGH);
	/*this function will always return ok*/
	return LED_OK;
}

/*led on is used to set the led off*/
EN_LED_Error_t LED_off(uint8_t portNumber,uint8_t pinNumber)
{
	/*call DIO_write and put the pin LOW*/
	DIO_write(portNumber,pinNumber,LOW);
	/*this function will always return ok*/
	return LED_OK;
}

/*led toggle is used to toggle led*/
EN_LED_Error_t LED_toggle(uint8_t portNumber,uint8_t pinNumber)
{
	/*call DIO_toggle and toggle the led*/
	DIO_toggle(portNumber,pinNumber);
	/*this function will always return ok*/
	return LED_OK;
}
