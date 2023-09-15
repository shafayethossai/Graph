#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int q;
    cin>>q;

    for(int i=0; i<q; i++){
        int u,v;
        cin>>u>>v;
        bool flag=false;
        int len=graph[u].size();

        for(int j=0; j<len; j++){
            if(graph[u][j]==v){
                cout<<"YES"<<endl;
                flag=true; break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

