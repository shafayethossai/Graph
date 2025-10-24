#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

const int N=1e4;
vector<int>adj [N+7];
int vis [N+7];
vector<int>meet(N+7);
set<int>ans;

void dfs(int me, int k) {
    cout << me << " ";

    vis[me]=true;
    meet[me]++;
    if (meet[me] == k) {
        ans.insert(me);
    }
    for (auto child : adj[me]) {
        if (vis[child]==0) {
            dfs(child,k);
        }
    }
}

int main() {
    ll t; cin >> t;

    for(int t1=1; t1<=t; t1++) {
        int k, n, m;
        cin >> k >> n >> m;
        vector <int> p(k);

        for(int i=0; i<k; i++) {
            cin >> p[i];
        }
        while(m--) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        for(int i=0; i<k; i++) {
            dfs(p[i],k);
            for(int j=1; j<=n; j++) {
                vis[j]=false;
            }
        }

        cout << "\nans : " << endl;
        for (auto it : ans) {
            cout << it << " ";
        }

        cout<<"Case "<<t1<<": ";
        cout<<ans.size()<<endl;
        ans.clear();
        for(int i=1;i<=n;i++) {
            adj[i].clear();
            vis[i]=false;
            meet[i]=0;
        }
    }
    return 0;
}
