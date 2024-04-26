#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

vector <pair<int,int>> graph[1001];

int main () {
    int n, m, u, v, w;
    cin >> n >> m;

    while (m--) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;

    vector <int> dist(n+1, INF);
    pq.push(make_pair(0, 1));
    dist[1] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();

        for (auto child : graph[curr]) {
            if (curr_d + child.second < dist[child.first]) {
                dist[child.first] = curr_d + child.second;
                pq.push(make_pair(dist[child.first], child.first));
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
