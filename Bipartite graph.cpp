#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001], col[10001];

bool dfs(int node, int c) {
    vis[node] = 1;
    col[node] = c;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            if (dfs(child, c^1) == false) {
                return false;
            }
        }
        else {
            if (col[node] == col[child]) {
                return false;
            }
        }
    }
    return true;
}

int main () {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (dfs(1, 0) == true) {
        cout << "Graph is bipartite" << endl;
    }
    else {
        cout << "Graph is not bipartite" << endl;
    }


    return 0;
}
