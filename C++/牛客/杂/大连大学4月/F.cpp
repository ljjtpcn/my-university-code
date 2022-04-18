// Problem: 旅行
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/F
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
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

const int mod = 1e9 + 7;
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on

const int N = 3e3 + 10;
vector<pii> g[N];
int dist[N], st[N], mp[N];
vector<int> pre[N];

void dij() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    dist[1] = 0;

    while (q.size()) {
        auto [distance, now] = q.top();
        q.pop();

        if (st[now]) continue;
        st[now] = 1;

        for (auto [next, d] : g[now]) {
            if (dist[next] > distance + d) {
                dist[next] = distance + d;
                q.push({dist[next], next});

                pre[next].clear();
                pre[next].pb(now);
            }
            if (dist[next] == distance + d) { pre[next].pb(now); }
        }
    }
}

void dfs(int now) {
    mp[now] = 1;
    for (auto next : pre[now]) { dfs(next); }
}
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
    }

    dij();
    dfs(n);

    while (k--) {
        int x;
        cin >> x;
        if (mp[x])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
