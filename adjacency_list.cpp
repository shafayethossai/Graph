#include <bits/stdc++.h>
using namespace std;

vector<int>graph[1002];

int main () {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cout << i;

        for (int j = 0; j<graph[i].size(); j++) {
            cout << "->" << graph[i][j];
        }
        cout << endl;
    }

    int q; // one node is connect to another node is yes or not
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        bool flag = false;
        int len = graph[x].size();

        for (int j = 0; j <= len; j++) {
            if (graph[x][j] == y) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "No" << endl;
        }
    }

    int big = 0;
    int index = 0;

    for (int i = 1; i <= n; i++) { // finding max size with node
        if (big < graph[i].size()) {
            big = graph[i].size();
            index = i;
        }
    }

    cout << "node : " << index << " size : " << big << endl;

    return 0;
}
