/*
 * interrupt.h
 *
 * Created: 10/10/2022 12:11:47 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/register.h"
#include "../../Utilities/bit_math.h"

/************************************************************************/
/*                      interrupt pins                                  */
/*
PD2 ---> INT0
PD3 ---> INT1
PB2 ---> INT2

no need for input init 
*/
/************************************************************************/

#define EX_INT0 0
#define EX_INT1 1
#define EX_INT2 2

#define DISABLE 0
#define ENABLE 1

#define LOW_MODE 0
#define ANY_CHANGE_MODE 1
#define FALLING_MODE 2
#define RISING_MODE 3


typedef enum EN_INT_Error_t
{
	INT_OK,INT_NOT_OK
}EN_INT_Error_t;


#define EXT_INT0_VECT __vector_1
#define EXT_INT1_VECT __vector_2
#define EXT_INT2_VECT __vector_3


#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


EN_INT_Error_t global_interrupt_state(uint8_t state);
EN_INT_Error_t interrupt_init(uint8_t id,uint8_t mode);
EN_INT_Error_t interrupt_wait_for_flag(uint8_t id);
EN_INT_Error_t interrupt_disable(uint8_t id);



#endif /* INTERRUPT_H_ */