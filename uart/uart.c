#include <stdint.h>
#include "uart.h"

/* UART Control and Status Register n A */
#define UART_RXCOMP_BITOFF	7
#define UART_TXCOMP_BITOFF	6
#define UART_UDREM_BITOFF	5
#define UART_FRM_ERR_BITOFF	4
#define UART_OVERRUN_ERR_BITOFF	3
#define UART_PARITY_ERR_BITOFF	2

/* UART Control and Status Register n B */
#define UART_TXEN_BITOFF	3
#define UART_RXEN_BITOFF	4

/* UART Control and Status Register n C */
#define UART_MODE_SEL_BITOFF	6
#define MODE_ASYNC_UART		0x00
#define MODE_SYNC_UART		0x01
#define MODE_RESERVE		0x02
#define MODE_SPI		0x03

#define UART_PARITY_SEL_BITOFF	4
#define PARITY_DIS		0x00
#define	PARITY_EN_EVEN		0x02
#define PARITY_EN_ODD		0x03

#define UART_CHAR_SIZE_BITOFF	1
#define UART_CHAR_5BIT		0x00
#define UART_CHAR_6BIT		0x01
#define UART_CHAR_7BIT		0x02
#define UART_CHAR_8BIT		0x03

static void config_baud_rate(int baud)
{
	uint16_t ubrr = 0;

	ubrr = (uint16_t)((F_CPU / (16.0 * baud)) - 1);

	*(volatile uint8_t *)UART_UBRR0H = (uint8_t)((ubrr & (0x0f << 8)) >> 8);
	*(volatile uint8_t *)UART_UBRR0L = (uint8_t)(ubrr & 0xff);
}

void uart_init()
{
	/* Enable RX and TX */
	*(volatile uint8_t *)UART_UCSR0B = (0x01 << UART_TXEN_BITOFF) | (0x01 << UART_RXEN_BITOFF);

	/* Set baud rate to 9600 */
	config_baud_rate(9600);

	/* Set 8 Bit data mode */
	*(volatile uint8_t *)UART_UCSR0C = (PARITY_DIS << UART_PARITY_SEL_BITOFF) | (UART_CHAR_8BIT << UART_CHAR_SIZE_BITOFF);
}

void uart_tx(char data)
{
	*(volatile uint8_t *)UART_UDR0 = data;

	/* wait till the shift register is empty */
	while ((*(volatile uint8_t *)UART_UCSR0A & (0x01 << UART_TXCOMP_BITOFF)) == 0);

	*(volatile uint8_t *)UART_UCSR0A |= (0x01 << UART_TXCOMP_BITOFF);
}

void uart_string_tx(char * data)
{
	while (*data != '\0')
	{
		uart_tx(*data);
		data++;
	}
}
