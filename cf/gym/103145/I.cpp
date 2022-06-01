// Problem: I. Takeaway
// Contest: Codeforces - The 15th Chinese Northeast Collegiate Programming
// Contest URL: https://codeforces.com/gym/103145/problem/I Memory Limit: 256 MB
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
struct Z {int x;Z(int x = 0) : x(norm(x)) {}Z(i64 x) : x(norm(x % P)) {}int val() const { return x; }Z operator-() const { return Z(norm(P - x)); }Z inv() const {assert(x != 0);return power(*this, P - 2);}Z &operator*=(const Z &rhs) {x = i64(x) * rhs.x % P;return *this;}Z &operator+=(const Z &rhs) {x = norm(x + rhs.x);return *this;}Z &operator-=(const Z &rhs) {x = norm(x - rhs.x);return *this;}Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }friend Z operator*(const Z &lhs, const Z &rhs) {Z res = lhs;res *= rhs;return res;}friend Z operator+(const Z &lhs, const Z &rhs) {Z res = lhs;res += rhs;return res;}friend Z operator-(const Z &lhs, const Z &rhs) {Z res = lhs;res -= rhs;return res;}friend Z operator/(const Z &lhs, const Z &rhs) {Z res = lhs;res /= rhs;return res;}friend std::istream &operator>>(std::istream &is, Z &a) {i64 v;is >> v;a=Z(v);return is;}};ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *=a;b >>= 1;}return res;}ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on
const int N = 2e5 + 10;

int op[10] = {0, 7, 27, 41, 49, 63, 78, 108};
void solve() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        sum += op[idx];
    }
    if (sum >= 120)
        cout << sum - 50 << endl;
    else if (sum >= 89)
        cout << sum - 30 << endl;
    else if (sum >= 69)
        cout << sum - 15 << endl;
    else
        cout << sum << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}  // Time Limit: 10000 ms
