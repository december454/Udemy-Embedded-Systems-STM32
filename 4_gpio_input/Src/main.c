// Griffin White
// 3-23-2023
// 4 - GPIO Input
// Udemy - Embedded Systems Bare-Metal Programming Ground Up (STM32)

/* Video:	 Section 2: Video 13.
 * Function: LED (LD2) is illuminated by default. While the button (B1) is pressed, the LED turns off.
 *
 * This program illustrates the use of input pins as well as some basic flow control logic.
 */

#include "stm32f4xx.h"

#define GPIOCEN				(1U<<2)
#define PIN13				(1U<<13)
#define BTN_PIN				(PIN13)

/////////////////////////////////// Additional Constants ///////////////////////////////////
#define GPIOBEN				(1U<<1)
#define PIN7				(1U<<7)
#define BLUE_LED_PIN		(PIN7)
/////////////////////////////////// Additional Constants End ///////////////////////////////

int main (void){

	// Enable clock access to GPIOA & GPIOC
	RCC->AHB1ENR |= GPIOBEN;
	RCC->AHB1ENR |= GPIOCEN;

	// Set PB7 (LED LD2) as output pin.
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &=~ (1U<<15);

	// Set PC13 (User Button B1) as input pin.
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);

	while(1){
		// If the button is pressed, turn on the LED.
		if(GPIOC->IDR & BTN_PIN)
			GPIOB->BSRR = (1U<<23);
		// Else, turn off the LED.
		else
			GPIOB->BSRR = BLUE_LED_PIN;

	}
}
