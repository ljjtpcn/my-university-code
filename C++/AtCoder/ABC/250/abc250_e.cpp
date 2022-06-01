// Problem: E - Prefix Equality
// Contest: AtCoder - AtCoder Beginner Contest 250
// URL: https://atcoder.jp/contests/abc250/tasks/abc250_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms

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

int a[N], b[N];
vector<pii> qr, qrc;
map<int, int> mp1, mp2;
map<pii, bool> vis;
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        qr.pb({x, y});
    }
    qrc = qr;
    sort(qr.begin(), qr.end());

    int idx1 = 1, idx2 = 1;
    for (int i = 0; i < qr.size(); i++) {
        auto [x, y] = qr[i];
        while (idx1 <= x) {
            mp1[a[i + 1]] = 1;
            idx1++;
        }
        while (idx2 <= y) {
            mp2[b[i + 1]] = 1;
            idx2++;
        }
        if (mp1.size() == mp2.size()) vis[{x, y}] = true;
    }
    for (auto [x, y] : qrc) {
        if (vis[{x, y}])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    // cout << vis[{2, 3}];
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
