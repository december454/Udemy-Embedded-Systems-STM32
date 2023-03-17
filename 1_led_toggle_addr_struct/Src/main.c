// Griffin White
// 3-16-2023
// 1 - LED Toggle Address Structure Members
// Udemy - Embedded Systems Bare-Metal Programming Ground Up (STM32)

/* This code follows along with Section 1: Video 8.
 * This program provides the same function as "0_led_toggle_addr". However, this version uses
 * structure members to perform various functions. This is less cumbersome than explicitly defining
 * memory offsets.
 */

#include <stdint.h>

#define PERIPH_BASE 		(0x40000000UL)

#define AHB1PERIPH_OFFEST	(0x00020000UL)
#define AHB1PERIPH_BASE 	(PERIPH_BASE + AHB1PERIPH_OFFEST)

#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN				(1U<<0)

#define PIN_5				(1U<<5)
#define LED_PIN				PIN_5

/////////////////////////////////// Additional Constants ///////////////////////////////////
#define GPIOB_OFFSET 		(0x00000400UL)
#define GPIOB_BASE			(AHB1PERIPH_BASE + GPIOB_OFFSET)
#define GPIOBEN				(1U<<1)
#define BLUE_LED_PIN		(1U<<7)
/////////////////////////////////// Additional Constants End ///////////////////////////////

#define __IO volatile

// Structure for GPIO operations.
typedef struct{
	volatile uint32_t MODER;		// GPIO port mode register.	Address offset: 0x00
	volatile uint32_t DUMMY[4];	 	// Dummy data to maintain correct offset.
	volatile uint32_t ODR;			// GPIO port output data register. Address offset: 0x14
}GPIO_TypeDef;

// Structure for RCC operations.
typedef struct{
	volatile uint32_t DUMMY[12]; 	// Dummy data to maintain correct offset.
	volatile uint32_t AHB1ENR;		// RCC AHB1 peripheral clock register.
} RCC_TypeDef;

// Type-casting the structures to the base addresses.
#define RCC		((RCC_TypeDef*) RCC_BASE)
#define GPIOB	((GPIO_TypeDef*)GPIOB_BASE)

int main(void) {
	// Enable clock access to GPIOB, using the "RCC_TypeDef" structure.
	RCC->AHB1ENR |= GPIOBEN;

	// Set PB7 as an output pin, using the "GPIO_TypeDef" structure.
	GPIOB->MODER |=  (1U<<14);			// Set bit 14 to 1.
	GPIOB->MODER &=~ (1U<<15);			// Set bit 15 to 0.

	while (1){
		// Toggle PB7, using the "GPIO_TypeDef" structure.
		GPIOB->ODR ^= BLUE_LED_PIN;
		for (int i = 0; i < 900000; i++){}
	}
}
