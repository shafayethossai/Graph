#include <bits/stdc++.h>
using namespace std;

#define    ll long long
const int MAX = 30005;
vector <pair<ll, ll>> graph[MAX];
bool vis[MAX];
ll maxD, maxnode, lol=1;

void dfs(ll node, ll d) {
    ll x, w;
    vis[node] = 1;

    if (d > maxD) {
//        cout << node << " : " << d << endl;
        maxD = d;
        maxnode = node;
    }
    for (auto child : graph[node]) {
        x = child.first;
        w = child.second;

        if (vis[x] == 0) {
            dfs(x, d+w);
        }
    }
}

int main () {
    ll tc;
    cin >> tc;

    for (int cs=1; cs<=tc; cs++) {
        ll n;
        cin >> n;

        for (int i=0; i<MAX; i++) graph[i].clear();

        for (int i=1; i<=n-1; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        maxD = INT_MIN;
        memset(vis, 0, sizeof vis);
        dfs(0, 0);


        maxD = INT_MIN;
        memset(vis, 0, sizeof vis);
        dfs(maxnode, 0);

        printf("Case %d: %lld\n", cs, maxD);
    }


    return 0;
}
