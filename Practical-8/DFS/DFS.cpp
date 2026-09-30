#include <iostream>
using namespace std;

const int MAX = 10;

bool visited[MAX];
int graph[MAX][MAX];
int V;

void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < V; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int E, u, v, start;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of Edges: ";
    cin >> E;

    cout << "Enter the edges:\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    cout << "Start Vertex: ";
    cin >> start;

    cout << "DFS: ";
    DFS(start);

    return 0;
}