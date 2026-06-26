#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const ll N = 1009;
vector<ll> g[N];
vector<ll> vis(N, 0), person(N);
map<ll, ll> mp;
ll n, k, m;

void dfs(ll node) {
    vis[node] = 1;
    mp[node]++;

    for (auto child : g[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

void solve() {
    cin >> k >> n >> m;

    for (int i=1; i<=n; i++) {
        g[i].clear();
    }
    mp.clear();

    for (int i=0; i<k; i++) {
        cin >> person[i];
    }
    while (m--) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (auto it : person) {
        fill(vis.begin(), vis.end(), 0);
        dfs(it);
    }
    ll ans = 0;

    for (auto it : mp) {
        if (it.second == k) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    fast;
    int tc;
    cin >> tc;
    
    for (int i=1; i<=tc; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
