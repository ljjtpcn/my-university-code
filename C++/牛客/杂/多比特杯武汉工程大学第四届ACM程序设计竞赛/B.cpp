// Problem: 阶乘求导
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/33616/B
// Memory Limit: 524288 MB
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
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
// clang-format on
const int mod = 998244353;
const int N = 1e6 + 10;

double f[N];
void init() {
    f[1] = 1.0;
    for (int i = 2; i <= N + 1; i++) { f[i] += f[i - 1] + 1.0 / i; }
}

void solve() {
    int n;
    cin >> n;

    printf("%.6lf\n", n == 1 ? -0.5772156649015 : -0.5772156649015 + f[n - 1]);
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    init();
    while (__--) { solve(); }
    Please AC;
}
