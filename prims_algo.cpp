#include <iostream>
#include <climits>

using namespace std;

#define V 7

int findMinEdge(int minEdges[], bool selectedNodes[]) {
    int min = INT_MAX, minIndex;

    for (int i = 0; i < V; i++) {
        if (!selectedNodes[i] && minEdges[i] < min) {
            min = minEdges[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void primAlgorithm(int graph[V][V]) {
    int minEdges[V];
    bool selectedNodes[V];

    for (int i = 0; i < V; i++) {
        minEdges[i] = INT_MAX;
        selectedNodes[i] = false;
    }

    minEdges[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinEdge(minEdges, selectedNodes);
        selectedNodes[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !selectedNodes[v] && graph[u][v] < minEdges[v]) {
                minEdges[v] = graph[u][v];
            }
        }
    }

    cout << "Edges of Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        cout << "Edge " << i << ": " << i << " - " << i + 1 << " Weight: " << minEdges[i] << endl;
    }
}

int main()
 {
    int graph[V][V] = {
        {0, 2, 0, 6, 0, 1, 0},
        {2, 0, 3, 8, 5, 3, 5},
        {0, 3, 0, 0, 7, 1, 0},
        {6, 8, 0, 0, 9, 3, 7},
        {0, 5, 7, 9, 0, 1, 0},
        {0, 2, 3, 1, 0, 1, 0},
        {0, 3, 1, 6, 7, 0, 0}
    };

    primAlgorithm(graph);

    return 0;
}