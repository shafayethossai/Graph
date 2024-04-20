#include <bits/stdc++.h>
using namespace std;

vector <int> graph[10001];
int vis[10001];

bool dfs (int node, int par) {
    vis[node] = 1;

    for (auto child : graph[node]){
        if (vis[child] == 0) {
            if (dfs(child, node) == true){
                return true;
            }
        }
        else {
            if (child != par) {
                return true;
            }
        }
    }
    return false;
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

    if (dfs(1, 0) == false) {
        cout << "No cycle exist"<<endl;
    } else {
        cout << "Cycle exist"<<endl;
    }

    return 0;
}
