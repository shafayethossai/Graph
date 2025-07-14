#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const ll N = 1e5 + 9;
vector<ll> g[N];
ll indeg[N], vis[N];

bool dfs (ll node, ll par) {
    vis[node] = 1;
    for (auto child : g[node]){
        if (vis[child] == 0) {
            if (dfs(child, node) == true){
                return true;
            }
        }
        else {
            if (child != par) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i=0; i<=n; i++) {
        g[i].clear();
        vis[i] = 0;
        indeg[i] = 0;
    }
    while (m--) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }
    queue<ll> q;

    for (int i=1; i<=n; i++) {
        if (!indeg[i]) {
            q.push(i);
        }
    }
    vector<ll> ans;
    
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        ans.push_back(curr);
        
        for (auto child : g[curr]) {
            indeg[child]--;
            
            if (indeg[child] == 0) {
                q.push(child);
            }
        }
    }
    if (ans.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
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
