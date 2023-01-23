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
	EuclideanPoint* list = dm.getListOfPoints();
	for (int i = 0; i<100; i++) {
		cout<<(list[i]).getPointID();
		cout<<endl;
	}
}
