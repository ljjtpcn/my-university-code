// Problem: 好似喵！好似喵！
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32577/D
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
const int mod = 1e9 + 7;
ll qmi(ll a, ll n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qmi(a, n - 1) * a % mod;
    else {
        ll temp = qmi(a, n / 2) % mod;
        return temp * temp % mod;
    }
}

void solve() {
    ll x, y, t, e, r, n;
    cin >> x >> y >> t >> e >> r >> n;
    if (t == 1) {
        cout << (x + n * e) % mod << ' ' << (y + n * r) % mod;
        return;
    }
    ll fz = (qmi(t, n) - 1) % mod, fm = (t - 1) % mod;
    ll db = fz * qmi(fm, mod - 2) % mod;
    ll res1 = (qmi(t, n) * x % mod + db * e % mod) % mod;
    ll res2 = (qmi(t, n) * y % mod + db * r % mod) % mod;

    cout << res1 << ' ' << res2;
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}