/*
 * Grid.h
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#ifndef INCLUDES_GRID_H_
#define INCLUDES_GRID_H_

#include <string>
#include <sstream>
#include <vector>
#include "FileIO.h"
#include "constants.h"

struct GridLocation {
	int id, x, y;
};

class Grid {
public:
	Grid(std::string data_set);
	virtual ~Grid();
	std::vector<GridLocation> getNeighbors(int gridLocationID);
	std::vector<GridLocation> getLocations();
private:
	int width;
	int height;
	std::vector<GridLocation> locations;
	std::vector<std::pair<GridLocation, std::vector<GridLocation>>> adjacency_matrix;
	bool in_bounds(GridLocation suspectLoc);
	void parse_data(std::string data_file, std::string& data);
};


#endif /* INCLUDES_GRID_H_ */
