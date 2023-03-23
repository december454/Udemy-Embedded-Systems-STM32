// Griffin White
// 3-23-2023
// 2 - GPIO Output
// Udemy - Embedded Systems Bare-Metal Programming Ground Up (STM32)

/* This code follows along with Section 2: Video 11.
 * Like the prior projects, this program will blink the blue LED, "LD2".
 * This program provides utilizes pre-made libraries. This simplifies our code, removing the need
 * to manually define memory addresses and offsets.
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
		GPIOB->ODR ^= BLUE_LED_PIN;
		for (int i = 0; i < 200000; i++){}
	}
}
