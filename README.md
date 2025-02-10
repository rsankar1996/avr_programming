This repository contains basic peripheral drivers and sample test application for atmega328p controller.

As of now, following peripheral drivers are added:
 * GPIO
 * UART

To compile the test applications, 
 * navigate to test application folder: cd test/<app_name>
 * run "make"
 * executable will be generated within the same path
 * run "make clean" to cleanup the build

To run the hex file using avrdude tool,
 * Run the command "avrdude -p m328p -c arduino -P /dev/tty<port> -b 115200 -U flash:w:<hex_file.hex>:i"

To use the serial monitor, you can use minicom software,
 * To run minicom - "minicom -s" This will open the minicom software with setup menu. Configure the serial parameters and open the application.
