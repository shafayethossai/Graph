#include <bits/stdc++.h>
using namespace std;

// *****************************This code check cycle exist in graph or not(cycle make with any number of node)*****************************
const int N = 1e5 + 9;
vector<ll> graph[N];
int col[N];
bool cycle;

void dfs(ll node) {
    col[node] = 1;

    for (auto child : graph[node]) {
        if (col[child] == 0) {
            dfs(child);
        }
        else if (col[child] == 1) {
            cycle = true;
        }
    }
    col[node] = 2;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    for (int i=1; i<=m; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cycle = false;
    
    for (int i=1; i<=n; i++) {
        if (col[i] == 0) {
            dfs(i);
        }
    }
    if (cycle) {
        cout << "Cycle Exist" << endl;
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
