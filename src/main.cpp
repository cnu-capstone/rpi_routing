/*
 * main.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include <bitset>
#include <iostream>
#include <string>
#include "../includes/Grid.h"
#include "../includes/routing.h"
#include "../includes/uart_comm.h"
#include "../includes/motor_driver.h"

using namespace std;

int main() {
	// Map
	string dataset = "data/lutr300_map.txt";
	// AWS dropbox file
	string aws_data = "/home/pi/Desktop/AWS/location.txt";

	Grid grid(dataset);

	int uart_port = uart_init();

	if (uart_port == TCGETATTR_ERR || uart_port == TCSETATTR_ERR) {
		cout<<"Closing program..."<<endl;
		return FAIL;
	}

	while (uart_port == SERIAL_ACCESS_ERR) {
		sleep(1);
		uart_port = uart_init();
	}

	char msg[MSG_SIZE];

	char read_buff[BUFFER_SIZE];

	string aws_data_string;

	GridLocation src = {UNDEFINED, UNDEFINED, UNDEFINED};
	GridLocation dest = {UNDEFINED, UNDEFINED, UNDEFINED};

	CARDINAL_DIR facing = EAST;

	/*
	 * Read data from AWS
	 * Generate route from current location to target read from AWS
	 * Translate route into motor instructions and buffer into PICO over UART PORT
	 */
	while (1) {
		// Read location from aws
		FileIO fio(aws_data);
		bool read_success = fio.read(aws_data_string);
//		bool read_success = true;

		if (read_success) {  // Create GridLocation from AWS request
			if (strcmp(aws_data_string.c_str(), "LUTR 302") == 0) {
				dest = {891, 26, 32};
			}
			else if (strcmp(aws_data_string.c_str(), "LUTR 303") == 0) {
				dest = {891, 26, 32};
			}
			else if (strcmp(aws_data_string.c_str(), "LUTR 304") == 0) {
				dest = {891, 26, 32};
			}
			else {
				dest = {UNDEFINED, UNDEFINED, UNDEFINED};
			}
		}
		else {
			cout<<"No data read..."<<endl;
			sleep(1);
			continue;
		}

		// Generate route from current location to target
		vector<Node> route;
		if (dest.id != UNDEFINED) {
			route = getRoute(AStar(grid, src, dest));
		}

		// Translate route to motor instructions
		instruction_block instructions = route_to_instructions(facing, route);

		// Send instructions to PICO
		string msg_string;

		for (bitset<INSTRUCTION_SIZE> instr : instructions) {
			msg_string = instr.to_string();

			strcpy(msg, msg_string.c_str());

			sleep(1);

			write(uart_port, msg, sizeof(msg));

			int bytes_read = read(uart_port, &read_buff, sizeof(read_buff));

			if (bytes_read < 0) {
				cout<<"Error reading data..."<<endl;
			}

			cout<<"Read "<<bytes_read<<" bytes. Received message: ";

			const char* char_p = &read_buff[0];

			for (int i = 0; i < bytes_read; i++) {
				cout<<*(char_p+i);
			}
			cout<<endl;
		}

		// Reset for next iteration
		// What direction are we facing at the end?
		GridLocation last_loc = route[route.size() - 1].loc;
		GridLocation before_last = route[route.size() - 2].loc;

		int delta_x_from_prev = last_loc.x - before_last.x;
		int delta_y_from_prev = last_loc.y - before_last.y;

		if (delta_x_from_prev > 0) {
			facing = EAST;
		}
		else if (delta_x_from_prev < 0) {
			facing = WEST;
		}
		else if (delta_y_from_prev > 0) {
			facing = NORTH;
		}
		else if (delta_y_from_prev < 0) {
			facing = SOUTH;
		}

		fio.clear();
		// Where did we end/ are we starting from?
		src = (*route.end()).loc;
	}

	close(uart_port);
	return SUCCESS;
}
