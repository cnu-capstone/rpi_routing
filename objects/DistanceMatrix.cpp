/*
 * DistanceMatrix.cpp
 *
 *  Created on: Oct 23, 2022
 *      Author: potts
 */

#include "../includes/DistanceMatrix.h"

DistanceMatrix::DistanceMatrix(std::string data_set) {
	this->set_size = 0;  // This be a num read from the file
	std::string data;
	this->parse_data(data_set, data, this->set_size);
	// https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/
	this->dist_matrix = new float*[this->set_size];
	for (int i = 0; i<this->set_size;i++) {
		this->dist_matrix[i] = new float[this->set_size];
	}

	// Read data from data_set file and dump
	this->points_list = new EuclideanPoint[this->set_size];
}

DistanceMatrix::~DistanceMatrix() {
	// TODO Auto-generated destructor stub
}


void DistanceMatrix::parse_data(std::string data_file, std::string& data, int& data_set_size) {
	FileIO dio(data_file);  // TODO: Look into closing file after use (Change visibility of close())
	dio.read(data);
	std::stringstream ss(data);
	std::string word;
	std::getline(ss, word, '\n');
	data_set_size = std::stoi(word);
}
