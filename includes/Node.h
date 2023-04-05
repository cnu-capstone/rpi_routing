/*
 * Node.h
 *
 *  Created on: Apr 5, 2023
 *      Author: potts
 */

#ifndef INCLUDES_NODE_H_
#define INCLUDES_NODE_H_

#include <memory>
#include "Grid.h"

// A class to represent a graph node
class Node {
public:
	Node(GridLocation location);
	Node(GridLocation location, Node parent);
	Node(const Node& other);  // Copy constructor
	~Node();
	std::shared_ptr<Node> parent;
//	Node* parent;
//	Node* child;
	GridLocation loc;
	int g; 	// g is distance from src
	int h;  // h is distance from dest
};

#endif /* INCLUDES_NODE_H_ */
