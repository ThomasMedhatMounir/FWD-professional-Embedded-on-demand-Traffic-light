/*
 * traffic light.c
 *
 * Created: 10/12/2022 10:25:02 AM
 * Author : Thomas Medhat Mounir Botros
 */ 


/*include application.h*/
#include "Application/application.h"


int main(void)
{
	#if (CASE == APPLICATION)
	/*call app_init which contains all initializations */
	app_init();
	/*call app_start which contains function body and while 1*/
	app_start();
	
	#elif (CASE == DIO)
	DIO_init(PORT_A,0,OUT);
	DIO_init(PORT_A,1,IN);
	DIO_write(PORT_A,0,HIGH);
	DIO_write(PORT_A,1,HIGH); // PULL UP 
	uint8_t val = 0;
	DIO_read(PORT_A,1,&val);
	DIO_toggle(PORT_A,0);
	
	#elif (CASE == LED)
	LED_init(PORT_A,0);
	LED_on(PORT_A,0);
	LED_off(PORT_A,0);
	LED_toggle(PORT_A,0);
	
	#elif (CASE == BUTTON)
	uint8_t val = 0;
	Button_init(PORT_A,1,PULL_UP);
	Button_read(PORT_A,1,&val);
	Button_init(PORT_A,1,PULL_DOWN);
	Button_read(PORT_A,1,&val);
	
	#elif (CASE == TIMER)
	uint8_t val = 0;
	timer0_init(OVERFLOW_MODE);
	timer0_intial_val(2);
	timer0_status(&val);
	timer0_start(PRE1024);
	timer0_wait_for_flag(OVERFLOW_FLAG);
	timer0_stop();
	counter0_start(EX_FALL);
	delay(PRE1024,_500_MSEC_DELAY);
	
	
	#elif (CASE == INTERRUPT)
	global_interrupt_state(ENABLE);
	interrupt_init(EX_INT0,FALLING_MODE);
	interrupt_wait_for_flag(EX_INT0);
	interrupt_disable(EX_INT0);
	#endif
	
}

