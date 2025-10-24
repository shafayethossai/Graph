#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int graph[n][n];
    int e;
    cin >> e;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j] = (i==j)?0:-1;

    for(int i=0;i<e;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        graph[v1][v2] = graph[v2][v1] = w;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] <<" ";
        }
        cout << endl;
    }

    int root = 5;
    vector<int> spanning_tree;

    int visited[n] = {0};
    spanning_tree.push_back(root);
    visited[root] = 1;

    int weight_sum = 0;

    while( spanning_tree.size() < n ){
        int min_weight = 99999;
        int min_v1 = -1, min_v2 = -1;

        for(int v1:spanning_tree){
            for(int v2=0;v2<n;v2++){
                if( graph[v1][v2]>0 && !visited[v2] && graph[v1][v2]<min_weight){
                    min_weight = graph[v1][v2];
                    min_v1 = v1;
                    min_v2 = v2;
                }
            }
        }

        cout << min_v1 << " -> " << min_v2 << endl;
        visited[min_v2] = 1;
        spanning_tree.push_back(min_v2);
        weight_sum += graph[min_v1][min_v2];

    }

    cout << "Sum of Min Spanning Tree: " << weight_sum;

}












