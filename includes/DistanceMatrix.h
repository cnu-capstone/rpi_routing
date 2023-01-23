/*
 * DistanceMatrix.h
 *
 *  Created on: Oct 23, 2022
 *      Author: potts
 */

#ifndef DISTANCEMATRIX_H_
#define DISTANCEMATRIX_H_
#include <string>
#include <sstream>
#include <math.h>
#include <cmath>
#include "EuclideanPoint.h"
#include "FileIO.h"

class DistanceMatrix {
public:
	DistanceMatrix(std::string data_set);
	virtual ~DistanceMatrix();
	float** getDistanceMatrix();
	float getDistanceBetweenPoints(int p1, int p2);
	EuclideanPoint* getListOfPoints();
private:
	int set_size;
	float **dist_matrix;
	EuclideanPoint *points_list;
	void parse_data(std::string data_file, std::string& data, int& data_set_size);
};

#endif /* DISTANCEMATRIX_H_ */
