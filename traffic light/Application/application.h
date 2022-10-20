/*
 * application.h
 *
 * Created: 10/9/2022 2:35:48 PM
 *  Author: Thomas Medhat Mounir Botros
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_



#define F_CPU 1000000U //1MHz
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"

#define NORMAL_MODE 0
#define PEDESTRIAN_MODE 1

#define NORMAL_LED_PORT PORT_A
#define PEDESTRIAN_LED_PORT PORT_B
#define GREEN 0
#define YELLOW 1
#define RED 2

#define BUTTON_PORT PORT_D
#define BUTTON_PIN 2

#define PRESSED 0
#define NOT_PRESSED 1

#define OFF 0
#define ON 1


#define _5_SEC_DELAY 19
#define _500_MSEC_DELAY 2

#define APPLICATION 0
#define DIO 1
#define LED 2
#define BUTTON 3
#define TIMER 4
#define INTERRUPT 5
#define CASE APPLICATION


void app_init(void);
void app_start(void);




#endif /* APPLICATION_H_ */