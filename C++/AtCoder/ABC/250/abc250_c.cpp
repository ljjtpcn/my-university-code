// Problem: C - Adjacent Swaps
// Contest: AtCoder - AtCoder Beginner Contest 250
// URL: https://atcoder.jp/contests/abc250/tasks/abc250_c
// Memory Limit: 1024 MB
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
// clang-format on
const int N = 2e5 + 10;

int p[N], idx[N];
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) p[i] = i, idx[i] = i;

    while (q--) {
        int op;
        cin >> op;
        int id1 = idx[op];
        if (idx[op] < n) {
            int id2 = id1 + 1;
            int val = p[id2];
            swap(p[idx[op]], p[idx[op] + 1]);
            idx[op] = id2;
            idx[val] = id1;
        } else {
            int id2 = id1 - 1;
            int val = p[id2];
            swap(p[idx[op]], p[idx[op] - 1]);
            idx[op] = id2;
            idx[val] = id1;
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i] << ' ';
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
