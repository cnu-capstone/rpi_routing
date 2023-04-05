/*
 * routing.cpp
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#include "../includes/routing.h"

Node AStar(Grid &graph, GridLocation src, GridLocation dest) {
	NodeQueue open_list;
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

				if ((open_list.findNode(neighbor_node)) && (curr_to_neighbor_cost < open_list.getNodeCost(neighbor_node))) {
					open_list.replaceNode(neighbor_node);
				}
				if ((closed_list.find(neighbor) != closed_list.end()) && (curr_to_neighbor_cost < closed_list.find(neighbor)->second)) {
					closed_list.erase(neighbor);
				}
				if ((!open_list.findNode(neighbor_node)) && (closed_list.find(neighbor) == closed_list.end())) {
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

	std::shared_ptr<Node> next = std::move(final_node.parent);
	while (next) {
		route.push_back(*next);
		next = std::move(next->parent);
	}
	std::reverse(route.begin(), route.end());
	return route;
}
