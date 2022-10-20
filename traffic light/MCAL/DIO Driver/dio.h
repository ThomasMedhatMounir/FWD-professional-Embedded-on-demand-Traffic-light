/*
 * dio.h
 *
 * Created: 10/7/2022 7:25:57 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef DIO_H_
#define DIO_H_

/************************************************************************/
/*                          includes                                    */
#include "../../Utilities/register.h"
#include "../../Utilities/bit_math.h"
/************************************************************************/

/************************************************************************/
/*                        Define                                        */
// port
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction
#define IN 0
#define OUT 1

//value
#define LOW 0
#define HIGH 1
/************************************************************************/

typedef enum EN_DIO_Error_t
{
	DIO_OK,DIO_NOT_OK
}EN_DIO_Error_t;

/************************************************************************/
/*                             prototype                                */
EN_DIO_Error_t DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction);
EN_DIO_Error_t DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value);
EN_DIO_Error_t DIO_toggle(uint8_t portNumber,uint8_t pinNumber);
EN_DIO_Error_t DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value);
/************************************************************************/



#endif /* DIO_H_ */