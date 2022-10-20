/*
 * timer.h
 *
 * Created: 10/9/2022 3:27:46 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/register.h"
#include "../../Utilities/bit_math.h"


#define OVERFLOW_MODE 0
#define CTC_MODE 1
#define FAST_PWM_MODE 2
#define PWM_PHASE_CORRECT_MODE 3


#define NO_CLK 0
#define NO_PRE 1
#define PRE8 2
#define PRE64 3
#define PRE256 4
#define PRE1024 5
#define EX_FALL 6
#define EX_RIS 7

#define OVERFLOW_FLAG 0
#define OUT_COMPARE_FLAG 1

typedef enum EN_Timer_Error_t
{
	TIMER_OK,TIMER_NOT_OK
}EN_Timer_Error_t;
  

EN_Timer_Error_t timer0_init(uint8_t mode);
EN_Timer_Error_t timer0_start(uint8_t prescaler);
EN_Timer_Error_t timer0_intial_val(uint8_t initialval);
EN_Timer_Error_t timer0_stop(void);
EN_Timer_Error_t counter0_start(uint8_t mode);
EN_Timer_Error_t timer0_wait_for_flag(uint8_t flag);
EN_Timer_Error_t timer0_status(uint8_t *val);
EN_Timer_Error_t delay(uint8_t pre,uint8_t OverflowNumber);







#endif /* TIMER_H_ */