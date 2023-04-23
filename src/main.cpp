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
#include "../motor_driver.h"

using namespace std;

//int main() {
////	string file = "data/grid_data.txt";
////	Grid grid(file);
//	// Displays locations and list of neighbors
////	for (GridLocation loc : grid.getLocations()) {
////		cout<<loc.id<<" "<<loc.x<<" "<<loc.y<<" ";
////		cout<<"Neighbors: ";
////		for (GridLocation neighbor : grid.getNeighbors(loc.id)) {
////			cout<<neighbor.id<<" ";
////		}
////		cout<<endl;
////	}
//
////	for (Node node : getRoute(AStar(grid, {1,0,0}, {100,9,9}))) {
////		std::cout<<node.loc.id<<" ";
////	}
////	std::cout<<std::endl;
//
//	return 0;
//}

int main() {
	// Map
	string dataset = "data/grid_data.txt";
	// AWS dropbox file
	std::string aws_data = "/home/pi/Desktop/AWS/location.txt";

	Grid grid(dataset);

	int uart_port = uart_init();

	char msg[MSG_SIZE];

	char read_buff[BUFFER_SIZE];

	std::string aws_data_string;

	GridLocation src = {UNDEFINED, UNDEFINED, UNDEFINED};
	GridLocation dest = {UNDEFINED, UNDEFINED, UNDEFINED};

	/*
	 * Read data from AWS
	 * Generate route from current location to target read from AWS
	 * Translate route into motor instructions and buffer into PICO over UART PORT
	 */
	while (1) {
		// Read location from aws
		FileIO fio(aws_data);
		bool read_success = fio.read(aws_data_string);

		if (read_success) {  // Create GridLocation from AWS request
			if (std::strcmp(aws_data_string.c_str(), "Forward") == 0) {  // If string is "Forward"
			}
			else if (std::strcmp(aws_data_string.c_str(), "Left") == 0) {  // If string is "Left"
			}
			else if (std::strcmp(aws_data_string.c_str(), "Right") == 0) {  // If string is "Right"
			}
			else if (std::strcmp(aws_data_string.c_str(), "Reverse") == 0) {  // If string is "Reverse"
			}
			else {
				dest = {UNDEFINED, UNDEFINED, UNDEFINED};
			}
		}
		else {
			cout<<"No data read..."<<endl;
		}

		// Generate route from current location to target
		vector<Node> route;

		// What direction are we facing?
		CARDINAL_DIR facing;

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

		// Translate route to motor instructions
		instruction_block instructions = route_to_instructions(facing, route);

		// Send instructions to PICO
		std::string msg_string;

		for (bitset<INSTRUCTION_SIZE> instr : instructions) {
			msg_string = instr.to_string();

			strcpy(msg, msg_string.c_str());

			sleep(1);

			write(uart_port, msg, sizeof(msg));

			int bytes_read = read(uart_port, &read_buff, sizeof(read_buff));

			if (bytes_read < 0) {
				std::cout<<"Error reading data..."<<std::endl;
			}

			std::cout<<"Read "<<bytes_read<<" bytes. Received message: ";

			const char* char_p = &read_buff[0];

			for (int i = 0; i < bytes_read; i++) {
				std::cout<<*(char_p+i);
			}
			std::cout<<std::endl;
		}

		// Reset for next iteration
		fio.clear();
	}

	close(uart_port);
	return SUCCESS;
}
