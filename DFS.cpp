// 6 5
// 1 2
// 2 3
// 2 4
// 4 5
// 4 6
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1002];
int vis [1003];

void DFS (int node){
    vis[node] = 1;
    cout << node << " -> ";

    for(int i = 0; i < graph[node].size(); i++){
        int child = graph[node][i];

        if(vis[child] == 0){
            DFS (child);
        }
    }
}

int main () {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    DFS(1);

    cout << endl;

    return 0;
}
