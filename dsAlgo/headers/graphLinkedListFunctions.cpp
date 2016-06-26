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




// Minimum Spanning Tree

void merge(edgeConfig *edge, int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    edgeConfig edgeTemp[r + 1];
    while (i <= mid && j <= r) {
        if (edge[i].weight < edge[j].weight) {
            edgeTemp[k] = edge[i];
            i++;
            k++;
        } else {
            edgeTemp[k] = edge[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        edgeTemp[k] = edge[i];
        i++;
        k++;
    }
    while (j <= r) {
        edgeTemp[k] = edge[j];
        j++;
        k++;
    }

    for (i = l; i <= r; i++) {
        edge[i] = edgeTemp[i];
    }
}

void mergeSort(edgeConfig *edge, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(edge, l, mid);
        mergeSort(edge, mid + 1, r);
        merge(edge, l, mid, r);
    }
}

graphConfig *minimumSpanningTree::sortEdges(graphConfig *graph) {
    mergeSort(graph->edge, 0, graph->e - 1);
    return graph;
}

void minimumSpanningTree::kruskalMinimumSpanningTree(graphConfig *graph) {
    sortEdges(graph);
    unionFindMethod2 unionFindMethod;

    int i, numberOfVertices = graph->v;

    subset *parentSubset = new subset[numberOfVertices];

    for (i = 0; i < numberOfVertices; i++) {
        parentSubset[i].parent = i;
        parentSubset[i].rank = 0;
    }

    for (i = 0; i < graph->e; i++) {
        int source = graph->edge[i].source;
        int destination = graph->edge[i].destination;
        double weight = graph->edge[i].weight;

        int sourceParent = unionFindMethod.findParent(parentSubset, source);
        int destinationParent = unionFindMethod.findParent(parentSubset, destination);

        if (sourceParent == destinationParent) {
            continue;
        }

        unionFindMethod.unionSubset(parentSubset, sourceParent, destinationParent);

        cout << source << " --> " << destination << " === " << weight << endl;
    }
}



// Prim's Minimum Spanning Tree

primMinimumSpanningTree::primMinimumSpanningTree(int V) {
    this->V = V;
    this->graph = new int *[V];
    int i, j;

    for (i = 0; i < V; ++i) {
        this->graph[i] = new int[V];
    }

    #define tempV 5
    int graph[tempV][tempV] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0},
    };
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            this->graph[i][j] = graph[i][j];
        }
    }
}

int primMinimumSpanningTree::minKey(int *key, bool *mstSet) {
    // Initialize min value
    int min = INT_MAX, min_index = 0;

    for (int v = 0; v < this->V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMinimumSpanningTree::printMST(int *parent, int n) {
    printf("Edge   Weight\n");
    for (int i = 1; i < this->V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMinimumSpanningTree::primMST(){
    int parent[V]; // Array to store constructed MST
    int key[V];   // Key values used to pick minimum weight edge in cut
    bool mstSet[V];  // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    printMST(parent, V);
}