#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1002];
int vis[1002] = {0};

void BFS(int root) {
    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(vis[node] != 0) {
            continue;
        }
        vis[node] = 1;
        cout << node << " -> ";

        for (int i=0; i<graph[node].size(); i++) {
            int child = graph[node][i];

            if (vis[child] == 0) {
                q.push(child);
            }
        }
    }
}

int main () {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1);

    cout << endl;

    return 0;
}
