// Problem: H.Spring tree
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/35627/H
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
#define yes cout << "Yes\n"
#define no cout << "No\n"
using namespace std;
using i64 = long long;
constexpr int P = 998244353;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// clang-format on
const int N = 1e5 + 10;

int p[N], v[N];
vector<int> g[N];
ll idx, ans, sum;
ll dfs(int now, int pre) {
    if (g[now].size() == 1) { return p[idx++]; }
    for (auto ne : g[now]) {
        if (ne != pre) sum += dfs(ne, now) + 1;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> p[i]; }
    sort(p + 1, p + n + 1, greater<int>());

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b), g[b].pb(a);
    }

    for (auto ne : g[1]) {
        idx = 1;
        sum = 0;
        ans = max(dfs(ne, 1), ans);
    }
}

// clang-format off
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int __ = 1;
    //cin >> __;
    while (__--) { solve(); }
    Please AC;
}

