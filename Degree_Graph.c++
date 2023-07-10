#include <iostream>
using namespace std;
int main()
{
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n; // Read the number of vertices
    cout << "Enter the number of edges: ";
    cin >> e; // Read the number of edges
    int in[n] = {0}, out[n] = {0}; // Initialize in-degree and out-degree arrays
    cout << "Enter the edges: \n";
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y; // Read an edge
        out[x]++; // Increment the out-degree of vertex x
        in[y]++; // Increment the in-degree of vertex y
    }
    cout << "Vertex\tIn\tOut\n"; // Print the header of the table
    for (int i = 0; i < n; i++)
        cout << i << "\t" << in[i] << "\t" << out[i] << endl; // Print the in-degree and out-degree of each vertex
    return 0;
}
