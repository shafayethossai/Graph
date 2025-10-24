#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll nodes, edges, q;
    cin >> nodes >> edges >> q;
    ll graph[nodes+1][nodes+1];

    for(int i=1;i<=nodes;i++) {
        for(int j=1;j<=nodes;j++) {
            graph[i][j] = (i==j)?0:INF;
        }
    }

    for(int i=0; i<edges; i++){
        ll v1, v2, w;
        cin >> v1 >> v2 >> w;

        graph[v1][v2] = min (graph[v1][v2], w);
        graph[v2][v1] = min (graph[v2][v1], w);
    }

    for(int k = 1; k<=nodes; k++) {
        for(int i=1; i<=nodes; i++) {
            for(int j=1; j<=nodes; j++) {
                if(graph[i][k] != INF && graph[k][j] != INF) {
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        if(graph[u][v] >= INF) {
            cout << "-1" << endl;
        } 
        else {
            cout << graph[u][v] << endl;
        }
    }

    return 0;
}