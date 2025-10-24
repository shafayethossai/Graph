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
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] <<" ";
        }
        cout << endl;
    }

    queue<int> q;
    int visited[n] = {0};

    int root = 3;
    q.push(root);

    // Check if queue is empty
    while(!q.empty()){
        // Dequeue the front value from queue
        int node = q.front();
        q.pop();

        // If node is visited then skip
        if( visited[node] )
            continue;

        // If not visited then traverse and mark as visited
        cout << node << " ";
        visited[node] = 1;

        // Add adjacent non-visited vertices of node to queue
        for(int i=0;i<n;i++)
            if( graph[node][i]==1 && !visited[i])
                q.push(i);
    }

}












