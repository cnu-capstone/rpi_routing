/*
 * main.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include <iostream>
#include <string>
#include <queue>
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
	std::priority_queue<std::pair<GridLocation, int>,std::vector<std::pair<GridLocation, int>>,CompareNodes> open_list;
	std::vector<GridLocation> closed_list;

	route.push_back(src);
	open_list.push(std::pair<GridLocation, int>(src, manhattanDistance(src, dest)));

	// g is distance from src
	// h is distance from dest

	GridLocation curr = src;

	// Begin loop

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
