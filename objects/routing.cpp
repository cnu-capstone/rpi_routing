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

Node::Node(GridLocation location, Node parent): loc(location), h(UNDEFINED) {
	this->parent = new Node(parent);
	this->g = this->parent->g + manhattanDistance(this->parent->loc, location);
}

Node::Node(Node other) {
	this->parent = other.parent;
	this->loc = other.loc;
	this->g = other.g;
	this->h = other.h;
}

Node AStar(Grid &graph, GridLocation src, GridLocation dest) {
	NodeQueue open_list;
//	std::unordered_set<GridLocation,GridLocationHasher,GridLocationEqual> closed_list;
	std::unordered_map<GridLocation, int, GridLocationHasher, GridLocationEqual> closed_list;

	Node curr = Node(src); curr.g = manhattanDistance(src, curr.loc); curr.h = manhattanDistance(curr.loc, dest);

	open_list.enqueue(curr);

	while (!open_list.isEmpty()) {  // Goes until queue is empty. Old used when curr = dest.
		Node target = open_list.dequeue();
		if (target.loc.id == dest.id) {
			return target;
		}
		else {
			curr = target;
			std::pair<GridLocation, int> curr_cost (curr.loc, curr.g);
			closed_list.insert(curr_cost);
			int curr_f = curr.g + curr.h;
			for (GridLocation neighbor : graph.getNeighbors(curr.loc.id)) {
				// Cost from curr to neighbor
				int curr_to_neighbor_cost = manhattanDistance(curr.loc, neighbor);

				Node neighbor_node = Node(neighbor, curr); neighbor_node.h = manhattanDistance(neighbor, dest);

//				int neighbor_g = curr.g + curr_to_neighbor_cost;
//				int neighbor_h = manhattanDistance(neighbor, dest);
//				Node neighbor_node = Node(neighbor); neighbor_node.g = neighbor_g; neighbor_node.h = neighbor_h;

//				if ((neighbor_g < curr.g) && (closed_list.find(neighbor) != closed_list.end())) {
//					neighbor_node.parent = new Node(curr);
//
//				}
//				else if (((curr.g+curr_to_neighbor_cost) < neighbor_g) && (open_list.findNode(neighbor_node))) {
//
//				}
//				else if ((open_list.findNode(neighbor_node)) && (closed_list.find(neighbor) != closed_list.end())) {
//					neighbor_node.parent = new Node(curr);
//					open_list.enqueue(neighbor_node);
				if ((open_list.findNode(neighbor_node)) && (curr_to_neighbor_cost < open_list.getNodeCost(neighbor_node))) {
					open_list.replaceNode(neighbor_node);
				}
				if ((closed_list.find(neighbor) != closed_list.end()) && (curr_to_neighbor_cost < closed_list.find(neighbor)->second)) {
					closed_list.erase(neighbor);
				}
				if ((open_list.findNode(neighbor_node)) && (closed_list.find(neighbor) != closed_list.end())) {
					open_list.enqueue(neighbor_node);
				}
			}
		}
	}
	return Node(GridLocation{UNDEFINED,UNDEFINED,UNDEFINED});
}

std::vector<Node> getRoute(Node final_node) {
	std::vector<Node> route;
	route.push_back(final_node);

	Node next = *(final_node.parent);
	while (next != 0) {
		route.push_back(next);
		next = *(next.parent);
	}
	std::reverse(route.begin(), route.end());
	return route;
}
