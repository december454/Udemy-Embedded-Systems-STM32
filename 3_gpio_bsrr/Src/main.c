// Griffin White
// 3-23-2023
// 3 - GPIO Bit Set/Reset Register
// Udemy - Embedded Systems Bare-Metal Programming Ground Up (STM32)

/* This program follows along with Section 2: Video 12.
 * As in prior projects, this program toggles the blue LED "LD2" on and off.
 * This program utilizes the bit set/reset register to achieve this functionality.
 */

#include "stm32f4xx.h"

/////////////////////////////////// Additional Constants ///////////////////////////////////
#define GPIOBEN				(1U<<1)
#define BLUE_LED_PIN		(1U<<7)
/////////////////////////////////// Additional Constants End ///////////////////////////////

int main (void){

	RCC->AHB1ENR |= GPIOBEN;
	GPIOB->MODER |= (1U<<14);
	GPIOB->MODER &=~ (1U<<15);

	while(1){
		GPIOB->BSRR = BLUE_LED_PIN;
		for (int i = 0; i < 200000; i++){}
		GPIOB->BSRR = (1U<<23);
		for (int i = 0; i < 900000; i++){}
	}
}
