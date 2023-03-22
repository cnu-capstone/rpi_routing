/*
 * boundary.h
 *
 *  Created on: Mar 13, 2023
 *      Author: potts
 */

#ifndef INCLUDES_BOUNDARY_H_
#define INCLUDES_BOUNDARY_H_

#include <vector>

class Boundary {
public:
	Boundary(int x1, int x2, int y1, int y2);
	std::vector<int> getXRange();
	std::vector<int> getYRange();

};



#endif /* INCLUDES_BOUNDARY_H_ */
