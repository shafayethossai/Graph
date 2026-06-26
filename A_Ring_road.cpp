#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const int N = 105;
vector<pair<int, int>> graph[N];
bool vis[N];
int cost = 0, tt=0;
 
void dfs(int node, int p) {
	vis[node] = true;
 
	for (auto child : graph[node]) {
		int v = child.first;
		int w = child.second;
 
		if (!vis[v]) {
			cost += w;
			//tt++;
			//cout <<"if => "<< ", tt: " << tt << ", node: " << node << ", v: " << v << ", p: " << p << ", cost: " << cost << endl;
			dfs(v, node);
		}
		else if (v == 1 && p != 1) {
			cost += w;
			//tt++;
			//cout <<"elseif => "<< ", tt: " << tt << ", node: " << node << ", v: " << v << ", p: " << p << ", cost: " << cost << endl;
		}
	}
}
 
int main() {
	if(fopen("input.txt", "r")){
        freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    }
    fast;
    int n, sum=0;
    cin >> n;
 
    for (int i=1; i<=n; i++) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	graph[u].pb({v, 0});
    	graph[v].pb({u, w});
    	sum += w;
    }
    // for (int i = 0; i < N; ++i) {
    //     if (!graph[i].empty()) {
    //         cout << "Graph[" << i << "]:" << endl;
    //         for (const auto& p : graph[i]) {
    //             cout << "First: " << p.first << ", Second: " << p.second << endl;
    //         }
    //     }
    // }
    dfs(1, 0);
    cout << min(cost, sum-cost) << endl;
    
 
    return 0;
}
