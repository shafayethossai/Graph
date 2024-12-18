#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    int graph[n+1][n+1];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = -1;
            }
        }
    }

    while (e--) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
