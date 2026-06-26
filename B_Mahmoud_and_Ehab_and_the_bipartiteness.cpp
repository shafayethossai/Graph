#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const ll N = 1e5 + 9;
vector<ll> g[N];
vector<ll> vis(N, 0), col(2);
 
void dfs(ll node, ll c) {
    col[c]++;
    vis[node] = 1;
 
    for (auto child : g[node]) {
        if (!vis[child]) {
            dfs(child, c^1);
        }
    }
}
 
void solve() {
    ll n, edge = 0;
    cin >> n;
    edge = n-1;
 
    while (edge--) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
 
    cout << (col[0] * col[1]) - (n-1)<< endl;
}

int main() {
    fast;
    int tc = 1;
    //cin >> tc;
    
    while(tc--) {
        solve();
    }
    

    return 0;
}
