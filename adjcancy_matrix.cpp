#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;

    bool graph[n][n];

    memset(graph, 0, sizeof(graph));

    for(int i=1; i<=e; i++){
        int u,v;
        cin>>u>>v;

        graph[u][v]=true;
        graph[v][u]=true;
    }

    int q;
    cin>>q;

    for(int i=1; i<=q; i++){
        int u,v;
        cin>>u>>v;

        if(graph[u][v]==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
