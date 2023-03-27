/*
 * main.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include "../includes/Grid.h"

int manhattanDistance(GridLocation src, GridLocation target) {
	return abs(src.x - target.x) + abs(src.y - target.y);
}

//bool compareNodes(const std::pair<GridLocation, int>& loc1, const std::pair<GridLocation, int>& loc2) {
//        return loc1.second < loc2.second;
//}

class CompareNodes {
public:
	bool operator() (const std::pair<GridLocation, int>& loc1, const std::pair<GridLocation, int>& loc2) const {
		  return loc1.second < loc2.second;
	}
};

std::vector<GridLocation> AStar(Grid &graph, GridLocation src, GridLocation dest) {
	std::vector<GridLocation> route;
	std::priority_queue<std::pair<GridLocation, int>,std::vector<std::pair<GridLocation, int>>,CompareNodes> open_queue;
	// Queue doesn't allow searching so adding an unordered set for lookup
	std::unordered_set<GridLocation,GridLocationHasher,GridLocationEqual> queued;
//	std::vector<GridLocation> closed_list;
	std::unordered_set<GridLocation,GridLocationHasher,GridLocationEqual> closed_list;

	route.push_back(src);
	open_queue.push(std::pair<GridLocation, int>(src, manhattanDistance(src, dest)));

	// g is distance from src
	// h is distance from dest

	GridLocation curr = src;

	// Begin loop
	while (curr.id != dest.id) { // Change to run until queue is empty
		std::pair<GridLocation, int> target = open_queue.top(); open_queue.pop();
		if (target.first.id == dest.id) {
			route.push_back(target.first);
			break;
		}
		else {
			curr = target.first;
//			closed_list.push_back(curr);
			closed_list.insert(curr);
//			int curr_g = manhattanDistance(src, curr);
			int curr_f = target.second;
			for (GridLocation neighbor : graph.getNeighbors(curr.id)) {
				// Find lowest f and add to open_list
				if (closed_list.find(neighbor) != closed_list.end()) { // Neighbor has already been checked
					continue;
				}
				int neighbor_g = manhattanDistance(src, neighbor);
				int neighbor_h = manhattanDistance(neighbor, dest);
				open_queue.push(std::pair<GridLocation, int>(neighbor,neighbor_g+neighbor_h));
//				if ((neighbor_g < curr_g) && (closed_list.find(neighbor) != closed_list.end())) {
//
//				}
//				else if ((curr_g < neighbor_g) && ())
			}
		}
	}
	return route;
}

using namespace std;

int main() {
	string file = "data/grid_data.txt";
	Grid grid(file);
	// Displays locations and list of neighbors
	for (GridLocation loc : grid.getLocations()) {
		cout<<loc.id<<" "<<loc.x<<" "<<loc.y<<" ";
		cout<<"Neighbors: ";
		for (GridLocation neighbor : grid.getNeighbors(loc.id)) {
			cout<<neighbor.id<<" ";
		}
		cout<<endl;
	}

	return 0;
}
