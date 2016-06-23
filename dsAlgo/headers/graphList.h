#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include <list>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class graphList {
    int v;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists

    void breadFirstSearchDisconnectedGraphUtils(int node, bool *visited);
    void depthFirstSearchDisconnectedGraphUtils(int node, bool *visited);
public:
    graphList(int v);  // Constructor
    void addEdge(int sourceVertex, int destinationVertex); // function to add an edge to graphList

    /*
        Breadth And Depth First Search
        Time Complexity: O(V+E) where V is number of vertices in the graphList and E is number of edges in the graphList.
            Complexity is either E or V
            Because outer loop is like table to maintain and access location of the node
        prints BFS and DFS traversal from a given source s
    */
    void breadFirstSearch(int startElement);
    void depthFirstSearch(int startElement);

    void breadFirstSearchDisconnectedGraph(int startElement);
    void depthFirstSearchDisconnectedGraph(int startElement);
};


#endif //DSALGO_GRAPH_H
