/*
 * routing.cpp
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#include "../includes/routing.h"

Node::Node(GridLocation location): parent(0), loc(location), g(0), h(0)  {

}
