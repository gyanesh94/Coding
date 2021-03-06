#include "graphList.h"

graphList::graphList(int v) {
    this->v = v;
    this->adj = new list<int>[v];
}

void graphList::addEdge(int sourceVertex, int destinationVertex) {
    if (sourceVertex > this->v || destinationVertex > this->v) {
        cout << "wrong source or destination vertex";
    }
    this->adj[sourceVertex].push_back(destinationVertex);
}

void graphList::breadFirstSearch(int startElement) {
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

void graphList::depthFirstSearch(int startElement) {
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

void graphList::breadFirstSearchDisconnectedGraph(int startElement) {
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

void graphList::breadFirstSearchDisconnectedGraphUtils(int node, bool *visited) {

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

void graphList::depthFirstSearchDisconnectedGraph(int startElement) {
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

void graphList::depthFirstSearchDisconnectedGraphUtils(int node, bool *visited) {
    cout << node << " ";
    visited[node] = true;

    for (list<int>::iterator iterator = this->adj[node].begin(); iterator != this->adj[node].end(); iterator++) {
        if (!visited[*iterator]) {
            depthFirstSearchDisconnectedGraphUtils(*iterator, visited);
        }
    }
}

bool graphList::detectCycleInAGraph(int startElement) {
    bool *visited = new bool[this->v];
    bool *recursion = new bool[this->v];
    int i;

    for (i = 0; i < this->v; i++) {
        visited[i] = false;
        recursion[i] = false;
    }

    for (i = 0; i < this->v; i++) {
        if (!visited[i]) {
            if (detectCycleInAGraphUtils(i, visited, recursion)) {
                return true;
            }
        }
    }
    return false;
}

bool graphList::detectCycleInAGraphUtils(int node, bool *visited, bool *recursion) {
    visited[node] = true;
    recursion[node] = true;

    for (list<int>::iterator iterator = this->adj[node].begin(); iterator != this->adj[node].end(); iterator++) {
        if (!visited[*iterator] && detectCycleInAGraphUtils(*iterator, visited, recursion)) {
            return true;
        } else if (recursion[*iterator]) {
            return true;
        }
    }

    recursion[node] = false;
    return false;
}

bool graphList::detectCycleInAGraphUsingColors(int startElement) {
    Color *color = new Color[this->v];
    int i;

    for (i = 0; i < this->v; i++) {
        color[i] = WHITE;
    }

    for (i = 0; i < this->v; i++) {
        if (color[i] == WHITE) {
            if (detectCycleInAGraphUsingColorsUtils(i, color)) {
                return true;
            }
        }
    }
    return false;
}

bool graphList::detectCycleInAGraphUsingColorsUtils(int node, Color *color) {
    color[node] = GRAY;

    for (list<int>::iterator iterator = this->adj[node].begin(); iterator != this->adj[node].end(); iterator++) {
        if (color[*iterator] == GRAY) {
            return true;
        }
        if (color[*iterator] == WHITE && detectCycleInAGraphUsingColorsUtils(*iterator, color)) {
            return true;
        }
    }

    color[node] = BLACK;
    return false;
}