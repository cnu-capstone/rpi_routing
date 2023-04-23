/*
 * uart_comm.h
 *
 *  Created on: Apr 2, 2023
 *      Author: potts
 */

#ifndef INCLUDES_UART_COMM_H_
#define INCLUDES_UART_COMM_H_

#include <stdio.h>
#include <unistd.h>  // Serial Bus R/W
#include <fcntl.h>  // TTY file control
#include <termios.h>  // Terminal control definitions
#include <errno.h>  // sterror() function
#include <string>
#include <iostream>
#include <cstring>

#include "FileIO.h"  // File IO header
#include "constants.h"

//#define SUCCESS 0
#define SERIAL_ACCESS_ERR -1
#define TCGETATTR_ERR -2
#define TCSETATTR_ERR -3

#define UART_BAUDR B115200
#define MSG_SIZE 8
#define BUFFER_SIZE 1024

int uart_init();

void close_uart(int uart_port);

#endif /* INCLUDES_UART_COMM_H_ */
