#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;



void primsAlgorithm(int V, vector<vector<pair<int, int>>>& adj){
    // {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(V, false);

    pq.push({0, 0}); //start from vertex 0

    int totalWeight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        
        visited[u] = true;
        totalWeight += weight;

        if (weight != 0)
            cout << "Vertex" << u <<" - Weight " <<weight << "\n";
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!visited[v]) {
                pq.push({w, v});
            }
        }

    }
    cout << "Total MST Weight: " << totalWeight << '\n';
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";

    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    primsAlgorithm(V, adj);

    return 0;
}