MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
APPLICATION = uart_app

all = uart_app.hex

INCL_DIR = ../../uart/

uart_app.hex: uart_app.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

uart_app.elf: main.o uart.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c -o $@ $<

uart.o: ../../uart/uart.c
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c -o $@ $<

clean:
	rm -f *.o *.elf *.hex
