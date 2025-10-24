#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001], in[10001], out[10001];
int timer = 1;

bool dfs(int node) {
    vis[node] = 1;
    in[node] = timer++;

    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            dfs(child);
        }
    }
    out[node] = timer++;
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

    for (int i=1; i<=n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    int a, b;
    cin >> a >> b;

    if (in[b] > in[a] && out[b] < out[a]) {
        cout << "node b lay on node a" << endl << endl;
    }
    else {
        cout << "node b not lay on node a" << endl << endl;
    }
    cout << "In time : ";
    for (int i=1; i<=n; i++) {
        cout << in[i] << " ";
    }
    cout << endl;

    cout << "Out time : ";
    for (int i=1; i<=n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;


    return 0;
}
