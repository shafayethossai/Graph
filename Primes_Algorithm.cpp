#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1002];
int vis[1002] = {0};

int MST(int root) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;

    pq.push({0, root});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node]) {
            continue;
        }
        vis[node] = 1;
        sum += wt;

        for (auto adj : graph[node]) {
            int adjNode = adj.first;
            int edgeWeight = adj.second;

            if (!vis[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int n, e;
    cin >> n >> e;

    // Input graph edges
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int result = MST(1);
    cout << "Total Cost will be : " << result << endl;

    return 0;
}
