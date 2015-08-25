/*
 * button.h
 *
 *  Created on: Apr 11, 2015
 *      Author: Ran
 */

#ifndef FINAL_HELI_BUTTON_H_
#define FINAL_HELI_BUTTON_H_
#include "driverlib/gpio.h"


#define BUTTON_BACKOFF_DELAY 200 // in ms

enum buttons {UP = 0, DOWN, LEFT, RIGHT, SELECT, RESET};

typedef struct
{
	unsigned char state;
	unsigned long backoff_tick;
	unsigned char pressed;
	unsigned char ulPin;

} button_t;


void buttonsInit(void);
void ButtonIntHandler(void);
unsigned char buttonPressed(int button);


#endif /* FINAL_HELI_BUTTON_H_ */
