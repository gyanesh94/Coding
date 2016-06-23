#include "headers/graph.cpp"

int main() {
    int totalGraphElements, startElement;
    bool dummy = true;

    if (dummy) {
        totalGraphElements = 5;
    } else {
        cout << "Enter total graph elements= ";
        cin >> totalGraphElements;
    }

    graph graph(totalGraphElements);

    if (dummy) {
        graph.addEdge(0,1);
        graph.addEdge(1,3);
        graph.addEdge(2,4);
        graph.addEdge(3,4);
        graph.addEdge(4,2);
    } else {
        int flag = 1, source, destination;
        while (flag) {
            cout << "Enter Source= ";
            cin >> source;
            cout << "Enter Destination= ";
            cin >> destination;
            if (source < totalGraphElements && destination < totalGraphElements) {
                graph.addEdge(source,destination);;
            } else {
                cout << "Wrong Source or destination." << endl;
            }
            cout << "To add more links enter 1 else 0= ";
            cin >> flag;
        }
    }

    if(dummy) {
        startElement = 0;
    } else {
        cout << "Enter Start Element= ";
        cin >> startElement;

        if (startElement > totalGraphElements) {
            cout << "Incorrect Start Element" << endl;
            return 0;
        }
    }

    graph.depthFirstSearch(startElement);

    return 0;
}