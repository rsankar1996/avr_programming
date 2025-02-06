#include <stdint.h>
#include "uart.h"

int main()
{
	uart_init();

	uart_string_tx("This string was send through uart\r\n");
	
	uart_tx('A');
	uart_tx('B');
	uart_tx('C');

	return 0;
}
