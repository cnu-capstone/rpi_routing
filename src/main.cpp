/*
 * main.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include <iostream>
#include <string>
#include "../includes/Grid.h"
#include "../includes/routing.h"

using namespace std;

int main() {
	string file = "data/grid_data.txt";
	Grid grid(file);
	// Displays locations and list of neighbors
//	for (GridLocation loc : grid.getLocations()) {
//		cout<<loc.id<<" "<<loc.x<<" "<<loc.y<<" ";
//		cout<<"Neighbors: ";
//		for (GridLocation neighbor : grid.getNeighbors(loc.id)) {
//			cout<<neighbor.id<<" ";
//		}
//		cout<<endl;
//	}

	for (Node node : getRoute(AStar(grid, {1,0,0}, {100,9,9}))) {
		std::cout<<node.loc.id<<" ";
	}
	std::cout<<std::endl;

	return 0;
}
