/*
 * dio.c
 *
 * Created: 10/7/2022 7:26:08 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 

/*include dio.h*/
#include "dio.h"


/* DIO_init function is used to set direction of a pin  
DIO_init is a function that takes port number, pin number and the direction needed */

EN_DIO_Error_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction)
{
	/*switch on the port*/
	
	switch(portNumber)
	{
		/*if port number was A 
		check on the direction if input clear pin if out set pin 
		else return not ok */
		case PORT_A:
		if (direction==IN)
		{
			CLR_BIT(DDRA,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was B 
		check on the direction if input clear pin if out set pin 
		else return not ok*/
		case PORT_B:
		if (direction==IN)
		{
			CLR_BIT(DDRB,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was C 
		check on the direction if input clear pin if out set pin 
		else return not ok*/
		case PORT_C:
		if (direction==IN)
		{
			CLR_BIT(DDRC,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was D 
		check on the direction if input clear pin if out set pin 
		else return not ok*/
		case PORT_D:
		if (direction==IN)
		{
			CLR_BIT(DDRD,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRD,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if no port found return not ok*/
		default:
		return DIO_NOT_OK;
		break;
	}
	/*if the function did not return not ok till now then return ok*/
	return DIO_OK;
}


/*DIO_write function is used to write a value on a pin 
DIO_write takes port number , pin number and the value needed to be written*/
EN_DIO_Error_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value)
{
	/*switch on the port*/
	switch(portNumber)
	{
		/*if port number was A 
		check on the value if low clear pin if High set pin 
		else return not ok*/
		case PORT_A:
		if (value==LOW)
		{
			CLR_BIT(PORTA,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was B 
		check on the value if low clear pin if High set pin 
		else return not ok*/
		case PORT_B:
		if (value==LOW)
		{
			CLR_BIT(PORTB,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was C 
		check on the value if low clear pin if High set pin 
		else return not ok*/
		case PORT_C:
		if (value==LOW)
		{
			CLR_BIT(PORTC,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if port number was D 
		check on the value if low clear pin if High set pin 
		else return not ok*/
		case PORT_D:
		if (value==LOW)
		{
			CLR_BIT(PORTD,pinNumber);
		}
		else if (value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
			return DIO_NOT_OK;
		}
		break;
		/*if no port found return not ok*/
		default:
		return DIO_NOT_OK;
		break;
	}
	/*if the function did not return not ok till now then return ok*/
	return DIO_OK;
}


/*DIO_toggle function is used to toggle a pin
DIO_toggle takes port number and pin number*/
EN_DIO_Error_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber)
{
	/*switch on the port*/
	switch(portNumber)
	{
		/*if port number was A toggle pin*/
		case PORT_A:
		TOG_BIT(PORTA,pinNumber);
		break;
		/*if port number was B toggle pin*/
		case PORT_B:
		TOG_BIT(PORTB,pinNumber);
		break;
		/*if port number was C toggle pin*/
		case PORT_C:
		TOG_BIT(PORTC,pinNumber);
		break;
		/*if port number was D toggle pin*/
		case PORT_D:
		TOG_BIT(PORTD,pinNumber);
		break;
		/*if no port found return not ok*/
		default:
		return DIO_NOT_OK;
		break;
	}
	/*if the function did not return not ok till now then return ok*/
	return DIO_OK;
}

/*DIO_read function is used to get pin value
DIO_read takes port number , pin number and pointer to value*/
EN_DIO_Error_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value)
{
	/*switch on the port*/
	switch(portNumber)
	{
		/*if port number was A make pointer on value equal get bit of the pin*/
		case PORT_A:
		*value = GET_BIT(PINA,pinNumber);
		break;
		/*if port number was B make pointer on value equal get bit of the pin*/
		case PORT_B:
		*value = GET_BIT(PINB,pinNumber);
		break;
		/*if port number was C make pointer on value equal get bit of the pin*/
		case PORT_C:
		*value = GET_BIT(PINC,pinNumber);
		break;
		/*if port number was D make pointer on value equal get bit of the pin*/
		case PORT_D:
		*value = GET_BIT(PIND,pinNumber);
		break;
		/*if no port found return not ok*/
		default:
		return DIO_NOT_OK;
		break;
	}
	/*if the function did not return not ok till now then return ok*/
	return DIO_OK;
}