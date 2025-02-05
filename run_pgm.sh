if [ $# != 2 ]; then
	echo "Insufficient data to run the script"
	echo "./run_pgm.sh <port> <hex file>"
	exit
fi

avrdude -p m328p -c arduino -P $1 -b 115200 -U flash:w:$2:i
