/*
 * main.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include <iostream>
#include <string>
#include "../includes/Grid.h"

using namespace std;

int main() {
	string file = "data/grid_data.txt";
	Grid grid(file);
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
