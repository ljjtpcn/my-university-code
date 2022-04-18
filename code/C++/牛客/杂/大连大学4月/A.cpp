// Problem: 数据泄露
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/A
// Memory Limit: 524288 MB
// Time Limit: 6000 ms

#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec sec
#define INF 0x3f3f3f3f
using namespace std;
// clang-format off
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on

const int N = 500 + 10;
ll n, m;
ll d[N][N];
// 算法结束后，d[a][b]表示a到b的最短距离
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void init() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(1ll * c, d[a][b]);
    }
    floyd();
    int k;
    cin >> k;
    int arr[N];
    for (int i = 1; i <= k; i++) cin >> arr[i];

    ll ans = 0;

    int pre = 1;
    for (int i = 1; i <= k; i++) {
        if (d[pre][arr[i]] >= INF) {
            cout << -1;
            return;
        }
        ans += d[pre][arr[i]];
        pre = arr[i];
    }
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}