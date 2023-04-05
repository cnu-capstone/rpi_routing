/*
 * routing.h
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#ifndef INCLUDES_ROUTING_H_
#define INCLUDES_ROUTING_H_

#include <vector>
#include <unordered_map>
#include "Grid.h"
#include "constants.h"
#include "NodeQueue.h"
#include "Node.h"

Node AStar(Grid &graph, GridLocation src, GridLocation dest);

std::vector<Node> getRoute(Node final_node);

#endif /* INCLUDES_ROUTING_H_ */
