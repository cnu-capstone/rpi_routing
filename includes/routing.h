/*
 * routing.h
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#ifndef INCLUDES_ROUTING_H_
#define INCLUDES_ROUTING_H_

//#include <iostream>
#include <vector>
//#include <unordered_set>
#include <unordered_map>
//#include <queue>
//#include <algorithm>
#include "Grid.h"
#include "constants.h"
#include "NodeQueue.h"
#include "Node.h"

//// A class to represent a graph node
//class Node {
//public:
//	Node(GridLocation location);
//	Node(GridLocation location, Node parent);
//	Node(const Node& other);  // Copy constructor
//	~Node();
//	Node* parent;
//	GridLocation loc;
//	int g; 	// g is distance from src
//	int h;  // h is distance from dest
//};

//// A comparison class to be used in priority queue
//class CompareNodes {
//public:
//    bool operator() (const Node& node1, const Node& node2) {
//        return (node1.g + node1.h) > (node2.g + node2.h);
//    }
//};

//int manhattanDistance(GridLocation src, GridLocation target);

Node AStar(Grid &graph, GridLocation src, GridLocation dest);

std::vector<Node> getRoute(Node final_node);

#endif /* INCLUDES_ROUTING_H_ */
