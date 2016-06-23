#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include <list>

using namespace std;

class graph {
    int v;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists

public:
    graph(int v);  // Constructor
    void addEdge(int sourceVertex, int destinationVertex); // function to add an edge to graph
    void breadFirstSearch(int startElement);  // prints BFS traversal from a given source s
};


#endif //DSALGO_GRAPH_H
