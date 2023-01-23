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
	// Read data from data_set file and dump
//	this->points_list = new EuclideanPoint[this->set_size];
//	for (int i = 0; i<this->set_size; i++) {
//		this->points_list[i] = EuclideanPoint();
//	}
	// https://www.geeksforgeeks.org/how-to-declare-a-2d-array-dynamically-in-c-using-new-operator/
	this->dist_matrix = new float*[this->set_size];
	for (int i = 0; i<this->set_size; i++) {
		this->dist_matrix[i] = new float[this->set_size];
	}
}

DistanceMatrix::~DistanceMatrix() {
	// TODO Auto-generated destructor stub
}

float** DistanceMatrix::getDistanceMatrix(){
	return this->dist_matrix;
}

EuclideanPoint* DistanceMatrix::getListOfPoints() {
	return this->points_list;
}

void DistanceMatrix::parse_data(std::string data_file, std::string& data, int& data_set_size) {
	FileIO dio(data_file);  // TODO: Look into closing file after use (Change visibility of close())
	dio.read(data);
	std::stringstream ss(data);
	std::string word;
	std::getline(ss, word, '\n');
	data_set_size = std::stoi(word);
	this->points_list = new EuclideanPoint[this->set_size];
	// Populate points_list as well
	for (int i = 0; i<this->set_size; i++) {  // TODO: Not great, improve...
//	while (!ss.eof()) {
		std::getline(ss, word, '\n');
		std::stringstream word_ss(word);
		std::string param;
		std::getline(word_ss, param, '\t');
		int id = std::stoi(param);
		std::getline(word_ss, param, '\t');
		int x = std::stoi(param);
		std::getline(word_ss, param, '\t');
		int y= std::stoi(param);
		this->points_list[i] = EuclideanPoint(id, x, y);
	}
}

float calculateEuclideanDistance(int x1, int y1, int x2, int y2) {
	int x_delta = x2 - x1;
	int y_delta = y2 - y1;
	return std::sqrt(std::pow(x_delta, 2) + std::pow(y_delta, 2));
}
