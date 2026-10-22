#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

const int N = 1e5 + 7;
int parent[N];
int component_size[N];

void make(int v) {
    parent[v] = v;
    component_size[v] = 1;
}

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]); // Path Compression
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (component_size[a] < component_size[b]) { // Union by component_size
            swap(a, b);
        }
        parent[b] = a;
        component_size[a] += component_size[b];
    }
}

//  INPUT : 
//  4 
//   2
//  1 2
//  4 1
//  OUTPUT : 
//  2

int main() {
    fast;
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        make(i);
    }
    while (k--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    
    int connected_component = 0;

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            connected_component++;
        }
    }
    cout << connected_component << endl;

    return 0;
}
