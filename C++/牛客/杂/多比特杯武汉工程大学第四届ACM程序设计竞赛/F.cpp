// Problem: 能源收集者
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/33616/F
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
const int N = 1e5 + 10;

vector<int> g[N];
int sum[N], n, x, ans;
pair<int, int> rt = {-1, -1};

int dfs1(int now, int pre, int step) {
    if (step > rt.first) rt = {step, now};

    sum[now] = 1;
    for (auto next : g[now]) {
        if (next == pre) continue;
        sum[now] += dfs1(next, now, step + 1);
    }

    return sum[now];
}

void dfs2(int now, int pre, int s) {
    ans = max(ans, s);
    for (auto next : g[now]) {
        if (next == pre) continue;
        dfs2(next, now, s + sum[next]);
    }
}

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b), g[b].pb(a);
    }

    dfs1(x, -1, 1);
    dfs2(rt.second, -1, 1);
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
