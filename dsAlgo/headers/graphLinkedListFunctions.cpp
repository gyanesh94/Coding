#include "graphLinkedListFunctions.h"

// Graph Linked List Functions

graphConfig *graphLinkedListFunctions::createGraph(int numberOfVertices, int numberOfEdges) {
    graphConfig *graph = new graphConfig();
    graph->v = numberOfVertices;
    graph->e = numberOfEdges;
    graph->edge = new edgeConfig[numberOfEdges];
    return graph;
}



// Union Find Method 1 Functions

int unionFindMethod1::findParent(int *parentList, int vertex) {
    while (parentList[vertex] != -1) {
        vertex = parentList[vertex];
    }
    return vertex;
}

void unionFindMethod1::unionSubset(int *parentList, int source, int destination) {
    int x = findParent(parentList, source);
    int y = findParent(parentList, destination);
    parentList[x] = y;
}

bool unionFindMethod1::isCyclic(graphConfig *graph) {
    int numberOfVertices = graph->v;
    int numberOfEdges = graph->e;
    int source, destination, sourceParent, destinationParent, i;

    int *parentList = new int[numberOfVertices];

    for (i = 0; i < numberOfVertices; i++) {
        parentList[i] = -1;
    }

    for (i = 0; i < numberOfEdges; i++) {
        source = graph->edge[i].source;
        destination = graph->edge[i].destination;

        sourceParent = findParent(parentList, source);
        destinationParent = findParent(parentList, destination);

        if (sourceParent == destinationParent) {
            return true;
        }

        unionSubset(parentList, sourceParent, destinationParent);
    }
    return false;
}




// Union Find Method 2 Functions

int unionFindMethod2::findParent(subset *parentSubset, int vertex) {
    // find root and make root as parent of vertex (path compression) so that it is easy to find next time
    if (parentSubset[vertex].parent != vertex) {
        parentSubset[vertex].parent = findParent(parentSubset, parentSubset[vertex].parent);
    }
    return parentSubset[vertex].parent;
}

void unionFindMethod2::unionSubset(subset *parentSubset, int source, int destination) {
    int x = findParent(parentSubset, source);
    int y = findParent(parentSubset, destination);

    /*
        Attach smaller rank tree under root of high rank tree
        (Union by Rank)
        If ranks are same, then make one as root and increment
        its rank by one
     */
    if (parentSubset[x].rank > parentSubset[y].rank) {
        parentSubset[y].parent = x;
    } else if (parentSubset[y].rank > parentSubset[x].rank) {
        parentSubset[x].parent = y;
    } else {
        parentSubset[x].parent = y;
        parentSubset[x].rank++;
    }
}

bool unionFindMethod2::isCyclic(graphConfig *graph) {
    int numberOfVertices = graph->v;
    int numberOfEdges = graph->e;
    int source, destination, sourceParent, destinationParent, i;

    subset *parentSubset = new subset[numberOfVertices];

    for (i = 0; i < numberOfVertices; i++) {
        parentSubset[i].parent = i;
        parentSubset[i].rank = 0;
    }

    for (i = 0; i < numberOfEdges; i++) {
        source = graph->edge[i].source;
        destination = graph->edge[i].destination;

        sourceParent = findParent(parentSubset, source);
        destinationParent = findParent(parentSubset, destination);

        if (sourceParent == destinationParent) {
            return true;
        }

        unionSubset(parentSubset, sourceParent, destinationParent);
    }
    return false;
}