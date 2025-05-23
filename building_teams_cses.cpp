#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)
 
// int gcd(int a, int b) {
//     if(b == 0) {
//         return a;
//     }
//     else {
//         return gcd (b, a%b);
//     }
// }
 
// ll lcm(ll a, ll b) { 
//     return a / gcd(a, b) * b; 
// }
 
// string toupper(string a) { 
//     for (int i = 0; i < (int)a.size(); ++i) 
//         if (a[i] >= 'a' && a[i] <= 'z') 
//             a[i] -= 32; 
//     return a; 
// }
 
// string tolower(string a) { 
//     for (int i = 0; i < (int)a.size(); ++i) 
//         if (a[i] >= 'A' && a[i] <= 'Z') 
//             a[i] += 32; 
//     return a; 
// }
 
// bool prime(ll a) { 
//     if (a == 1) 
//         return false; 
//     for (int i = 2; i <= round(sqrt(a)); ++i) 
//         if (a % i == 0) 
//             return false; 
//     return true; 
// }
 
// constexpr long long pow(long long a, long long b) {
//     long long res = 1;
//     for (; b; b /= 2, a *= a) {
//         if (b % 2)
//             res *= a;
//     }
//     return res;
// }
 
// constexpr int factorial(int k) {
//     int res = 1;
//     for (int i = 2; i <= k; i++)
//         res *= i;
//     return res;
// }
 
// bool check() {
//     return true;
// }
 
// bool cmp(pair<int, int> a, pair<int, int> b) {
//     if (a.first == b.first) return (a.second > b.second);
//     return (a.first < b.first);
// }
 
// int power_MOD (int base, int p, int m) {
//     int res = 1;
 
//     while (p) {
//         if (p % 2 == 1) {
//             res = (res * base) % m;
//             p--;
//         }
//         else {
//             base = (base * base) % m;
//             p = p / 2;
//         }
//     }
//     return res % m;
// }
 
// //** Bitwise --> begin
 
// // swap ( x, y ) --> x=x^y, y=x^y, x=x^y
// // if x=a then x=b // if x=b then x=a --> x=a^b^x
// // a+b=(a^b)+2(a&b)
// // a+b=(a|b)+(a&b)
 
// bool check_odd ( ll x ) {
//     return (x & 1); // odd ecen check
// }
// bool check_kth_bit ( ll x, ll k ) {
//     return (x & (1LL<<k));  // k'th bit set or not
// }
// ll set_kth_bit_1 ( ll x, ll k ) {
//     return (x | (1LL<<k));   // make k'th bit 1;
// }
// ll set_kth_bit_0 ( ll x, ll k ) {
//     return (x & ~(1LL<<k));   // make k'th bit 0;
// }
// ll mul_num_by_2_pow_k ( ll x, ll k ) {
//     return (x<<k);   // x*(pow(2,k))
// }
// ll dic_num_by_2_pow_k ( ll x, ll k ) {
//     return (x>>k);   // x/pow(2,k)
// }
// int set_bit_count_int ( int x ) {
//     return __builtin_popcount(x);  // int set bit count
// }
// ll set_bit_count_ll ( ll x ) {
//     return __builtin_popcountll(x); // ll set bit count
// }
// ll toggle_kth_bit ( ll x, ll k ){ // if k = 0 then k = 1
//     return (x ^ ( 1LL <<k ));  // if k = 1 then k = 0
// }
// bool power_of_2 ( ll x ) {
//     return (!(x&(x-1))); // power of 2 checking
// }
 
//** Bitwise --> endl

const int N = 100007;
vector<int> graph[N];
vector<int> vis(N+1, 0), col(N+1);
bool possible;

void dfs(int node, int p) {
	for (auto child : graph[node]) {
        if (child != p) {
            if (!vis[child]) {
                col[child] = !col[node];
                vis[child] = 1;
                dfs(child, node);
            }
            else {
                if (col[child] == col[node]) {
                    possible = false;
                }
            }
        }
    }
}

int main() {
    fast;
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].pb(v);
    	graph[v].pb(u);
    }
    possible = true;

    for (int i=1; i<n; i++) {
    	if (!vis[i]) {
            vis[i] = 1;
    		dfs(i, 0);
    	}
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (int i=1; i<=n; i++) {
            if (col[i] == 0) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }

    return 0;
}