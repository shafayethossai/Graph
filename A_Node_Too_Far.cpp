#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const ll inf = 1e9 + 9;
ll cs = 0;

int main() {
    fast;
    ll edge;

    while(cin >> edge && edge != 0) {
        map<ll, vector<ll>>g;
        set<ll> nodes;

        while (edge--) {
            ll u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }
        ll start, ttl;
        
        while (cin >> start >> ttl && !(start == 0 && ttl == 0)) {
            cs++;
            map<ll, ll> dist;
            
            for (auto it : nodes) {
                dist[it] = inf;
            }
            queue<ll> q;
            q.push(start);
            dist[start] = 0;

            while (!q.empty()) {
                ll curr = q.front();
                q.pop();

                for (auto child : g[curr]) {
                    if (dist[curr] + 1 < dist[child]) {
                        dist[child] = dist[curr] + 1;
                        q.push(child);
                    }
                }
            }
            ll count = 0;
            
            for (auto it : nodes) {
                if (dist[it] > ttl) {
                    count++;
                }
            }
            cout << "Case " << cs << ": " << count << " nodes not reachable from node " << start << " with TTL = " << ttl << "." << endl;
        }
    }

    

    return 0;
}
