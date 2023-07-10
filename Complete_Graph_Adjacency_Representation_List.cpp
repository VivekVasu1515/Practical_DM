#include <iostream>
using namespace std;

// Function to check if a given graph is a complete graph
bool isCompleteGraph(int** adjList, int n) {
    // Loop through all vertices in the graph
    for (int i = 0; i < n; i++) {
        int degree = 0;
        // Loop through all other vertices to check for edges
        for (int j = 0; j < n; j++) {
            // If there is an edge between vertex i and vertex j, increment the degree of vertex i
            if (adjList[i][j] == 1) {
                degree++;
            }
        }
        // If the degree of vertex i is not equal to n-1, then the graph is not complete
        if (degree != n - 1) {
            return false;
        }
    }
    // If all vertices have degree n-1, then the graph is complete
    return true;
}

int main() {
    int n = 4;
    // Dynamically allocate a 2D array to represent the adjacency list
    int** adjList = new int*[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adjList[i][j] = 0;
        }
    }

    // Add edges to the graph
    adjList[0][1] = 1;
    adjList[0][2] = 1;
    adjList[0][3] = 1;
    adjList[1][0] = 1;
    adjList[1][2] = 1;
    adjList[1][3] = 1;
    adjList[2][0] = 1;
    adjList[2][1] = 1;
    adjList[2][3] = 1;
    adjList[3][0] = 1;
    adjList[3][1] = 1;
    adjList[3][2] = 1;

    // Check if the graph is complete and print the result
    cout << isCompleteGraph(adjList, n) << endl;

    // Deallocate the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] adjList[i];
    }
    delete[] adjList;

    return 0;
}
