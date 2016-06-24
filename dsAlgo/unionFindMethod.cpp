#include "headers/graphLinkedListFunctions.cpp"

void unionFindMethod1Function() {
    int numberOfVertices = 3, numberOfEdges = 3;

    graphLinkedListFunctions graphLinkedListFunctions;

    graphConfig *graph = graphLinkedListFunctions.createGraph(numberOfVertices, numberOfEdges);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;

    graph->edge[1].source = 1;
    graph->edge[1].destination = 2;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 2;

    unionFindMethod2 unionFindMethod;

    cout << unionFindMethod.isCyclic(graph);
}

int main() {
    unionFindMethod1Function();
    return 0;
}