/*
       1. Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)

       Example
               10
            0--------1
            |  \     |
           6|   5\   |15
            |      \ |
            2--------3
                 4

        2. Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))

        Example

             2    3
          (0)--(1)--(2)
           |   / \   |
          6| 8/   \5 |7
           | /     \ |
          (3)-------(4)
                9
 */

#include "headers/graphLinkedListFunctions.cpp"

graphConfig *createGraph();

void primAlgo();

void kruskalAlgo();

int main() {
    primAlgo();
    return 0;
}


graphConfig *createGraph() {
    int numberOfVertices = 4, numberOfEdges = 5;

    graphLinkedListFunctions graphLinkedListFunctions;

    graphConfig *graph = graphLinkedListFunctions.createGraph(numberOfVertices, numberOfEdges);

// add edge 0-1
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 10;

// add edge 0-2
    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 6;

// add edge 0-3
    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 5;

// add edge 1-3
    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 15;

// add edge 2-3
    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 4;

    return graph;
}

void kruskalAlgo() {
    graphConfig *graph = createGraph();
    minimumSpanningTree minimumSpanningTree;
    minimumSpanningTree.kruskalMinimumSpanningTree(graph);
};

void primAlgo() {
    primMinimumSpanningTree primMinimumSpanningTree(5);
    primMinimumSpanningTree.primMST();

}