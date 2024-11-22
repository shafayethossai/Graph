#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &vis,
         vector<int> adj[], vector<int> &tin, vector<int> &low,
         vector<vector<int>> &bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node]) {
        if (it == parent) continue; // Ignore the edge to the parent node
        if (!vis[it]) {
            dfs(it, node, timer, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                bridges.push_back({node, it});
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> findCriticalConnections(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for (auto it : connections) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0), tin(n, -1), low(n, -1);
    vector<vector<int>> bridges;
    int timer = 1;

    dfs(0, -1, timer, vis, adj, tin, low, bridges);

    return bridges;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> connections(m);
    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        connections[i] = {u, v};
    }

    vector<vector<int>> bridges = findCriticalConnections(n, connections);
    cout << "Critical Connections (Bridges):" << endl;
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &vis,
         vector<int> adj[], vector<int> &tin, vector<int> &low,
         vector<vector<int>> &bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : adj[node]) {
        if (it == parent) continue; // Ignore the edge to the parent node
        if (!vis[it]) {
            dfs(it, node, timer, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node]) {
                bridges.push_back({node, it});
            }
        } else {
            low[node] = min(low[node], tin[it]);
        }
    }
}

vector<vector<int>> findCriticalConnections(int n, vector<vector<int>> &connections) {
    vector<int> adj[n];
    for (auto it : connections) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0), tin(n, -1), low(n, -1);
    vector<vector<int>> bridges;
    int timer = 1;

    dfs(0, -1, timer, vis, adj, tin, low, bridges);

    return bridges;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> connections(m);
    cout << "Enter the edges (node1 node2):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        connections[i] = {u, v};
    }

    vector<vector<int>> bridges = findCriticalConnections(n, connections);
    cout << "Critical Connections (Bridges):" << endl;
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}
