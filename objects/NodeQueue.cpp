/*
 * NodeQueue.cpp
 *
 *  Created on: Apr 4, 2023
 *      Author: potts
 */

#include "../includes/NodeQueue.h"

bool sort_by_f_val(const Node& node1, const Node& node2) {
	return (node1.g + node1.h) < (node2.g + node2.h);
}

NodeQueue::NodeQueue() {}

NodeQueue::~NodeQueue() {}

void NodeQueue::enqueue(Node node) {
	this->data_members.push_back(node);
	this->data_queue.push(node);
	this->sort();
}

Node NodeQueue::dequeue() {
	Node next = this->data_queue.front();
	this->data_queue.pop();
	for (std::vector<Node>::iterator it=this->data_members.begin(); it != this->data_members.end(); it++) {
		if ((*it).loc.id == next.loc.id) {
			this->data_members.erase(it);  // There was a collision here where it would try to erase some shared memory
		}
		if (this->data_members.empty()) {
			break;
		}
	}
	return next;
}

bool NodeQueue::isEmpty() {
	return this->data_queue.empty();
}

bool NodeQueue::findNode(Node node) {
	for (std::vector<Node>::iterator it=this->data_members.begin(); it != this->data_members.end(); it++) {
		if ((*it).loc.id == node.loc.id) {
			return true;
		}
	}
	return false;
}

int NodeQueue::getNodeCost(Node node) {
	for (std::vector<Node>::iterator it=this->data_members.begin(); it != this->data_members.end(); it++) {
		if ((*it).loc.id == node.loc.id) {
			return (*it).g;
		}
	}
	return UNDEFINED;
}

void NodeQueue::replaceNode(Node node) {
	// Gonna go out on a limb and assume this->data_members is accurate.
	for (std::vector<Node>::iterator it=this->data_members.begin(); it != this->data_members.end(); it++) {
		if ((*it).loc.id == node.loc.id) {
			this->data_members.erase(it);
			this->data_members.push_back(node);
		}
	}
	this->sort();  // Replaces data in queue at end of function
}

void NodeQueue::sort() {
	// Clean out the queue (Assumes data_members member is accurate)
	while (!this->data_queue.empty()) {
		this->data_queue.pop();
	}
	// Sort data
	std::sort(this->data_members.begin(), this->data_members.end(), sort_by_f_val);
	// Replace data into queue
	for (std::vector<Node>::iterator it=this->data_members.begin(); it != this->data_members.end(); it++) {
		this->data_queue.push(*it);
	}
}
