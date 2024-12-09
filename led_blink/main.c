#include <util/delay.h>
#include "gpio.h"

int main()
{
	gpio_init(PORTB, 5, DIR_OUT);

	while(1)
	{
		gpio_write(PORTB, 5, GPIO_HIGH);
		_delay_ms(500);
		gpio_write(PORTB, 5, GPIO_LOW);
		_delay_ms(500);
	}

	return 0;
}
