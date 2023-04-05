/*
 * routing.cpp
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#include "../includes/routing.h"

int manhattanDistance(GridLocation src, GridLocation target) {
	return abs(src.x - target.x) + abs(src.y - target.y);
}

Node::Node(GridLocation location): parent(0), loc(location), g(UNDEFINED), h(UNDEFINED) {
}


