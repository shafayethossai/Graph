#include <bits/stdc++.h>
using namespace std;

vector <int> graph[101];
int in[101], low[101], vis[101];
int timer;

void dfs (int node, int parent) {
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;

    for (auto child : graph[node]) {
        if (child == parent) {
            continue;
        }
        if (vis[child] == 1) {
            low[node] = min(low[node], in[child]); // back edge
        }
        else {
            dfs(child, node); // forward edge

            if (low[child] > in[node]) {
                cout << node << "-" << child << "is a bridge" << endl;
            }

            low[node] = min(low[node], low[child]);
        }
    }
}

int main () {
    int n, m, a, b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    return 0;
}
