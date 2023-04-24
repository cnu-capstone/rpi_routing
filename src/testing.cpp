/*
 * testing.cpp
 *
 *  Created on: Jan 20, 2023
 *      Author: potts
 */

#include <bitset>
#include <iostream>
#include <string>
#include "../includes/Grid.h"
#include "../includes/routing.h"
#include "../includes/uart_comm.h"
#include "../includes/motor_driver.h"

using namespace std;

// Comment out main function in main.cpp to utilize this main for testing
// ("temporary solution" lol)

//int main() {
//	string file = "data/lutr300_map.txt";
//	Grid grid(file);
//	//  Displays locations and list of neighbors
//	//	for (GridLocation loc : grid.getLocations()) {
//	//		cout<<loc.id<<" "<<loc.x<<" "<<loc.y<<" ";
//	//		cout<<"Neighbors: ";
//	//		for (GridLocation neighbor : grid.getNeighbors(loc.id)) {
//	//			cout<<neighbor.id<<" ";
//	//		}
//	//		cout<<endl;
//	//	}
//
//	// {100, 3, 0}
//	// {891, 26, 32}
//
//	vector<Node> route = getRoute(AStar(grid, {1,0,0}, {891, 26, 32}));
//
//	for (Node node : route) {
//		std::cout<<node.loc.id<<" ";
//	}
//	std::cout<<std::endl;
//
//	instruction_block instructions = route_to_instructions(EAST, route);
//
//	for (std::bitset<INSTRUCTION_SIZE> instr : instructions) {
//		string bit_string = instr.to_string();
//		cout<<bit_string<<endl;
//	}
//
//	return 0;
//}
