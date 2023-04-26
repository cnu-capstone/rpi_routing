/*
 * testing.cpp
 *
 *  Created on: Jan 20, 2023
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

// Comment out main function in main.cpp to utilize this main for testing
// ("temporary solution" lol)

int main() {
	string file = "data/lutr300_map.txt";
	string aws_data = "/home/pi/Desktop/AWS/location.txt";
//	string aws_data = "data/location.txt";

	Grid grid(file);

	string aws_data_string;

	GridLocation src = {1, 0, 0};
	GridLocation dest = {UNDEFINED, UNDEFINED, UNDEFINED};

	CARDINAL_DIR facing = EAST;

	// Read location from aws
	FileIO fio(aws_data);
	bool read_success = fio.read(aws_data_string);

	if (read_success) {  // Create GridLocation from AWS request
		cout<<aws_data_string<<endl;
		if (strcmp(aws_data_string.c_str(), "302\n") == 0) {
			dest = {891, 26, 32};
		}
		else if (strcmp(aws_data_string.c_str(), "303\n") == 0) {
			dest = {891, 26, 32};
		}
		else if (strcmp(aws_data_string.c_str(), "304\n") == 0) {
			dest = {891, 26, 32};
		}
		else {
			dest = {UNDEFINED, UNDEFINED, UNDEFINED};
		}
	}
	else {
		cout<<"No data read..."<<endl;
		return -1;
	}

	// Generate route from current location to target
	vector<Node> route;
	if (dest.id != UNDEFINED) {
		route = getRoute(AStar(grid, src, dest));
	}

	for (Node node : route) {
		std::cout<<node.loc.id<<" ";
	}
	cout<<endl<<endl;

	// Translate route to motor instructions
	instruction_block instructions = route_to_instructions(facing, route);

	// Send instructions to PICO
	string bit_string;

	for (bitset<INSTRUCTION_SIZE> instr : instructions) {
		bit_string = instr.to_string();
		cout<<bit_string<<endl;
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
//	src = (*route.end()).loc;

	return 0;
}
