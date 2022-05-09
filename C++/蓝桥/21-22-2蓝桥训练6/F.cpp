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
const int N = 1000 + 10;

int arr[N], f[N][N];
void solve() {
    // input
    int n, p, t;
    cin >> n >> p >> t;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    // f[i][j]表示跳了j次处于i的位置上,存储到达该位置的最大权值
    // init
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++) f[i][j] = -1e9;
    for (int i = 1; i <= min(p, n); i++) f[i][1] = arr[i];

    // dp
    for (int j = 2; j <= t; j++) {
        for (int i = 1; i <= n + 1; i++) {
            for (int k = 1; k <= p && i > k; k++) {
                f[i][j] = max(f[i][j], f[i - k][j - 1] + arr[i]);
            }
        }
    }

    // output
    cout << f[n + 1][t];
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}