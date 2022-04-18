// Problem: 卷王的服装店终于终于开业啦
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32577/A
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
#define fir first
#define sec second
using namespace std;

template <typename T>
inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void split(const string& s, vector<string>& tokens, const string& delimiters) {
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(
            s.substr(lastPos, pos - lastPos));  // use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}
struct node {
    int x, y, cnt;
};
struct cmp {
    bool operator()(node a, node b) { return a.cnt > b.cnt; }
};
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 10;

void solve() {
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    if (d == 0) cout << 0, exit(0);

    ll ans = 0;
    vector<pii> v;
    v.pb({e, a}), v.pb({f, b}), v.pb({g, c});
    sort(v.begin(), v.end(), greater<pii>());

    for (auto t : v) {
        if (d == 0) break;
        auto [pri, cnt] = t;
        if (d >= cnt) {
            ans += 1ll * cnt * pri;
            d -= cnt;
        } else {
            ans += 1ll * d * pri;
            d = 0;
            break;
        }
    }
    cout << ans;
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}
    