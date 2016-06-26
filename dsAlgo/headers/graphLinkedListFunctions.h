#ifndef DSALGO_GRAPHLINKEDLIST_H
#define DSALGO_GRAPHLINKEDLIST_H

#include <iostream>

using namespace std;

typedef struct edgeConfig {
    int source, destination;
    double weight;
} edgeConfig;

typedef struct graphConfig {
    int v, e;     // V-> Number of vertices, E-> Number of edges
    struct edgeConfig *edge;   // graph is represented as an array of edges
} graphConfig;


class graphLinkedListFunctions {
public:
    graphConfig *createGraph(int numberOfVertices, int numberOfEdges);
};


/*
    Union Find Method (Detect Cycle in a an Undirected Graph)

    Method - 1

        A disjoint-set data structure is a data structure that keeps track of a set of
        elements partitioned into a number of disjoint (non-overlapping) subsets.
        A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

        Find: Determine which subset a particular element is in. This can be used for
        determining if two elements are in the same subset.

        Union: Join two subsets into a single subset.

        In this post, we will discuss an application of Disjoint Set Data Structure. The application
        is to check whether a given graph contains a cycle or not.

        Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not.\
        Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find.
        This method assumes that graph doesn’t contain any self-loops.

        We can keeps track of the subsets in a 1D array, lets call it parent[].

        Let us consider the following graph:

                0
                |  \
                |    \
                1-----2
        For each edge, make subsets using both the vertices of the edge. If both the vertices
        are in the same subset, a cycle is found.

        Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

        0   1   2
        -1 -1  -1
        Now process all edges one by one.

        Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the
        union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa.

        0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
        1  -1  -1
        Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

        0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
        1   2  -1
        Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.

        How subset of 0 is same as 2?
        0->1->2 // 1 is parent of 0 and 2 is parent of 1

        Note that the implementation of union() and find() is naive and takes O(n) time in worst case.
 */

class unionFindMethod1 {
    int findParent(int *parentList, int vertex);

    void unionSubset(int *parentList, int source, int destination);

public:
    bool isCyclic(graphConfig *graph);
};


/*
    Union Find Method (Detect Cycle in a an Undirected Graph)

    Method - 2

        The above operations can be optimized to O(Log n) in worst case.
        The idea is to always attach smaller depth tree under the root of the deeper tree.
        This technique is called union by rank. The term rank is preferred instead of height because
        if path compression technique (we have discussed it below) is used, then rank is not always
        equal to height. Also, size (in place of height) of trees can also be used as rank.
        Using size as rank also yields worst case time complexity as O(Logn) (See this for prrof)

        Let us see the above example with union by rank
        Initially all elements are single element subsets.
        0 1 2 3

        Do Union(0, 1)
           1   2   3
          /
         0

        Do Union(1, 2)
           1    3
         /  \
        0    2

        Do Union(2, 3)
            1
         /  |  \
        0   2   3
        The second optimization to naive method is Path Compression.
        The idea is to flatten the tree when find() is called. When find() is called
        for an element x, root of the tree is returned. The find() operation traverses up
        from x to find root. The idea of path compression is to make the found root as
        parent of x so that we don’t have to traverse all intermediate nodes again. If x is root
        of a subtree, then path (to root) from all nodes under x also compresses.


        Let the subset {0, 1, .. 9} be represented as below and find() is called
        for element 3.
                      9
                 /    |    \
                4     5      6
             /     \        /  \
            0        3     7    8
                    /  \
                   1    2

        When find() is called for 3, we traverse up and find 9 as representative
        of this subset. With path compression, we also make 3 as child of 9 so
        that when find() is called next time for 1, 2 or 3, the path to root is
        reduced.

                       9
                 /    /  \    \
                4    5    6     3
             /           /  \   /  \
            0           7    8  1   2

        The two techniques complement each other. The time complexity of each operations
        becomes even smaller than O(Logn). In fact, amortized time complexity effectively becomes small constant.
 */

typedef struct subset {
    int parent;
    int rank;       // Represents depth of tree. It is incremented only when two trees are on same height.
} subset;

class unionFindMethod2 {
public:
    int findParent(subset *parentSubset, int vertex);

    void unionSubset(subset *parentSubset, int source, int destination);

    bool isCyclic(graphConfig *graph);
};


/*
    Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)

        What is Minimum Spanning Tree?
        Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects
        all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST)
        or minimum weight spanning tree for a weighted, connected and undirected graph is a spanning tree with weight
        less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of
        weights given to each edge of the spanning tree.

        How many edges does a minimum spanning tree has?
        A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.

        What are the applications of Minimum Spanning Tree?
        See this for applications of MST.

        Below are the steps for finding MST using Kruskal’s algorithm

        1. Sort all the edges in non-decreasing order of their weight.

        2. Pick the smallest edge. Check if it forms a cycle with the spanning tree
        formed so far. If cycle is not formed, include this edge. Else, discard it.

        3. Repeat step#2 until there are (V-1) edges in the spanning tree.


        Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through
            all edges and apply find-union algorithm. The find and union operations can take atmost O(LogV) time.
            So overall complexity is O(ELogE + ELogV) time. The value of E can be atmost V^2, so O(LogV) are O(LogE)
            same. Therefore, overall time complexity is O(ElogE) or O(ElogV)
*/


class minimumSpanningTree {
    graphConfig *sortEdges(graphConfig *graph);

public:
    void kruskalMinimumSpanningTree(graphConfig *graph);
};

/*      Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))

        We have discussed Kruskal’s algorithm for Minimum Spanning Tree. Like Kruskal’s algorithm, Prim’s algorithm
        is also a Greedy algorithm. It starts with an empty spanning tree. The idea is to maintain two sets of vertices.
        The first set contains the vertices already included in the MST, the other set contains the vertices not yet
        included. At every step, it considers all the edges that connect the two sets, and picks the minimum weight edge
        from these edges. After picking the edge, it moves the other endpoint of the edge to the set containing MST.

        A group of edges that connects two set of vertices in a graph is called cut in graph theory. So, at every step
        of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other
        contains rest of the verices), pick the minimum weight edge from the cut and include this vertex to MST Set
        (the set that contains already included vertices).

        How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree means all vertices
        must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a
        Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

        Algorithm
        1) Create a set mstSet that keeps track of vertices already included in MST.
        2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign
        key value as 0 for the first vertex so that it is picked first.
        3) While mstSet doesn’t include all vertices
        ….a) Pick a vertex u which is not there in mstSet and has minimum key value.
        ….b) Include u to mstSet.
        ….c) Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent
        vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update
        the key value as weight of u-v

        Time Complexity of the above program is O(V^2). If the input graph is represented using adjacency list,
        then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap.
        Please see Prim’s MST for Adjacency List Representation for more details
 */

class primMinimumSpanningTree {
    int V;
    int **graph;

    // A utility function to find the vertex with minimum key value, from
    // the set of vertices not yet included in MST
    int minKey(int *key, bool *mstSet);

    // A utility function to print the constructed MST stored in parent[]
    void printMST(int *parent, int n);
public:
    primMinimumSpanningTree(int V);

    // Function to construct and print MST for a graph represented using adjacency
    // matrix representation
    void primMST();
};

#endif //DSALGO_GRAPHLINKEDLIST_H
