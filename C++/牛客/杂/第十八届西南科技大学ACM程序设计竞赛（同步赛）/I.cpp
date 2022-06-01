// Problem: 醉漾轻舟，信流引到花深处
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/33540/I
// Memory Limit: 524288 MB
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
const int N = 100 + 10;
int n, m, k;
vector<ll> a(N), b(N);

bool check(ll x) {
    vector<ll> c;
    vector<ll> pre, ed;
    pre.reserve(40000), ed.reserve(40000);
    for (int i = 0; i < n; i++) { c.pb(x * b[i] + a[i]); }

    int cur = n / 2;
    for (int i = 0; i < (1 << cur); i++) {
        ll sum = 0;
        for (int j = 0; j < cur; j++) {
            if (i >> j & 1) sum += c[j];
        }
        pre.pb(sum);
    }

    for (int i = 0; i < 1 << (n - cur); i++) {
        ll sum = 0;
        for (int j = 0; j < n - cur; j++) {
            if (i >> j & 1) sum += c[j + cur];
        }
        ed.pb(sum);
    }

    sort(ed.begin(), ed.end());

    ll ans = 0;
    for (int i = 0; i < pre.size(); i++) {
        ll y = m - pre[i];
        int cnt = upper_bound(ed.begin(), ed.end(), y) - ed.begin();
        ans += cnt;
        if (ans >= k) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll l = 0, r = 1e10;
    while (l < r) {
        ll mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
