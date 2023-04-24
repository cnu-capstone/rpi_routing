/*
 * uart_comm.cpp
 *
 *  Created on: Apr 2, 2023
 *      Author: potts
 */

#include "../includes/uart_comm.h"

int uart_init() {
	int uart_port = open("/dev/ttyACM0", O_RDWR);

	// Error handling for opening file stream
	if (uart_port < 0) {
		std::cout<<"Error opening file /dev/ttyACM0..."<<std::endl;
		return SERIAL_ACCESS_ERR;
	}

	struct termios tty;

	// Read in existing settings, and handle any error
	if (tcgetattr(uart_port, &tty) != 0) {
		std::cout<<"Error getting tty attributes..."<<std::endl;
		return TCGETATTR_ERR;
	}

	// UART utilizes B115200 8N1
	// 8 Num Bits
	// No Parity
	// 1 Stop Bit

	tty.c_cflag &= ~PARENB;  // Clears Parity Bit
	tty.c_cflag &= ~CSTOPB;  // Clears stop field, 1 bit is used
	tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
	tty.c_cflag |= CS8; // 8 bits per byte
	tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
	tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines

	tty.c_lflag |= ICANON;  // Turns on canonical mode (newline termin.)
	tty.c_lflag &= ~ECHO; // Disable echo
	tty.c_lflag &= ~ECHOE; // Disable erasure
	tty.c_lflag &= ~ECHONL; // Disable new-line echo
	tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP
	tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl
	tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

	tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
	tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed

	tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
	tty.c_cc[VMIN] = 0;

	// Set in/out baud rate to be 115200
	cfsetispeed(&tty, UART_BAUDR);
	cfsetospeed(&tty, UART_BAUDR);

	// Save tty settings, also checking for error
	if (tcsetattr(uart_port, TCSANOW, &tty) != 0) {
	  //printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
	  std::cout<<"Error setting tty attributes..."<<std::endl;
	  return TCGETATTR_ERR;
	}

	return uart_port;
}

void close_uart(int uart_port) {
	close(uart_port);
}
