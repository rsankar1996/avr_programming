To run the hex file using avrdude tool, run the following command:

avrdude -p m328p -c arduino -P /dev/tty<port> -b 115200 -U flash:w:<hex_file.hex>:i
