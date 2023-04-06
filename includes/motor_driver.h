/*
 * motor_driver.h
 *
 *  Created on: Apr 5, 2023
 *      Author: potts
 */

#ifndef INCLUDES_MOTOR_DRIVER_H_
#define INCLUDES_MOTOR_DRIVER_H_

#include <bitset>
#include "routing.h"
#include "constants.h"

typedef std::vector<std::bitset<INSTRUCTION_SIZE>> instruction_block;

enum CARDINAL_DIR {NORTH, EAST, SOUTH, WEST};

std::unordered_map<CARDINAL_DIR, CARDINAL_DIR> left ({{NORTH, WEST}, {WEST, SOUTH}, {SOUTH, EAST}, {EAST, NORTH}});
std::unordered_map<CARDINAL_DIR, CARDINAL_DIR> right ({{NORTH, EAST}, {EAST, SOUTH}, {SOUTH, WEST}, {WEST, NORTH}});

// Moved to constants.h
//#define STALL 0  // {0,0,0};
//#define RLEFT 1  // {0,0,1};
//#define RRIGHT 2  // {0,1,0};
//#define REVERSE 3  // {0,1,1};
//#define FLEFT 6  // {1,1,0};
//#define FRIGHT 5  // {1,0,1};
//#define FORWARD 7  // {1,1,1};

struct instruction {
	uint8_t motor_command;
	uint8_t distance;
//	std::bitset<INSTRUCTION_SIZE> binary_string;
};

//instruction_block subroute_to_instructions(GridLocation src, GridLocation dest, GridLocation prev);

instruction_block route_to_instructions(CARDINAL_DIR facing, std::vector<Node> route);

#endif /* INCLUDES_MOTOR_DRIVER_H_ */
