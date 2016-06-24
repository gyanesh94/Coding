#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include <list>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

enum Color {WHITE, GRAY, BLACK};

class graphList {
    int v;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists

    void breadFirstSearchDisconnectedGraphUtils(int node, bool *visited);
    void depthFirstSearchDisconnectedGraphUtils(int node, bool *visited);
    bool detectCycleInAGraphUtils(int node, bool *visited, bool *recursion);
    bool detectCycleInAGraphUsingColorsUtils(int node, Color *color);
public:
    graphList(int v);  // Constructor
    void addEdge(int sourceVertex, int destinationVertex); // function to add an edgeConfig to graphList

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

    /*
        Detect Cycle in a Directed Graph

        Method 1

        Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graphConfig produces a tree.
        There is a cycle in a graphConfig only if there is a back edgeConfig present in the graphConfig.
        A back edgeConfig is an edgeConfig that is from a node to itself (selfloop) or one of its ancestor in the tree produced by DFS.
        In the following graphConfig, there are 3 back edges, marked with cross sign. We can observe that these 3 back edges
        indicate 3 cycles present in the graphConfig.

        Rec array is used to store whether the status of traversal of the node

        To detect a back edgeConfig, we can keep track of vertices currently in recursion stack of function for DFS traversal.
        If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree.
        The edgeConfig that connects current vertex to the vertex in the recursion stack is back edgeConfig.
        We have used recStack[] array to keep track of vertices in the recursion stack.

        Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).

        For undirected graph no need of recursion stack
        If we reach visited node again than it contains cycle
    */

    bool detectCycleInAGraph(int startElement);

    /*
        Detect Cycle in a Directed Graph

        Method 1

        WHITE : Vertex is not processed yet.  Initially
                all vertices are WHITE.

        GRAY : Vertex is being processed (DFS for this
               vertex has started, but not finished which means
               that all descendants (ind DFS tree) of this vertex
               are not processed yet (or this vertex is in function
               call stack)

        BLACK : Vertex and all its descendants are
                processed.

        While doing DFS, if we encounter an edgeConfig from current
        vertex to a GRAY vertex, then this edgeConfig is back edgeConfig
        and hence there is a cycle.

        Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).

        For undirected graph only two colors are required one for unprocessed other for processed
        If we reach processed node again than it contains cycle
     */
    bool detectCycleInAGraphUsingColors(int startElement);
};


#endif //DSALGO_GRAPH_H
