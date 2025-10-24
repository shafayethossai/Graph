#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll            long long
#define ull           unsigned long long
#define pb            push_back
#define rev(v)        reverse(v.begin(),v.end())
#define yes           cout << "YES" << "\n";
#define no            cout << "NO" << "\n";
#define endl          "\n"
#define srt(v)        sort(v.begin(), v.end())
#define csrt(v)       sort(v.begin(), v.end(), cmp)
#define rsrt(v)       sort(v.rbegin(), v.rend())
#define mem(v, val)   memset(v, val, sizeof(v))
#define mod           1000000000+7 // 10^9 + 7
#define inf           1e18
#define fast          ios::sync_with_stdio(false);cin.tie(nullptr)


template<class T> using special_set = tree<T, null_type, less<T>, rb_tree_tag,
 tree_order_statistics_node_update>;



const ll N = 1e5+9;
vector<ll> g[N];
vector<ll> dist(N,-1), par(N,-1);


void solve() {
    int n, m;
    cin >> n >> m;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    par[1] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    vector<int> path;
    for (int u = n; u != -1; u = par[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    for (int house : path) {
        cout << house << " ";
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