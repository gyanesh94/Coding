/*
    0 --> 1 --> 2 --> 4         6 --> 7
         / \   /                \    /
        /   \ /                  \  /
       5     3                    8 --> 9
*/
#include "headers/graphList.cpp"

void graphListTraversal() {
    int totalGraphElements, startElement;
    totalGraphElements = 10;
    graphList graph(totalGraphElements);

    graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(6, 7);
    graph.addEdge(6, 8);
    graph.addEdge(7, 8);
    graph.addEdge(8, 9);

    startElement = 0;

    graph.breadFirstSearchDisconnectedGraph(startElement);
}

int main() {
    graphListTraversal();
    return 0;
}