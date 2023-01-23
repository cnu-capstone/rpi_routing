/*
 * testing.cpp
 *
 *  Created on: Jan 20, 2023
 *      Author: potts
 */

#include <iostream>
#include <string>
#include "../includes/DistanceMatrix.h"

using namespace std;

int main() {
	string file = "data/test.txt";
	DistanceMatrix dm(file);

	// DistanceMatrix Testing
//	float** distance_matrix = dm.getDistanceMatrix();
//	for (int i = 0; i<dm.getSetSize(); i++) {
//		for (int j = 0; j<dm.getSetSize(); j++) {
//			cout<<distance_matrix[i][j]<<"\t";
//		}
//		cout<<endl;
//	}

	// Points List Testing
//	EuclideanPoint* list = dm.getListOfPoints();
//	for (int i = 0; i<100; i++) {
//		cout<<(list[i]).getPointID();
//		cout<<endl;
//	}
}
