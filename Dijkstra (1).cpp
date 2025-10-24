#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    int graph[nodes][nodes];

    for(int i=0;i<nodes;i++)
        for(int j=0;j<nodes;j++)
            graph[i][j] = (i==j)?0:99999;

    for(int i=0;i<edges;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = graph[v2][v1] = w;
    }

    vector<int> d(nodes);
    vector<int> visited(nodes);

    for(int i=0;i<nodes;i++){
        d[i] = 99999;
        visited[i] = 0;
    }

    d[0] = 0;

    while(1){
        int min_d = 99999, min_n = -1;

        for(int i=0;i<nodes;i++){
            if(d[i]<99999 && !visited[i] && d[i] <= min_d ){
                min_d = d[i];
                min_n = i;
            }
        }

        if(min_n == -1) break;
        visited[min_n] = 1;

        for(int j = 0;j<nodes;j++)
            if( !visited[j] )
                d[j] = min(d[j], d[min_n]+graph[min_n][j]);

    }

    cout << "Shortest paths from 0: ";
    for(int i=0;i<nodes;i++)
        cout << d[i] << " ";

}
