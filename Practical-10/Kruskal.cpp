
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (DSU)
int parent[100];
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    // Initialize DSU
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int mstWeight = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (auto e : edges) {
        int pu = find(e.u);
        int pv = find(e.v);

        // Include edge if it doesn't form a cycle
        if (pu != pv) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            unite(pu, pv);
            mstWeight += e.weight;
            count++;

            if (count == n - 1)
                break;
        }
    }

    if (count != n - 1)
        cout << "MST does not exist (Graph is disconnected).\n";
    else
        cout << "Total MST Weight: " << mstWeight << endl;

    return 0;
}
