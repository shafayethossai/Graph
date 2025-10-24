#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int a = 1;

bool dfs(ll n, ll k, vector<ll>&ans) {
    ans.pb(n);

    if (n == k) {
        //cout << "2*n : " << a++ << ", value : " << n << endl;
        return true;
    }
    if (n > k) {
        ans.pop_back();
        return false;
    }
    if (dfs(n*2, k, ans)) {
        //cout << "2*n : " << a++ << ", value : " << n << endl;
        return true;
    }
    if (dfs(10*n + 1, k, ans)) {
        //cout << "10*n+1 : " << a++ << ", value : " << n << endl;
        return true;
    }
    ans.pop_back();
    return false;
}

int main () {
    if(fopen("input.txt", "r")){
        freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    vector <ll> ans;

    dfs(n, k, ans);

    if (dfs(n, k, ans)) {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (ll it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
