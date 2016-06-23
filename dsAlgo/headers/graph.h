#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include <list>
#include <stack>
#include <iostream>

using namespace std;

class graph {
    int v;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists

public:
    graph(int v);  // Constructor
    void addEdge(int sourceVertex, int destinationVertex); // function to add an edge to graph

    /*
        Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.
            Complexity is either E or V
            Because outer loop is like table to maintain and access location of the node
        prints BFS traversal from a given source s
    */
    void breadFirstSearch(int startElement);

    void depthFirstSearch(int startElement);
};


#endif //DSALGO_GRAPH_H
