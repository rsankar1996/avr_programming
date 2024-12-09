#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef enum
{
	DIR_IN,
	DIR_OUT
} gpio_dir;

typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
} gpio_state;

#define PIN_MASK	(0x01)

#define PORTB		(0x00)
#define PORTC		(0x03)
#define PORTD		(0x06)

#define REG_PORTB		0x25
#define REG_PORTC		0x28
#define REG_PORTD		0x2B

#define REG_DDRB		0x24
#define REG_DDRC		0x27
#define REG_DDRD		0x2A

#define REG_PINB		0x23
#define REG_PINC		0x26
#define REG_PIND		0x29

void gpio_init(uint8_t port, uint8_t pin, gpio_dir dir);
void gpio_write(uint8_t port, uint8_t pin, gpio_state state);
gpio_state gpio_read(uint8_t port, uint8_t pin);

#endif /* GPIO_H_ */
