#include <iostream>
#include <queue>
using namespace std;

const int MAX = 10;
bool visited[MAX];
int graph[MAX][MAX];
int V;

void BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout<< node << " ";

        for (int i = 0; i < V; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

}

int main() {
    int E, u, v, start;
    cout <<"Enter the number of vertices: "; cin >>V;
    cout <<"Enter the number of Edges: "; cin >> E;
    cout <<"Enter the edges:\n";
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
    cout << "Start Vertex: "; cin >> start;
    cout << "BFS: ";
    BFS(start);
}