/*
 * main.c
 */

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/pwm.h"
#include "inc/hw_ints.h"
#include "inc/lm3s1968.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "utils/uartstdio.h"
#include "driverlib/debug.h"
#include "drivers/rit128x96x4.h"

#include "string.h"
#include "stdio.h"

#include "constant.h"
#include "button.h"
#include "task.h"


volatile unsigned long sysTick;

// 32bit real time counter
void SysTickIntHandler (void)
{
    sysTick ++;
}

void sysInit(void)
{
	// clock divider have to be no more than 10, otherwise CPU will not run
	SysCtlClockSet (SYSCTL_SYSDIV_1 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
				   SYSCTL_XTAL_8MHZ);


	// At current configuration, pre-scalar set to 6 and SYSTICK_RATE set to 1e6,
	// it will takes 71 minutes to run out of 32 bit unsigned integer
	SysTickPeriodSet (SysCtlClockGet() / SYSTICK_RATE_HZ);

	// Register the interrupt handler
	SysTickIntRegister (SysTickIntHandler);

	// Enable interrupt and device
	SysTickIntEnable ();
	// Enable SysTick device (no interrupt)
	SysTickEnable ();
}


void pinReset(void)
{
	SysCtlPeripheralReset (SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralReset (SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralReset (SYSCTL_PERIPH_UART0);
	SysCtlPeripheralReset (SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralReset (SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralReset (SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralReset (SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralReset (SYSCTL_PERIPH_GPIOG);
}

void pinInit(void)
{
	// enable system peripherals
	SysCtlPeripheralEnable (SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOG);
}

void displayInit(void)
{
	RIT128x96x4Init(1000000);
}

void sometask(void *args)
{
	RIT128x96x4StringDraw ("HELLO", 0, 24, 15);
}

void sometask2(void *args)
{
	RIT128x96x4StringDraw ("MSDDR", 0, 24, 15);

	if (sysTick > 100000)
	{
		scheduler_cancel(0);
	}
}

int main(void)
{
	pinReset();
	sysInit();
	pinInit();
	buttonsInit();
	displayInit();
	scheduler_init(5);

	
	// enable the interrupt
	IntMasterEnable();

	unsigned int id[2];
	scheduler_create(&id[0], sometask, NULL, 1000);
	scheduler_create(&id[1], sometask2, NULL, 10000);

	scheduler_start();

	// trap here
	while (1)
	{

	}
}
