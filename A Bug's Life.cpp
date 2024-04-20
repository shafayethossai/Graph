#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int vis[10001], col[10001];

bool dfs(int node, int c) {
    vis[node] = 1;
    col[node] = c;

    for (auto child : graph[node]){
        if (vis[child] == 0) {
            if (dfs(child, c ^ 1) == false){
                return false;
            }
        }
        else {
            if (col[node] == col[child]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tc;
    cin >> tc;

    for (int scenario=1;scenario<=tc;scenario++) {
        int n, e;
        cin >> n >> e;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i <= e; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool flag = true;

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                if (dfs(i, 0) == false) {
                    flag = false;
                }
            }
        }
        printf("Scenario #%d:\n", scenario);

        if (flag == false) {
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }
    }
    return 0;
}
