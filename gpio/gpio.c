#include "gpio.h"

void gpio_init(uint8_t port, uint8_t pin, gpio_dir dir)
{
	if (DIR_OUT == dir)
	{
		*(volatile uint8_t*)(REG_DDRB + port) |= (PIN_MASK << pin);
	}
	else
	{
		*(volatile uint8_t*)(REG_DDRB + port) &= ~(PIN_MASK << pin);
	}
}

void gpio_write(uint8_t port, uint8_t pin, gpio_state state)
{
	if (GPIO_HIGH == state)
	{
		*(volatile uint8_t*)(REG_PORTB + port) |= (PIN_MASK << pin);
	}
	else
	{
		*(volatile uint8_t*)(REG_PORTB + port) &= ~(PIN_MASK << pin);
	}
}

gpio_state gpio_read(uint8_t port, uint8_t pin)
{
	gpio_state state = GPIO_LOW;

	state = ((*(volatile uint8_t*)(PORTB + port)) & (PIN_MASK << pin)) == (PIN_MASK << pin);

	return state;
}
