/*
 * application.c
 *
 * Created: 10/9/2022 2:36:01 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 

#include "application.h"

/*declare a global variable that is used in ISR and it selects the mode 
it must be volatile so it does not get optimized */
volatile uint8_t mode = 0 ;

/*app_init contains every initialization we need to do once */
void app_init(void)
{
	/*set all normal traffic LEDs output*/
	LED_init(NORMAL_LED_PORT,GREEN);
	LED_init(NORMAL_LED_PORT,YELLOW);
	LED_init(NORMAL_LED_PORT,RED);
	/*set all pedestrian LEDs output*/
	LED_init(PEDESTRIAN_LED_PORT,GREEN);
	LED_init(PEDESTRIAN_LED_PORT,YELLOW);
	LED_init(PEDESTRIAN_LED_PORT,RED);
	/*set button as input*/
	Button_init(BUTTON_PORT,BUTTON_PIN,PULL_UP);
	/*interrupt initialize*/
	/*initialize external interrupt 0 in falling mode
	because the button is connected pull up */
	interrupt_init(EX_INT0,FALLING_MODE);
	/*Timer0 init*/
	/*set timer in overflow mode with zero intial value */
	timer0_init(OVERFLOW_MODE);
	timer0_intial_val(0);
}

/*app_start contains program body and super loop*/
void app_start(void)
{
	/*declare some variables to use*/
	uint8_t state = 0 , check = 0 ,ledState = 0; 
	/*enter super loop */
	while(1)
	{
		/*switch on the global var */
		switch(mode)
		{
			/*if mode == 0 Normal mode */
			case NORMAL_MODE:
			/*put all LEDs OFF*/
			LED_off(NORMAL_LED_PORT,GREEN);
			LED_off(NORMAL_LED_PORT,YELLOW);
			LED_off(NORMAL_LED_PORT,RED);
			LED_off(PEDESTRIAN_LED_PORT,GREEN);
			LED_off(PEDESTRIAN_LED_PORT,YELLOW);
			LED_off(PEDESTRIAN_LED_PORT,RED);
			/*check on the state*/
			/*if zero*/
			if (state == 0 && mode == NORMAL_MODE)
			{
				/*cars green Led is ON and also pedestrian red led is on 
				as in this state cars can move so pedestrian can not
				set ledState = 1 , state = 1 and check = 0 to go to next state*/
				ledState = 1;
				state = 1;
				check = 0;
				LED_on(NORMAL_LED_PORT,GREEN);
				LED_on(PEDESTRIAN_LED_PORT,RED);
				delay(PRE1024,_5_SEC_DELAY);
				LED_off(PEDESTRIAN_LED_PORT,RED);
				LED_off(NORMAL_LED_PORT,GREEN);
				
			}
			/*if 1*/
			/*cars yellow LED and pedestrian yellow LED will be On  */
			if (state == 1 && mode == NORMAL_MODE)
			{
				ledState = 2 ;
				if (check == 0 )
				{
					state = 2 ;
				}
				else
				{
					state = 0;
				}
				for(uint8_t count = 0 ; count < 10 ; count++)
				{
					LED_toggle(NORMAL_LED_PORT,YELLOW);
					LED_toggle(PEDESTRIAN_LED_PORT,YELLOW);
					delay(PRE1024,_500_MSEC_DELAY);
				}
				LED_off(NORMAL_LED_PORT,YELLOW);
				LED_off(PEDESTRIAN_LED_PORT,YELLOW);
			}
			/*if 2*/
			/*cars red Led and pedestrian Green Led will be on */
			if (state == 2 && mode == NORMAL_MODE)
			{
				ledState = 3 ;
				state = 1;
				check = 1;
				LED_on(NORMAL_LED_PORT,RED);
				LED_on(PEDESTRIAN_LED_PORT,GREEN);
				delay(PRE1024,_5_SEC_DELAY);
			}
			break;
			
			/*if pedestrian mode we will enter it when interrupt happens*/
			case PEDESTRIAN_MODE:
			/*if led state is 1 or 2 which means button was pressed either in car green was
			on or cars yellow  was on  */
			if (ledState == 1 || ledState == 2)
			{
				/*put pedestrian red led on and blink both yellow lEDs for 5 seconds*/
				LED_on(PEDESTRIAN_LED_PORT,RED);
				for(uint8_t count = 0 ; count < 10 ; count++)
				{
					LED_toggle(NORMAL_LED_PORT,YELLOW);
					LED_toggle(PEDESTRIAN_LED_PORT,YELLOW);
					delay(PRE1024,_500_MSEC_DELAY);
				}
				/*turn both yellow LEDs and pedestrian red led off*/
				LED_off(NORMAL_LED_PORT,YELLOW);
				LED_off(PEDESTRIAN_LED_PORT,YELLOW);
				LED_off(PEDESTRIAN_LED_PORT,RED);
				/*turn cars red led on and pedestrian green led on*/
				LED_on(NORMAL_LED_PORT,RED);
				LED_on(PEDESTRIAN_LED_PORT,GREEN);
				/*wait for 5 seconds*/
				delay(PRE1024,_5_SEC_DELAY);
				/*turn them off*/
				LED_off(NORMAL_LED_PORT,RED);
				LED_off(PEDESTRIAN_LED_PORT,GREEN);
				/*but state 1 and check 1 to return to the state where both yellow blinks
				and after they are done we return to car green led on and pedestrian red
				led off */
				state = 1;
				check = 1 ;
			}
			else
			{
				// do nothing
			}
			/*set mode to Normal mode to get out of pedestrian mode*/
			mode = NORMAL_MODE;
			break;
			
			/*if neither nor that is an error*/
			default:
			/*Error*/
			break;
		}
	}
}


ISR(EXT_INT0_VECT)
{
	mode = PEDESTRIAN_MODE;
}







