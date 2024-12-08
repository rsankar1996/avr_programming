This project showcase the examples to run on avr platform. Here I have used the simple arduino uno board, but using the avr-gcc compiler to compile and avrdude to flash the program.

To compile the program and generate the hex file, navigate to each project folder and run the make command.

To run the hex file using avrdude tool, run the following command:
./run_pgm <port> <hex_file>
