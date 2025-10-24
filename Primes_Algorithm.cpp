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
        int node = it.second;
        int wt = it.first;
        pq.pop();

        if (vis[node] != 0) {
            continue;
        }
        vis[node] = 1;
        sum += wt;

        for (auto child : graph[node]) {
            int child_node = child.first;
            int child_wt = child.second;

            if (vis[child_node] == 0) {
                pq.push({child_wt, child_node});
            }
        }
    }
    return sum;
}

int main () {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int result = MST(1);
    cout << "Total cost is : " << result << endl;

    return 0;
}
