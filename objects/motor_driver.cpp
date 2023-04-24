/*
 * motor_driver.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: potts
 */

#include "../includes/motor_driver.h"

CARDINAL_DIR dir_facing_check(GridLocation curr, GridLocation prev) {
	// Which direction are we facing?
	// If pos delta x -> Facing EAST (pos x direction)
	// If pos delta y -> Facing NORTH (pos y direction)
	// If neg delta x -> Facing WEST (neg x direction)
	// If neg delta y -> Facing SOUTH (neg y direction)
	int delta_x_from_prev = curr.x - prev.x;
	int delta_y_from_prev = curr.y - prev.y;

	CARDINAL_DIR facing;

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

	return facing;
}

CARDINAL_DIR dir_driving_check(GridLocation curr, GridLocation next) {
	int delta_x_to_next = next.x - curr.x;
	int delta_y_to_next = next.y - curr.y;

	CARDINAL_DIR driving;

	if (delta_x_to_next > 0) {
		driving = EAST;
	}
	else if (delta_x_to_next < 0) {
		driving = WEST;
	}
	else if (delta_y_to_next > 0) {
		driving = NORTH;
	}
	else if (delta_y_to_next < 0) {
		driving = SOUTH;
	}

	return driving;
}

instruction_block route_to_instructions(CARDINAL_DIR facing, std::vector<Node>& route) {
	instruction_block block;

	int i = 0;

	while (i < route.size()) {
		if (i > 0) {
			facing = dir_facing_check(route[i].loc, route[i - 1].loc);
		}

		CARDINAL_DIR driving;
		// Determing driving direction by looking at next
		if (i < route.size() - 1) {
			driving = dir_driving_check(route[i].loc, route[i + 1].loc);
		}

		// If driving is not on the left or right of facing: we can go straight.
		if (((*left.find(facing)).second != driving) && ((*right.find(facing)).second != driving)) {
			// Check how far we can drive forward?
			bool forward_end_check = false;
			int forward_count = 1;
			while (i + forward_count + 1 < route.size() && dir_driving_check(route[i + forward_count].loc, route[i + forward_count + 1].loc) == driving) {
				forward_count++;
			}

			forward_end_check = i + forward_count + 1 == route.size();

			i += forward_count - 1;

			while (forward_count > 0) {
				std::bitset<INSTRUCTION_SIZE> instr;
				if (forward_count > 32) {
					instr.set();
					forward_count -= 32;
				}
				else {
					std::bitset<INSTRUCTION_SIZE> distance(forward_count);
					instr ^= distance;  // XOR assignment
					instr.set(7); instr.set(6); instr.set(5);
					forward_count = 0;
				}
				block.push_back(instr);
			}
			if (forward_end_check) {  // Handle case where last instr is forward so it adds another
				break;
			}
		}
		else {
			std::bitset<INSTRUCTION_SIZE> instr; instr.set();
			// We need to turn
			// Left turn
			if ((*left.find(facing)).second == driving) {
				instr.set(5, 0);
			}
			// Right turn
			else if ((*right.find(facing)).second == driving) {
				instr.set(6, 0);
			}
			else {
				// pull a U-ey
				instr.set(7, 0);  // Just back up
			}
			block.push_back(instr);
		}
		i++;
	}
	return block;
}

