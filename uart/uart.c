#include <stdint.h>
#include "uart.h"

void uart_init()
{
	/* Enable tx */
	*(volatile uint8_t *)UART_UCSR0B = (0x01 << 3);

	/* Set baud rate to 9600 */
 	*(volatile uint8_t *)UART_UBRR0H = 0;
	*(volatile uint8_t *)UART_UBRR0L = 0x67;

	/* Set 8 bit data mode and 1 stop bit */
	*(volatile uint8_t *)UART_UCSR0C = ((0x01 << 2) | (0x01 << 1));
}

void uart_tx(char data)
{
	*(volatile uint8_t *)UART_UDR0 = data;

	/* wait till the shift register is empty */
	while ((*(volatile uint8_t *)UART_UCSR0A & (0x01 << 6)) == 0);

	*(volatile uint8_t *)UART_UCSR0A |= (0x01 << 6);
}

void uart_string_tx(char * data)
{
	while (*data != '\0')
	{
		uart_tx(*data);
		data++;
	}
}
