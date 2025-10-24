#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2001;

void Topological(int node, vector<bool>& vis, stack<int>& s, vector<vector<int>>& graph) {
    vis[node] = true;

    for (auto child : graph[node]) {
        if (!vis[child]) {
            Topological(child, vis, s, graph);
        }
    }
    s.push(node);
}

void dfs(int node, vector<vector<int>>& graph2, vector<bool>& vis) {
    vis[node] = true;
    for (auto child : graph2[node]) {
        if (!vis[child]) {
            dfs(child, graph2, vis);
        }
    }
}

int Kosaraju(int n, vector<vector<int>>& graph) {
    // Step 1: Topological sort
    stack<int> s;
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            Topological(i, vis, s, graph);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> graph2(n);

    for (int i = 0; i < n; i++) {
        for (int v : graph[i]) {
            graph2[v].push_back(i);
        }
    }

    // Step 3: Find strongly connected components
            // if popped node is not visited yet
                // SCC++
                // DFS

    fill(vis.begin(), vis.end(), false);
    int SCC = 0;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!vis[node]) {
            SCC++;
            dfs(node, graph2, vis);
        }
    }
    return SCC;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int ans = Kosaraju(n, graph);
    cout << ans << endl;

    return 0;
}

