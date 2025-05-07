#include <bits/stdc++.h>
using namespace std;

#define ll long long

const long long INF = 1e18;
const int MAX_N = 1e5 + 5;

// Global variables
vector<pair<int, int>> adj[MAX_N];
vector<bool> vis(MAX_N, false);
vector<long long> dist(MAX_N, INF);

bool bellmanFord(int n, int src) {
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist[u] == INF) continue;
            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 1; u <= n; u++) {
        if (dist[u] == INF) continue;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                return true; // Negative cycle detected
            }
        }
    }

    return false; // No negative cycle
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    while(m--) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
        adj[v2].push_back({v1, w});
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        fill(dist.begin(), dist.end(), INF);
        fill(vis.begin(), vis.end(), false);

        bool neg_cyc = bellmanFord(n, u);

        if (neg_cyc) {
            cout << "contains negative cycle\n";
        }
        else if (dist[v] == INF) {
            cout << "-1\n";
        }
        else {
            cout << dist[v] << "\n";
        }
    }

    return 0;
}
