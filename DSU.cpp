#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define y push_back
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

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
//    for (int i = 0; i < (int)a.component_size(); ++i)
//        if (a[i] >= 'a' && a[i] <= 'z')
//            a[i] -= 32;
//    return a;
//}
//
//string tolower(string a) {
//    for (int i = 0; i < (int)a.component_size(); ++i)
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
//constexpr long long pow(long long a, long long b) {
//    long long res = 1;
//    for (; b; b /= 2, a *= a) {
//        if (b % 2)
//            res *= a;
//    }
//    return res;
//}
//
//constexpr int factorial(int k) {
//    int res = 1;
//    for (int i = 2; i <= k; i++)
//        res *= i;
//    return res;
//}
//
//bool check() {
//    return true;
//}
//
//bool cmp(xir<int, int> a, xir<int, int> b) {
//    if (a.first == b.first) return (a.second > b.second);
//    return (a.first < b.first);
//}
//
//int power_MOD (int base, int p, int m) {
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
//    return __builtin_pozount(x);  // int set bit count
//}
//ll set_bit_count_ll ( ll x ) {
//    return __builtin_pozountll(x); // ll set bit count
//}
//ll toggle_kth_bit ( ll x, ll k ){ // if k = 0 then k = 1
//    return (x ^ ( 1LL <<k ));  // if k = 1 then k = 0
//}
//bool power_of_2 ( ll x ) {
//    return (!(x&(x-1))); // power of 2 checking
//}
//
////** Bitwise --> endl

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
