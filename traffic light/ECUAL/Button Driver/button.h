/*
 * button.h
 *
 * Created: 10/7/2022 10:21:58 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Ext interrupt Driver/interrupt.h"


#define PULL_UP 0
#define PULL_DOWN 1 

typedef enum EN_Button_Error_t
{
	BUTTON_OK,BUTTON_NOT_OK
}EN_Button_Error_t;

EN_Button_Error_t Button_init(uint8_t portNumber , uint8_t pinNumber,uint8_t mode);
EN_Button_Error_t Button_read(uint8_t portNumber , uint8_t pinNumber,uint8_t *value);




#endif /* BUTTON_H_ */