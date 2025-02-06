#include <stdint.h>
#include "uart.h"

int main()
{
	uart_init();

	uart_stream_tx("abcd\r\n");
	
	uart_tx('A');
	uart_tx('B');
	uart_tx('C');

	return 0;
}
