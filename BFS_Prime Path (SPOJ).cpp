#include <bits/stdc++.h>
using namespace std;

vector <int> graph[100001];
vector <int> primes;
int vis[100001], dist[100001];

bool isprime(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

bool isvalid(int a, int b){
    int cnt=0;

    while (a > 0){
        if (a%10 != b%10){
            cnt++;
        }
        a /= 10, b /= 10;
    }
    if (cnt == 1){
        return true;
    }
    else{
        return false;
    }
}

void build_graph(){
    for (int i=1000; i<=9999; i++){
        if (isprime(i)){
            primes.push_back(i);
        }
    }
    for (int i=0; i<primes.size(); i++){
        for (int j=i+1; j<primes.size(); j++){
            int a = primes[i];
            int b = primes[j];

            if (isvalid(a, b)){
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
    }
}

void bfs (int start){
    queue <int> q;
    q.push(start);

    vis[start] = 1;
    dist[start] = 0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (auto child : graph[curr]){
            if (vis[child] == 0){
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}


int main (){
    int tc;
    cin >> tc;
    build_graph();

    while (tc--){
        int a, b;
        cin >> a >> b;

        for (int i=1000; i<=9999; i++){
            vis[i] = 0;
            dist[i] = -1;
        }
        bfs(a);

        if (dist[b] == -1){
            cout << "Impossible" << endl;
        } else{
            cout << dist[b] << endl;
        }
    }
    return 0;
}
