#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001];

void dfs(int node) {
    vis[node] = 1;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            dfs(child);
        }
    }
}

int main () {
    int n, e;
    cin >> n >> e;

    for (int i=1; i<=e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt=0;

    for (int i=1; i<=n; i++) {
        if (vis[i] == 0) {
            cnt++;
            dfs(i);
        }
    }
    //cout << e << " " << n-1 << endl;

    if (cnt == 1 && e == n-1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
