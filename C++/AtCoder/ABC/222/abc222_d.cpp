// Problem: D - Between Two Arrays
// Contest: AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner
// Contest 222） URL: https://atcoder.jp/contests/abc222/tasks/abc222_d Memory
// Limit: 1024 MB Time Limit: 2000 ms
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
const int N = 3000 + 10;

int a[N], b[N], f[N][N], sum[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    f[0][0] = 1;
    for (int i = a[i]; i <= b[i]; i++) {
        f[1][i] = 1, sum[i] = sum[i - 1] + f[1][i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= b[i]; j++) {
            // for (int k = a[i - 1]; k <= j && k <= b[i - 1]; k++) {
            // f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
            // }
        }
    }

    ll ans = 0;
    for (int i = a[n]; i <= b[n]; i++) ans = (ans + f[n][i]) % mod;
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
