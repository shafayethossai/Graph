#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
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
//bool cmp(pair<int, int> a, pair<int, int> b) {
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

int solve(const vector<string>& grid, int n, int m) {
    int cnt = 0;

    for (int k = 0; k < min(n,m)/2; k++) {
        string full = "";

        for (int j = k; j < m-k; j++) {
            full += grid[k][j];
        }

        for (int i = k + 1; i < n-k; i++) {
            full += grid[i][m - k - 1];
        }

        for (int j = m-k-2; j >= k; j--) {
            full += grid[n-k-1][j];
        }

        for (int i = n-k-2; i > k; i--) {
            full += grid[i][k];
        }

        for (int i = 0; i < full.size(); i++) {
            if (full[i] == '1' &&
                full[(i + 1) % full.size()] == '5' &&
                full[(i + 2) % full.size()] == '4' &&
                full[(i + 3) % full.size()] == '3') {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    fast;

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> v(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> v2(n, vector<int>(k));
    for (int j = 0; j < k; j++) {
        v2[0][j] = v[0][j];
        for (int i = 1; i < n; j++) {
            v2[i][j] = v2[i - 1][j] | v[i][j];
        }
    }

    while (q--) {
        int m;
        cin >> m;
        vector<tuple<int, char, int>> all(m);
        for (int i = 0; i < m; i++) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            all[i] = {r - 1, o, c};
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            bool take = true;
            for (auto& req : all) {
                int r = get<0>(req);
                char o = get<1>(req);
                int c = get<2>(req);
                if ((o == '<' && !(v2[i][r] < c)) || (o == '>' && !(v2[i][r] > c))) {
                    take = false;
                    break;
                }
            }
            if (take) {
                ans = i + 1;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
