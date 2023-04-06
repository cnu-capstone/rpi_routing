/*
 * motor_driver.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: potts
 */

#include "../includes/motor_driver.h"

//instruction_block subroute_to_instructions(GridLocation src, GridLocation dest, GridLocation prev) {
//	instruction_block block;
//	// Which direction are we facing?
//	CARDINAL_DIR facing;
//	// If pos delta x -> Facing EAST (pos x direction)
//	// If pos delta y -> Facing NORTH (pos y direction)
//	// If neg delta x -> Facing WEST (neg x direction)
//	// If neg delta y -> Facing SOUTH (neg y direction)
//	int delta_x_from_prev = src.x - prev.x;
//	int delta_y_from_prev = src.y - prev.y;
//
//	if (delta_x_from_prev > 0) {
//		facing = EAST;
//	}
//	else if (delta_x_from_prev < 0) {
//		facing = WEST;
//	}
//	else if (delta_y_from_prev > 0) {
//		facing = NORTH;
//	}
//	else if (delta_y_from_prev < 0) {
//		facing = SOUTH;
//	}
//
//	CARDINAL_DIR driving;
//
//	int delta_x_to_dest = dest.x - src.x;
//	int delta_y_to_dest = dest.y - src.y;
//
//	if (delta_x_to_dest > 0) {
//		driving = EAST;
//	}
//	else if (delta_x_to_dest < 0) {
//		driving = WEST;
//	}
//	else if (delta_y_to_dest > 0) {
//		driving = NORTH;
//	}
//	else if (delta_y_to_dest < 0) {
//		driving = SOUTH;
//	}
//
//	std::pair<CARDINAL_DIR, CARDINAL_DIR> transition (facing, driving);
//
//
//	// move in y direction
//	if (abs(dest.y - src.y) > 0) {
//
//	}
//	// move in x direction
//	else if (abs(dest.x - src.x) > 0) {
//
//	}
//	return block;
//}

instruction_block route_to_instructions(CARDINAL_DIR facing, std::vector<Node> route) {
	instruction_block block;

	for (std::vector<Node>::size_type i = 0; i < route.size(); i++) {
		if (i > 0) {
			//	// Which direction are we facing?
			//	// If pos delta x -> Facing EAST (pos x direction)
			//	// If pos delta y -> Facing NORTH (pos y direction)
			//	// If neg delta x -> Facing WEST (neg x direction)
			//	// If neg delta y -> Facing SOUTH (neg y direction)
			int delta_x_from_prev = route[i].loc.x - route[i - 1].loc.x;
			int delta_y_from_prev = route[i].loc.x - route[i - 1].loc.x;

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
		}

		CARDINAL_DIR driving;

		// If driving is not on the left or right of facing: we can go straight.
		if (((*left.find(facing)).second != driving) || ((*right.find(facing)).second != driving)) {

		}
		else {
			// We need to turn
			// Left turn
			if ((*left.find(facing)).second == driving) {

			}
			// Right turn
			else if ((*right.find(facing)).second == driving) {

			}
			else {
				// pull a U-ey
			}
		}

	}
}

