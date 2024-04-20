// shortest path
#include <bits/stdc++.h>
using namespace std;

#define    ll long long
vector <int> graph[10001];
int vis[10001], dist[10001];

void dfs(int node, int d) {
    vis[node] = 1;
    dist[node] = d;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            dfs(child, dist[node]+1);
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
    dfs(1, 0);

    int q;
    cin >> q;
    int ans = -1, min_dist = 1e9;

    while (q--) {
        int city;
        cin >> city;

        if (dist[city] < min_dist) {
            min_dist = dist[city];
            ans = city;
        }
        else if (dist[city] == min_dist && city < ans) {
            ans = city;
        }
    }

    cout << ans << endl;

    return 0;
}
