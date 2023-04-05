/*
 * Node.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: potts
 */

#include "../includes/Node.h"

Node::Node(GridLocation location): parent(0), loc(location), g(UNDEFINED), h(UNDEFINED) {
}

Node::Node(GridLocation location, Node parent): loc(location), h(UNDEFINED) {
	std::unique_ptr<Node> unique (new Node(parent));
	this->parent = std::move(unique);
    this->parent->loc = parent.loc;
    this->parent->g = parent.g;
	this->g = this->parent->g + manhattanDistance(this->parent->loc, location);
}

Node::Node(const Node& other) {
	if (other.parent) {
		this->parent = std::move(other.parent);
	}
	else {
		this->parent.reset();
	}
	this->loc = other.loc;
	this->g = other.g;
	this->h = other.h;
}

Node::~Node() {
}
