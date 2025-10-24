#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001], dist[10001];

void bfs(int start) {
    queue <int> q;
    q.push(start);
    vis[start] = 1;
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto child : graph[curr]) {
            if (vis[child] == 0) {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main () {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, e;
        cin >> n >> e;

        for (int i=1; i<=n; i++) {
            graph[i].clear();
            vis[i] = 0;
        }

        while (e--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs(1);

        cout << dist[n] << endl;
    }

    return 0;
}
