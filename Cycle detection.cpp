#include <bits/stdc++.h>
using namespace std;

// *****************************This code check cycle exist in graph or not and the Path (cycle make with any number of node)*****************************
const int N = 1e5 + 9;
vector<ll> graph[N];
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

void solve() {
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
}

//********************************* This code only for 3 node's cycle detection ********************************
vector <int> graph[10001];
int vis[10001];

bool dfs (int node, int par) {
    vis[node] = 1;
    for (auto child : graph[node]){
        if (vis[child] == 0) {
            if (dfs(child, node) == true){
                return true;
            }
        }
        else {
            if (child != par) {
                return true;
            }
        }
    }
    return false;
}

int main () {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (dfs(1, 0) == false) {
        cout << "No cycle exist"<<endl;
    } else {
        cout << "Cycle exist"<<endl;
    }

    return 0;
}
