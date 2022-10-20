/*
 * led.h
 *
 * Created: 10/7/2022 9:56:08 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer0 Driver/timer.h"


typedef enum EN_LED_Error_t
{
	LED_OK,LED_NOT_OK
}EN_LED_Error_t;


EN_LED_Error_t LED_init(uint8_t portNumber,uint8_t pinNumber);
EN_LED_Error_t LED_on(uint8_t portNumber,uint8_t pinNumber);
EN_LED_Error_t LED_off(uint8_t portNumber,uint8_t pinNumber);
EN_LED_Error_t LED_toggle(uint8_t portNumber,uint8_t pinNumber);




#endif /* LED_H_ */