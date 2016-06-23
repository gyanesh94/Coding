#include "graph.h"

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
        cout << currentElement << " ";

        for (iterator = this->adj[currentElement].begin(); iterator != this->adj[currentElement].end(); iterator++) {
            if (!visited[*iterator]) {
                queue.push_back(*iterator);
                visited[*iterator] = true;
            }
        }
    }
    cout << endl;
}

void graph::depthFirstSearch(int startElement) {
    bool *visited = new bool[this->v];
    stack<int> stack;
    int i, currentElement;
    list<int>::iterator iterator;

    for (i = 0; i < this->v; i++) {
        visited[i] = false;
    }

    stack.push(startElement);
    visited[startElement] = true;

    while (!stack.empty()) {
        currentElement = stack.top();
        stack.pop();
        cout << currentElement << " ";

        for (iterator = this->adj[currentElement].begin(); iterator != this->adj[currentElement].end(); iterator++) {
            if (!visited[*iterator]) {
                stack.push(*iterator);
                visited[*iterator] = true;
            }
        }
    }
    cout << endl;
}

void graph::breadFirstSearchDisconnectedGraph(int startElement) {
    bool *visited = new bool[this->v];
    int i;

    for (i = 0; i < this->v; i++) {
        visited[i] = false;
    }

    for (i = 0; i < this->v; i++) {
        if (!visited[i]) {
            cout << i << " ";
            visited[i] = true;
            breadFirstSearchDisconnectedGraphUtils(i, visited);
        }
    }
    cout << endl;
}

void graph::breadFirstSearchDisconnectedGraphUtils(int node, bool *visited) {

    queue<int> queue;

    for (list<int>::iterator iterator = this->adj[node].begin(); iterator != this->adj[node].end(); iterator++) {
        if (!visited[*iterator]) {
            cout << *iterator << " ";
            visited[*iterator] = true;
            queue.push(*iterator);
        }
    }

    while (!queue.empty()) {
        breadFirstSearchDisconnectedGraphUtils(queue.front(), visited);
        queue.pop();
    }
}

void graph::depthFirstSearchDisconnectedGraph(int startElement) {
    bool *visited = new bool[this->v];
    int i;

    for (i = 0; i < this->v; i++) {
        visited[i] = false;
    }

    for (i = 0; i < this->v; i++) {
        if (!visited[i]) {
            depthFirstSearchDisconnectedGraphUtils(i, visited);
        }
    }
    cout << endl;
}

void graph::depthFirstSearchDisconnectedGraphUtils(int node, bool *visited) {
    cout << node << " ";
    visited[node] = true;

    for (list<int>::iterator iterator = this->adj[node].begin(); iterator != this->adj[node].end(); iterator++) {
        if (!visited[*iterator]) {
            depthFirstSearchDisconnectedGraphUtils(*iterator, visited);
        }
    }
}