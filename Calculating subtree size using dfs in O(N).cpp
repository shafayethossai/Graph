#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int vis[10001], subtree_size[10001];

int dfs(int node) {
    vis[node] = 1;
    int curr_size = 1;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            curr_size += dfs(child);
        }
    }
    subtree_size[node] = curr_size;
    return curr_size;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << i << " : "<< subtree_size[i] << endl;
    }

    return 0;
}
