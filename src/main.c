#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BASE + 0x20000U)
#define GPIOD_BASE (AHB1_BASE + 0x0C00U)
#define RCC_BASE (AHB1_BASE + 0x3800U)

// Page 117, 6.3.9
#define RCC_AHB1ENR_OFFSET (0x30U) 
#define RCC_AHB1ENR ((volatile uint32_t*)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_GPIODEN (0x03U)

// Page 163, table.
#define GPIO_MODER_OFFSET (0x00U)
#define GPIOD_MODER ((volatile uint32_t*)(GPIOD_BASE + GPIO_MODER_OFFSET))
#define GPIOD_MODER_12 (0x18U)

// Page 164, table
#define GPIO_ODR_OFFSET (0x14U)
#define GPIOD_ODR ((volatile uint32_t*)(GPIOD_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 12

void blink_all_leds()
{
	uint8_t led_pins[] = {12, 13, 14, 15};
	uint8_t current_led = 0;

	for (uint8_t i = 0; i < sizeof(led_pins); ++i)
	{
		*GPIOD_MODER |= (1 << (GPIOD_MODER_12 + ((led_pins[i] - LED_PIN) * 0x2U)));	
	}
		
	while(1)
	{
		*GPIOD_ODR ^= (1 << led_pins[current_led]);
		for (uint32_t i = 0; i < 1000000; ++i);
		*GPIOD_ODR ^= (1 << led_pins[current_led]);
		current_led = (current_led + 1) % 4;
	}

}

void main(void)
{
	// Enable the peripheral clock.
	*RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIODEN);
	
	// Set the mode to output.
	*GPIOD_MODER |= (1 << GPIOD_MODER_12);
	
	blink_all_leds();	
/*	
	while(1)
	{
		*GPIOD_ODR ^= (1 << LED_PIN);
		for (uint32_t i = 0; i < 1000000; ++i);
	}
	*/
}
