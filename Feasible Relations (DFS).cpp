#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000001];
int vis[1000001], cc[1000001];
int curr_cc;

void dfs(int node) {
    vis[node] = 1;
    cc[node] = curr_cc;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            dfs(child);
        }
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, k;
        string op;
        cin >> n >> k;
        curr_cc = 0;

        vector<pair<int, int>> edges;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            vis[i] = 0;
        }

        for (int i = 1; i <= k; i++) {
            int u, v;
            cin >> u >> op >> v;

            if (op == "=") {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            else {
                edges.push_back({u, v});
            }
        }
        for (int i=1; i<=n; i++) {
            if (vis[i] == 0) {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            if (cc[u] == cc[v]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
