/*
 * Grid.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#include "../includes/Grid.h"

Grid::Grid(std::string data_set) {
	this->width = 0;  // This be a num read from the file
	this->height = 0;
	std::string data;
	this->parse_data(data_set, data);

	std::vector<GridLocation> locations = this->getLocations();

	for (std::pair<GridLocation, std::vector<GridLocation>> Pair : this->adjacency_matrix) {
		for (GridLocation neighbor : Pair.second) {
			if (neighbor.x == UNDEFINED || neighbor.y == UNDEFINED) {
				for (GridLocation loc : locations) {
					if (neighbor.id == loc.id) {
						neighbor.x = loc.x;
						neighbor.y = loc.y;
					}
				}
			}
		}
	}
}

Grid::~Grid() {}

std::vector<GridLocation> Grid::getNeighbors(int gridLocationID)  {
	for (std::pair<GridLocation, std::vector<GridLocation>> pair : this->adjacency_matrix) {
		if (pair.first.id == gridLocationID) {
			return pair.second;
		}
	}
	return std::vector<GridLocation>{GridLocation{UNDEFINED,UNDEFINED,UNDEFINED}};
}

std::vector<GridLocation> Grid::getLocations() {
	std::vector<GridLocation> locations;
	for (std::pair<GridLocation, std::vector<GridLocation>> pair : this->adjacency_matrix) {
		locations.push_back(pair.first);
	}
	return locations;
}

bool Grid::in_bounds(GridLocation suspectLoc) {
	return (0 <= suspectLoc.x && suspectLoc.x < this->width) && (0 <= suspectLoc.y && suspectLoc.y < this->height);
}

void Grid::parse_data(std::string data_file, std::string& data) {
	FileIO dio(data_file);  // TODO: Look into closing file after use (Change visibility of close())
	dio.read(data);
	std::stringstream ss(data);
	std::string word;
	std::getline(ss, word, 'x');
	this->width = std::stoi(word);
	std::getline(ss, word, '\n');
	this->height = std::stoi(word);

	while (!ss.eof()) {
		std::getline(ss, word, '\n');
		if (word.compare("") == 0) {
			break;
		}
		std::stringstream word_ss(word);
		std::string param;
		std::getline(word_ss, param, '\t');
		int id = std::stoi(param);
		std::getline(word_ss, param, '\t');
		int x = std::stoi(param);
		std::getline(word_ss, param, '\t');
		int y = std::stoi(param);

		GridLocation curr{id,x,y};
		this->locations.push_back(curr);

		std::vector<GridLocation> neighbors;

		while (!word_ss.eof()) {
			std::getline(word_ss, param, ',');
			if (param.compare("") == 0) {
				break;
			}
			int nid = std::stoi(param);
			neighbors.push_back(GridLocation{nid,UNDEFINED,UNDEFINED});
		}

		this->adjacency_matrix.push_back(std::pair<GridLocation, std::vector<GridLocation>>(curr, neighbors));
	}
}
