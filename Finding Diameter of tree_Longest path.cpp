#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001];
int maxD, maxnode;

void dfs(int node, int d) {
    vis[node] = 1;

    if (d > maxD) {
        maxD = d;
        maxnode = node;
    }
    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            dfs(child, d+1);
        }
    }
}

int main () {
    int n;
    cin >> n;

    for (int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    maxD = -1;
    dfs(1, 0);

    for (int i=1; i<=n; i++) {
        vis[i] = 0;
    }

    maxD = -1;
    dfs(maxnode, 0);

    cout << maxD << endl;


    return 0;
}
