#ifndef _UART_H
#define _UART_H

#define UART_UDR0	0xC6
#define UART_UBRR0H	0xC5
#define UART_UBRR0L	0xC4
#define UART_UCSR0A	0xC0
#define UART_UCSR0B	0xC1
#define UART_UCSR0C	0xC2

void uart_init();
void uart_tx(char data);
void uart_string_tx(char * data);

#endif /* _UART_H */
