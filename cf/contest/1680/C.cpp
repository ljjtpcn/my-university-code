// Problem: C. Binary String
// Contest: Codeforces - Educational Codeforces Round 128 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1680/problem/C
// Memory Limit: 512 MB
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

void solve() {
    string s;
    cin >> s;
    int one[N], zero[N], n;
    n = s.size();
    for (int i = 1; i <= n; i++) {
        zero[i] = zero[i - 1] + (s[i - 1] == '0');
        one[i] = one[i - 1] + (s[i - 1] == '1');
    }

    //对于确定的左端点，二分找到最优右端点(即让1与0尽可能的接近)
    auto check = [&](int l, int r) {
        int s0 = zero[r] - zero[l - 1];
        int s1 = one[l - 1] + one[n] - one[r];
        return s0 <= s1;  //如果留下的【i，mid】 里面的0 小于等于 删除的1 则扩大
                          //保留的区间， 即l = mid
    };

    int ans = one[n];  // 初始全删
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(i, mid))
                l = mid;
            else
                r = mid - 1;
        }
        ans =
            min(ans, max(zero[l] - zero[i - 1], one[i - 1] + one[n] - one[l]));
    }
    cout << ans << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}