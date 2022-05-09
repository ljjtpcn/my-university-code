// Problem: D. Vertical Paths
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/D
// Memory Limit: 256 MB
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
const int N = 2e5 + 10;

int root, idx, vis[N];
vector<int> g[N], res;
map<int, vector<int>> ans;
void dfs(int now, int pre) {
    if (!vis[now]) res.pb(now), vis[now] = 1;
    for (auto next : g[now]) {
        if (next != pre) dfs(next, now);
    }
    if (g[now].size() <= 1 && res.size()) ans[idx++] = res;
    res.clear();
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == i)
            root = i;
        else {
            g[x].pb(i), g[i].pb(x);
        }
    }
    idx = 0;
    memset(vis, 0, sizeof vis);
    dfs(root, -1);
    cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        cout << ans[i].size() << endl;
        for (auto x : ans[i]) cout << x << ' ';
        cout << endl;
    }
    cout << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
