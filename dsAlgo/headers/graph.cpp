//
// Created by Gyanesh Mittal on 23/06/16.
//

#include <iostream>
#include <list>
#include "graph.h"

using namespace std;

graph::graph(int v) {
    this->v = v;
    this->adj = new list<int>[v];
}

void graph::addEdge(int sourceVertex, int destinationVertex) {
    if (sourceVertex > this->v || destinationVertex > this->v) {
        cout << "wrong source or destination vertex";
    }
    this->adj[sourceVertex].push_back(destinationVertex);
}

void graph::breadFirstSearch(int startElement) {
    bool *visited = new bool[this->v];
    list<int> queue;
    int i, currentElement;
    list<int>::iterator iterator;

    for (i = 0; i < this->v; i++) {
        visited[i] = false;
    }

    queue.push_back(startElement);
    visited[startElement] = true;

    while (!queue.empty()) {
        currentElement = queue.front();
        queue.pop_front();
        cout << currentElement;

        for (iterator = this->adj[currentElement].begin(); iterator != this->adj[currentElement].end(); iterator++) {
            if (!visited[*iterator]) {
                queue.push_back(*iterator);
                visited[*iterator] = true;
            }
        }
    }

    cout << endl;
}