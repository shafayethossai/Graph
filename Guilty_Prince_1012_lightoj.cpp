#include <bits/stdc++.h>
using namespace std;

#define    ll long long
#define    endl "\n"
#define    pb push_back

int X[] = {0, 1, 0, -1};
int Y[] = {-1, 0, 1, 0};

int vis[26][26];
char graph[26][26];
int ans = 0, m, n, x, y;

bool border(int x, int y) {
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (border(x + X[i], y + Y[i]) && !vis[x + X[i]][y + Y[i]] && graph[x + X[i]][y + Y[i]] == '.') {
            ans++;
            vis[x + X[i]][y + Y[i]] = true;
            dfs(x + X[i], y + Y[i]);
        }
    }
}

int main() {
    int tc, t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        ans = 0;
        memset(vis, 0, sizeof(vis));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];

                if (graph[i][j] == '@') {
                    x = i, y = j;
                    ans++;
                    vis[i][j] = true;
                }
            }
        }
        dfs(x, y);
        cout << "Case " << ++tc << ": " << ans << endl;
    }
    return 0;
}

