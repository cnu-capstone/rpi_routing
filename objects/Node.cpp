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
//	this->parent = (new Node(parent));
    this->parent->loc = parent.loc;
    this->parent->g = parent.g;
//	this->parent = Node(parent);
	this->g = this->parent->g + manhattanDistance(this->parent->loc, location);
}

Node::Node(const Node& other) {
	if (other.parent) {
		this->parent = std::move(other.parent);
//		this->parent = new Node(*other.parent);
	}
	else {
		this->parent.reset();
	}
//	this->child = other.child;
	this->loc = other.loc;
	this->g = other.g;
	this->h = other.h;
}

Node::~Node() {
//	if (this->parent) {
//		delete parent;
//		this->parent = 0;
//	}
//	if (this->child) {
//		delete child;
//		this->child = 0;
//	}
}
