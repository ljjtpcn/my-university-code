// Problem: B. Stone Age Problem
// Contest: Codeforces - Codeforces Round #791 (Div. 2)
// URL: https://codeforces.com/contest/1679/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using i64 = long long;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int P = 998244353;
int norm(int x) {if (x < 0) { x += P; }if (x >= P) { x -= P; }return x;}inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}template <class T>T power(T a, i64 b) {T res = 1;for (; b; b /= 2, a *= a) {if (b % 2) { res *= a; }}return res;}
struct Z {int x;Z(int x = 0) : x(norm(x)) {}Z(i64 x) : x(norm(x % P)) {}int val() const { return x; }Z operator-() const { return Z(norm(P - x)); }Z inv() const {assert(x != 0);return power(*this, P - 2);}Z &operator*=(const Z &rhs) {x = i64(x) * rhs.x % P;return *this;}Z &operator+=(const Z &rhs) {x = norm(x + rhs.x);return *this;}Z &operator-=(const Z &rhs) {x = norm(x - rhs.x);return *this;}Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }friend Z operator*(const Z &lhs, const Z &rhs) {Z res = lhs;res *= rhs;return res;}friend Z operator+(const Z &lhs, const Z &rhs) {Z res = lhs;res += rhs;return res;}friend Z operator-(const Z &lhs, const Z &rhs) {Z res = lhs;res -= rhs;return res;}friend Z operator/(const Z &lhs, const Z &rhs) {Z res = lhs;res /= rhs;return res;}friend std::istream &operator>>(std::istream &is, Z &a) {i64 v;is >> v;a=Z(v);return is;}};
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *=a;b >>= 1;}return res;}ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on
const int N = 2e5 + 10;
int v[N];
ll arr[N];
void solve() {
    int n, q;
    cin >> n >> q;
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i], sum += arr[i];

    ll ne, cnt = 0;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx, x;
            cin >> idx >> x;

            if (v[idx] < cnt) {
                v[idx] = cnt;
                arr[idx] = ne;
            }
            sum = sum + (x - arr[idx]);
            arr[idx] = x;
            cout << sum << endl;

        } else {
            cin >> ne;
            cnt++;
            sum = ne * n;
            cout << sum << endl;
        }
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
