#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph G;
    createGraph(G);
    menu();

    string a, b;
    cin >> a;
    addVertex(G, a);
    cin >> b;
    addEdge(G, a, b);
    displayGroupMembers(G, a);

    return 0;
}
