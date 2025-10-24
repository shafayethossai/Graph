#include <bits/stdc++.h>
using namespace std;

vector <int> graph[20001];
int color[20001];
enum {NOT_VIS, BLACK, RED};

int bfs (int node) {
    queue <int> q;
    int black=0, red=0;
    q.push(node);
    color[node] = BLACK;
    black++;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : graph[parent]) {
            if (color[child] == NOT_VIS) {
                q.push(child);
                if (color[parent] == BLACK) {
                    color[child] = RED;
                    red++;
                }
                else {
                    color[child] = BLACK;
                    black++;
                }
            }
        }
    }
    return max(black, red);
}

int main () {
    int tc;
    cin >> tc;

    for (int i=0; i<tc; i++) {
        int m;
        cin >> m;

        for (int i=0; i<20001; i++) {
            graph[i].clear();
        }

        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(color, 0, sizeof(color));
        int sum = 0;

        for (int j=0; j<20001; j++) {
            if (color[j] == 0 && !graph[j].empty()) {
                sum += bfs(j);
            }
        }
        printf("Case %d: %d\n",i+1, sum);
    }

    return 0;
}
