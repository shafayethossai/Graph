#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &discovery,
         vector<int> &low, stack<int> &st, vector<bool> &Instack, vector<vector<int>> &ans,
         int &timer, int &SCC) {
    vis[node] = true;
    discovery[node] = low[node] = timer++;
    st.push(node);
    Instack[node] = true;

    for (auto neighbour : graph[node]) {
        if (!vis[neighbour]) {
            dfs(neighbour, graph, vis, discovery, low, st, Instack, ans, timer, SCC);
            low[node] = min(low[node], low[neighbour]);
        }
        else if (Instack[neighbour]) {
            low[node] = min(low[node], discovery[neighbour]);
        }
    }

    // If node is the root of an SCC
    if (discovery[node] == low[node]) {
        vector<int> component;
        while (true) {
            int v = st.top();
            st.pop();
            Instack[v] = false;
            component.push_back(v);
            if (v == node) break;
        }
        ans.push_back(component);  // Store the SCC
        SCC++;  // Increase the count of SCCs
    }
}

vector<vector<int>> tarjan(int n, vector<vector<int>> &graph, int &SCC) {
    vector<vector<int>> ans;       // Stores all SCCs
    vector<int> discovery(n, -1);  // Discovery times of nodes
    vector<int> low(n, -1);        // Lowest reachable discovery time
    vector<bool> vis(n, false);    // Visited nodes
    stack<int> st;                 // Stack to store the nodes in the current SCC
    vector<bool> Instack(n, false); // To check if a node is in the stack
    int timer = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, graph, vis, discovery, low, st, Instack, ans, timer, SCC);
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    // Input the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int SCC = 0;
    vector<vector<int>> sccs = tarjan(n, graph, SCC);

    // Output the SCCs
    cout << "Strongly Connected Components:\n";
    for (const auto &component : sccs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    // Output the count of SCCs
    cout << "Number of SCCs: " << SCC << endl;

    return 0;
}
