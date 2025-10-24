#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 9;
vector<ll> graph[N];
int col[N];
int col[N], par[N];
bool cycle;
vector<ll> cycle_Path;

void dfs(ll node) {
    col[node] = 1;

    for (auto child : graph[node]) {
        if (col[child] == 0) {
            par[child] = node;
            dfs(child);

            if (cycle) return;
        }
        else if (col[child] == 1) {
            cycle = true;
            
            ll curr = node;
            cycle_Path.push_back(child);

            while (curr != child && curr != -1) {
                cycle_Path.push_back(curr);
                curr = par[curr];
            }
            cycle_Path.push_back(child);
            reverse(cycle_Path.begin(), cycle_Path.end());
            return;
        }
    }
    col[node] = 2;
}

int main() {
    ll n, m;
    cin >> n >> m;

    for (int i=1; i<n; i++) {
        graph[i].clear();
        col[i] = 0;
        par[i] = -1;
    }

    for (int i=1; i<=m; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cycle_Path.clear();
    cycle = false;

    for (int i=1; i<=n; i++) {
        if (col[i] == 0) {
            dfs(i);
            if (cycle) break;
        }
    }
    if (cycle) {
        cout << "Cycle Exist" << endl;
        cout << "Cycle Path: ";
        for (ll node : cycle_Path) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "Cycle not Exist" << endl;
    }

  return 0;
}