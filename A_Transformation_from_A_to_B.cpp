#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

bool dfs (ll n, ll k, vector<ll>&ans) {
    ans.push_back(n);

    if (n == k) {
        return true;
    }
    if (n > k) {
        ans.pop_back();
        return false;
    }
    if (dfs(n * 2, k, ans)) {
        return true;
    }
    if (dfs(n * 10 + 1, k, ans)) {
        return true;
    }

    ans.pop_back();
    return false;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> ans;

    if (dfs(n, k, ans)) {
        cout << "YES" << endl;
        cout << ans.size() << endl;

        for (auto &it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    fast;
    int tc = 1;
    //cin >> tc;
    
    while(tc--) {
        solve();
    }
    

    return 0;
}
