#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

vector<pair<int, int>> graph[1001];
vector<int> dist(1009, INF);

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (auto child : graph[node]) {
            int child_node = child.first;
            int child_wt = child.second;

            if (dist[child_node] > dist[node] + child_wt) {
                dist[child_node] = dist[node] + child_wt;
                pq.push({dist[child_node], child_node});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
