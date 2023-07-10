#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of vertices in the graph

// Function to check if a given graph is a complete graph
bool isCompleteGraph(int graph[MAX][MAX], int V) {
    // Iterate over all pairs of vertices
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            // If i is not equal to j and there is no edge between them
            if (i != j && graph[i][j] == 0)
                return false; // The graph is not complete
    return true; // The graph is complete
}

int main() {
    int V = 4; // Number of vertices in the graph
    // Adjacency matrix representation of the graph
    int graph[MAX][MAX] = {{0, 1, 1, 1},
                           {1, 0, 1, 1},
                           {1, 1, 0, 1},
                           {1, 1, 1, 0}};
    // Check if the graph is complete
    if (isCompleteGraph(graph, V))
        cout << "The graph is a complete graph";
    else
        cout << "The graph is not a complete graph";
    return 0;
}
