// Problem: C - Dice Sum
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022（AtCoder Beginner
// Contest 248） URL: https://atcoder.jp/contests/abc248/tasks/abc248_c Memory
// Limit: 1024 MB Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
using namespace std;
// clang-format off
inline void read(int &num) {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    num = s;
}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 998244353;
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on

const int N = 50 + 10;

ll dp[N * N][N * N];

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    //前I个最大元素,he wei j的方案
    // for (int i = 1; i <= m; i++) dp[1][i] = 1;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= m; x++) {
                if (j >= x) dp[i][j] = dp[i][j] + dp[i - 1][j - x] % mod;
            }
        }
    }
    ll ans = 0;
    for (int i = n; i <= k; i++) { ans = (ans + dp[n][i]) % mod; }
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}