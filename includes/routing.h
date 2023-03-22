/*
 * routing.h
 *
 *  Created on: Mar 12, 2023
 *      Author: potts
 */

#ifndef INCLUDES_ROUTING_H_
#define INCLUDES_ROUTING_H_

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <float.h>
#include "DistanceMatrix.h"

//#define INF INT_MAX
#define INF FLT_MAX

// A class to represent a graph node
class Node {
public:
    int id, dist;
    Node(int id, int dist);
};

// A comparison class to be used in priority queue
class CompareNodes {
public:
    bool operator() (const Node& node1, const Node& node2) {
        return node1.dist > node2.dist;
    }
};

//int* nearest_neighbor(DistanceMatrix &matrix);

//int* dijkstra

std::vector<float> dijkstra(float **graph, int N, int src);

void printShortestPath(float **graph, int N, int src, int dest);



#endif /* INCLUDES_ROUTING_H_ */
