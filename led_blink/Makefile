MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
APPLICATION = led_blink

all = main.hex

INCL_DIR = ../gpio/

led_blink.hex: led_blink.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

led_blink.elf: main.o gpio.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c -o $@ $<

gpio.o: ../gpio/gpio.c
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c -o $@ $<

clean:
	rm -f *.o *.elf *.hex
