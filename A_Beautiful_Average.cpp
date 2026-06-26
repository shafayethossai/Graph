#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll            long long
#define ull           unsigned long long
#define pb            push_back
#define rev(v)        reverse(v.begin(),v.end())
#define yes           cout << "YES" << "\n";
#define no            cout << "NO" << "\n";
#define endl          "\n"
#define srt(v)        sort(v.begin(), v.end())
#define csrt(v)       sort(v.begin(), v.end(), cmp)
#define rsrt(v)       sort(v.rbegin(), v.rend())
#define mem(v, val)   memset(v, val, sizeof(v))
#define mod           1000000000+7 // 10^9 + 7
#define inf           1e18
#define fast          ios::sync_with_stdio(false);cin.tie(nullptr)


template<class T> using special_set = tree<T, null_type, less<T>, rb_tree_tag,
 tree_order_statistics_node_update>;

//1. find the value in kth index in pbds set
//cout << *st.find_by_order(k) << endl;

//2. find how many value in set is less than k
//cout << st.order_of_key(k) << endl;


void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ave = 0;

    for (auto &it: v) {
        cin >> it;
        ave = max(ave, it);
    }
    cout << ave  << endl;
}

int main() {
    fast;
    int tc = 1;
    cin >> tc;
    
    while(tc--) {
        solve();
    }
    

    return 0;
}
