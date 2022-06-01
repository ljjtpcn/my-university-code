// Problem: P3372 【模板】线段树 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3372
// Memory Limit: 125 MB
// Time Limit: 1000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define ls(k) (k) << 1
#define rs(k) (k) << 1 | 1
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
const int N = 1e5 + 10;

vector<ll> a(N, 0);
struct node {
    int l, r;
    ll x;
} tr[N << 2];

void build(int p, int l, int r) {
    tr[p].l = l, tr[p].r = r;
    if (l == r) {
        tr[p].x = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tr[p].x = tr[ls(p)].x + tr[rs(p)].x;
}

void modify(int p, int pos, ll x) {
    if(tr[p].l == tr[p].r){
        tr[p].x = x;
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    if(pos <= mid)
}

ll ask(int p, int l, int r) {
    

}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            int a;
            ll b;
            cin >> a >> b;
            change(1, a, b);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ask(1, l, r) << endl;
        }
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
