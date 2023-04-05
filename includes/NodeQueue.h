/*
 * NodeQueue.h
 *
 *  Created on: Apr 4, 2023
 *      Author: potts
 */

#ifndef INCLUDES_NODEQUEUE_H_
#define INCLUDES_NODEQUEUE_H_

#include <vector>
#include <algorithm>
#include <queue>
#include "routing.h"
#include "constants.h"

class NodeQueue {
public:
	NodeQueue();
	~NodeQueue();
	void enqueue(Node node);
	Node dequeue();
	bool isEmpty();
	bool findNode(Node node);
	int getNodeCost(Node node);
	void replaceNode(Node node);
private:
	void sort();
	std::queue<Node> data_queue;
	std::vector<Node> data_members;
};


#endif /* INCLUDES_NODEQUEUE_H_ */
