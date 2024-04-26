#include <bits/stdc++.h>
using namespace std;

vector <int> v[100005];
int vis[100005];

void DFS (int node) {
    vis[node] = 1;
    for (int child : v[node]) {
        if (vis[child] == 0) {
            DFS(child);
        }
    }
}

int main () {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << endl;

    return 0;
}
