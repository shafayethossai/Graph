#include <bits/stdc++.h>
using namespace std;

vector <int> v[1005];
int vis[1005], dis[1005];

void dfs(int node, int d){
    vis[node] = 1;
    dis[node] = d;
    for(int child : v[node]){
        if(vis[child] == 0){
            dfs(child, d+1);
        }
    }
}

int main(){
    int n, e;
    cin>>n;
    e = n-1;
    while(e--){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    int q;
    cin>>q;
    int ans = -1;
    int mn = INT_MAX;
    while(q--){
        int x;
        cin>>x;
        if(dis[x] < mn){
            mn = dis[x];
            ans = x;
        }
        else if(dis[x] == mn){
            ans = min(ans, x);
        }
    }
    cout<<ans<<endl;

    return 0;
}

