#include <stdint.h>

#define UART_UDR0	0xC6
#define UART_UBRR0H	0xC5
#define UART_UBRR0L	0xC4
#define UART_UCSR0A	0xC0
#define UART_UCSR0B	0xC1
#define UART_UCSR0C	0xC2


int main()
{
	*(volatile uint8_t *)UART_UCSR0B = (0x01 << 3); // transmit enable
	*(volatile uint8_t *)UART_UBRR0H = 0;
	*(volatile uint8_t *)UART_UBRR0L = 0x67;
	*(volatile uint8_t *)UART_UCSR0C = ((0x01 << 2) | (0x01 << 1));

	*(volatile uint8_t *)UART_UDR0 = 'A';

	while ((*(volatile uint8_t *)UART_UCSR0A & (0x01 << 6)) == 0);

	*(volatile uint8_t *)UART_UDR0 = 'B';

	while ((*(volatile uint8_t *)UART_UCSR0A & (0x01 << 6)) == 0);
 
	return 0;
}
