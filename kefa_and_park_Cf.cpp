#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
vector<int> graph[200007];
int cats[200007];
vector <bool> vis(200007, 0);

void dfs(int y, int cnt) {
    vis[y] = 1;
    cnt = (cats[y] == 1) ? ++cnt : 0;

    if (cnt > k) {
        return;
    }
    if (graph[y].size() == 1 && y != 1) {
        ans++;
    }

    for (auto child : graph[y]) {
        if (vis[child] == 0) {
            dfs(child, cnt);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}
