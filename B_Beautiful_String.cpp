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

//ll gcd(ll a, ll b) {
//    if (b == 0)
//        return a;
//    return gcd(b, a % b);
//}
//
//ll lcm(ll a, ll b) {
//    return a / gcd(a, b) * b;
//}
//
//string toupper(string a) {
//    for (int i = 0; i < (int)a.size(); ++i)
//        if (a[i] >= 'a' && a[i] <= 'z')
//            a[i] -= 32;
//    return a;
//}
//
//string tolower(string a) {
//    for (int i = 0; i < (int)a.size(); ++i)
//        if (a[i] >= 'A' && a[i] <= 'Z')
//            a[i] += 32;
//    return a;
//}
//
//bool prime(ll a) {
//    if (a == 1)
//        return false;
//    for (int i = 2; i <= round(sqrt(a)); ++i)
//        if (a % i == 0)
//            return false;
//    return true;
//}
//
//ll pow(ll a, ll b) {
//    ll res = 1;
//    for (; b; b /= 2, a *= a) {
//        if (b % 2) {
//            res *= a;
//        }
//    }
//    return res;
//}
//
//ll factorial(ll k) {
//    ll res = 1;
//    for (int i = 2; i <= k; i++) {
//        res *= i;
//    }
//    return res;
//}
//
//ll power_MOD (ll base, ll p, ll m) {
//    int res = 1;
//
//    while (p) {
//        if (p % 2 == 1) {
//            res = (res * base) % m;
//            p--;
//        }
//        else {
//            base = (base * base) % m;
//            p = p / 2;
//        }
//    }
//    return res % m;
//}
//
// bool cmp(pair<ll, ll>&a, pair<ll, ll>&b) {
//     if (a.first == b.first) {
//         return a.second > b.second;
//     }
//     return a.first < b.first;
// }

////** Bitwise --> begin
//
//// swap ( x, y ) --> x=x^y, y=x^y, x=x^y
//// if x=a then x=b // if x=b then x=a --> x=a^b^x
//// a+b=(a^b)+2(a&b)
//// a+b=(a|b)+(a&b)
//
//bool check_odd ( ll x ) {
//    return (x & 1); // odd ecen check
//}
//bool check_kth_bit ( ll x, ll k ) {
//    return (x & (1LL<<k));  // k'th bit set or not
//}
//ll set_kth_bit_1 ( ll x, ll k ) {
//    return (x | (1LL<<k));   // make k'th bit 1;
//}
//ll set_kth_bit_0 ( ll x, ll k ) {
//    return (x & ~(1LL<<k));   // make k'th bit 0;
//}
//ll mul_num_by_2_pow_k ( ll x, ll k ) {
//    return (x<<k);   // x*(pow(2,k))
//}
//ll dic_num_by_2_pow_k ( ll x, ll k ) {
//    return (x>>k);   // x/pow(2,k)
//}
//int set_bit_count_int ( int x ) {
//    return __builtin_popcount(x);  // int set bit count
//}
//ll set_bit_count_ll ( ll x ) {
//    return __builtin_popcountll(x); // ll set bit count
//}
//ll toggle_kth_bit ( ll x, ll k ){ // if k = 0 then k = 1
//    return (x ^ ( 1LL <<k ));  // if k = 1 then k = 0
//}
//bool power_of_2 ( ll x ) {
//    return (!(x&(x-1))); // power of 2 checking
//}
//
////** Bitwise --> endl

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    set<ll> st;

    for (int i=0; i<n; i++) {
        if (s[i] == '1') {
            st.insert(i+1);
        }
    }
    cout << st.size() << endl;

    for (auto it: st) {
        cout << it << " ";
    }
    cout << endl;
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