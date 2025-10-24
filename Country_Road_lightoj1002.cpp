#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> graph[1001];
int dis[1009], n;

void dijkstra(int st) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i <= n; i++) {
        dis[i] = 20001;
    }
    dis[st] = 0;
    q.push(make_pair(0, st));

    while (!q.empty()) {
        int parent = q.top().second;
        q.pop();

        for (auto child : graph[parent]) {
            int v = child.first;
            int w = child.second;
            if (max(dis[parent], w) < dis[v]) {
                dis[v] = max(dis[parent], w);
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    int e, u, v, w, m, tc, cs = 1;
    cin >> tc;

    for (int i = 0; i < n; i++) {
        graph[i].clear();
    }

    while (tc--) {
        cin >> n >> e;
        for (int i = 0; i < e; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        cin >> m;
        dijkstra(m);

        cout << "Case " << cs++ << ":" << endl;

        for (int i = 0; i < n; i++) {
            if (dis[i] == 20001) {
                cout << "Impossible" << endl;
            }
            else {
                cout << dis[i] << endl;
            }
        }
    }
    return 0;
}
