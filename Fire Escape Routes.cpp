#include <bits/stdc++.h>
using namespace std;
#define    mod 1000000007

vector <int> graph[100001];
int vis[100001];
int cc_cnt;

void dfs(int node) {
    vis[node] = 1;
    cc_cnt++;

    for (auto child : graph[node]) {
        if (vis[node] == 0) {
            dfs(child);
        }
    }
}

int main () {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, e;
        cin >> n >> e;

        for (int i=1; i<=n; i++) {
            graph[i].clear();
            vis[i] = 0;
        }
        for (int i=1; i<=e; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int cnt=0;
        long long int ans=1;

        for (int i=1; i<=n; i++) {
            if (vis[i] == 0) {
                cc_cnt = 0;
                dfs(i), cnt++;
                ans = (ans * cc_cnt) % mod;
            }
        }
        cout << cnt << " " << ans << endl;
    }


    return 0;
}
