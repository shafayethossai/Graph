#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

vector<pair<ll, ll>> graph[1001];
vector<ll> dist(1009, INF);

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> stay_cost(n+1);

    for (int i=1; i<=n; i++) {
        cin >> stay_cost[i];
    }

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (auto child : graph[node]) {
            ll child_node = child.first;
            ll child_wt = child.second;

            if (dist[child_node] > dist[node] + child_wt + stay_cost[child_node]) {
                dist[child_node] = dist[node] + child_wt + stay_cost[child_node];
                pq.push({dist[child_node], child_node});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] + stay_cost[1] << " ";
    }
    cout << endl;

    return 0;
}