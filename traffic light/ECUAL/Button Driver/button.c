/*
 * button.c
 *
 * Created: 10/7/2022 10:22:10 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 

#include "button.h"


/*button init to set button pin input and set connection mode pull up or down*/
EN_Button_Error_t Button_init(uint8_t portNumber , uint8_t pinNumber,uint8_t mode)
{
	/*call DIO_init and put direction input*/
	DIO_init(portNumber,pinNumber,IN);
	/*check if mode is pull up then set the pin high*/
	if (mode == PULL_UP)
	{
		/*call DIO_write and write high on pin to make it pull up*/
		DIO_write(portNumber,pinNumber,HIGH);
	}
	else
	{
		// do nothing
	}
	/*this function will always return ok*/
	return BUTTON_OK;
}


/*button read is used to get the button state*/
EN_Button_Error_t Button_read(uint8_t portNumber , uint8_t pinNumber,uint8_t *value)
{
	/*call DIO_read and pass the value*/
	DIO_read(portNumber,pinNumber,value);
	/*this function will always return ok*/
	return BUTTON_OK;
}