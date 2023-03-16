// Griffin White
// 3-16-2023
// 0 - LED Toggle Address
// Udemy - Embedded Systems Bare-Metal Programming Ground Up (STM32)

/* This code follows along with Section 1: Videos 5-7.
 *
 * I have made slight changes to the code (which was written for the NUCLEO-F411RE) so that it functions
 * with the NUCLEO-F412ZG board. The code was designed to use LED "LD1", which is typically assigned to PA5.
 * However, LD1 is assigned elsewhere on the F412ZG board. So, I decided to use LD2, which is assigned to
 * PB7. I have added additional constants and commented out the original code in the main method.
 */

#define PERIPH_BASE 		(0x40000000UL)

#define AHB1PERIPH_OFFEST	(0x00020000UL)
#define AHB1PERIPH_BASE 	(PERIPH_BASE + AHB1PERIPH_OFFEST)

#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *) (RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *) (GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFEST			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int *) (GPIOA_BASE + OD_R_OFFEST))

#define GPIOAEN				(1U<<0)

#define PIN_5				(1U<<5)
#define LED_PIN				PIN_5

/////////////////////////////////// Additional Constants ///////////////////////////////////
#define GPIOB_OFFSET 		(0x00000400UL)
#define GPIOB_BASE			(AHB1PERIPH_BASE + GPIOB_OFFSET)
#define GPIOB_MODE_R		(*(volatile unsigned int *) (GPIOB_BASE + MODE_R_OFFSET))
#define GPIOB_OD_R			(*(volatile unsigned int *) (GPIOB_BASE + OD_R_OFFEST))
#define GPIOBEN				(1U<<1)
#define BLUE_LED_PIN		(1U<<7)
/////////////////////////////////// Additional Constants End ///////////////////////////////

int main(void) {
	// Enable clock access to GPIOA, without assigning any other bits.
	// RCC_AHB1EN_R |= GPIOAEN;

	// Enable clock access to GPIOB, without assigning any other bits.
	RCC_AHB1EN_R |= GPIOBEN;

	// Set PA5 as output pin.
	// GPIOA_MODE_R |=  (1U<<10);		// Set bit 10 to 1.
	// GPIOA_MODE_R &=~ (1U<<11);		// Set bit 11 to 0.

	// Set PB7 as an output pin.
	GPIOB_MODE_R |=  (1U<<14);			// Set bit 14 to 1.
	GPIOB_MODE_R &=~ (1U<<15);			// Set bit 15 to 0.

	while (1){
		// Set PA5 high. (Turn on LED)
		// GPIOA_OD_R |= LED_PIN;

		// Set PB7 high. (Turn on blue LED)
		GPIOB_OD_R |= BLUE_LED_PIN;
	}

}


