///*
// * routing.cpp
// *
// *  Created on: Mar 12, 2023
// *      Author: potts
// */
//
//#include "../includes/routing.h"
//
//using namespace std;
//
//Node::Node(int id, int dist) : id(id), dist(dist) {}
//
//// Dijkstra's algorithm to find shortest path from a source node to all nodes
//vector<float> dijkstra(float **graph, int N, int src) {
//    // Create a vector to store distances from the source node to all other nodes
//    vector<float> dist(N, INF);
//    // Create a priority queue to store nodes in increasing order of their distances from the source node
//    priority_queue<Node, vector<Node>, CompareNodes> pq;
//
//    // Set the distance of the source node to zero and add it to the priority queue
//    dist[src] = 0;
//    pq.push(Node(src, 0));
//
//    // Process all nodes in the priority queue
//    while (!pq.empty()) {
//        // Get the node with the smallest distance from the priority queue
//        Node node = pq.top();
//        pq.pop();
//
//        // Update the distances of all adjacent nodes
//        for (int i = 0; i < N; i++) {
//            if (graph[node.id][i] != 0 && dist[node.id] + graph[node.id][i] < dist[i]) {
//                dist[i] = dist[node.id] + graph[node.id][i];
//                pq.push(Node(i, dist[i]));
//            }
//        }
//    }
//
//    return dist;
//}
//
//// A function to print the shortest path from the source node to a destination node
//void printShortestPath(float **graph, int N, int src, int dest) {
//    vector<float> dist = dijkstra(graph, N, src);
//    // Check if there is a path from the source node to the destination node
//    if (dist[dest] == INF) {
//        cout << "No path from " << src << " to " << dest << endl;
//        return;
//    }
//    // Create a vector to store the path from the source node to the destination node
//    vector<int> path;
//    int curr = dest;
//    while (curr != src) {
//        path.push_back(curr);
//        for (int i = 0; i < N; i++) {
//            if (graph[i][curr] != 0 && dist[curr] == dist[i] + graph[i][curr]) {
//                curr = i;
//                break;
//            }
//        }
//    }
//    path.push_back(src);
//    // Reverse the path vector to get the path from the source to the destination
//    reverse(path.begin(), path.end());
//    // Print the path
//    cout << "Shortest path from " << src << " to " << dest << " is: ";
//    for (int i = 0; i < path.size(); i++) {
//        cout << path[i] << " ";
//    }
//    cout << endl;
//}
//
//// An example usage of the functions
////int main() {
////    int N = 5;
////    int **graph = new int*[N];
////    for (int i = 0; i < N; i++) {
////        graph[i] = new int[N];
////        for (int j = 0; j < N; j++) {
////            graph[i][j] = 0;
////        }
////    }
////    graph[0][1] = 2;
////    graph[0][2] = 4;
////    graph[1][2] = 1;
////    graph[1][3] = 7;
////    graph[2][3] = 3;
////    graph[3][4] = 2;
////
////    int src = 0;
////    int dest = 4;
////
////    printShortestPath(graph, N, src, dest);
////
////    for (int i = 0; i < N; i++) {
////        delete[] graph[i];
////    }
////    delete[] graph;
////
////    return 0;
////}
//
