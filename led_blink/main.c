#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN		PD2
#define LED_DDR		DDRD
#define LED_PORT	PORTD

int main()
{
	LED_DDR |= (1 << LED_PIN);

	while(1)
	{
		LED_PORT ^= (1 << LED_PIN);

		_delay_ms(500);
	}

	return 0;
}
