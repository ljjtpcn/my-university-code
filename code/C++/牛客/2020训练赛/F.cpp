// Problem: 卷王的木板
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32577/F
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
const int N = 100 + 10;

int vis[N];
void solve() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    s = '!' + s;
    int one, zero;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }

    int f[110][110][2];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            if (s[j] == '0')
                f[i][j][0] = f[i][j - 1][0] + 1, f[i][j][1] = f[i][j - 1][1];
            if (s[j] == '1')
                f[i][j][1] = f[i][j - 1][1] + 1, f[i][j][0] = f[i][j - 1][0];
        }

    int cnt;
    for (int i = 1; i < n; i++)
        if (s[i] != s[i + 1]) cnt++;
    cnt += 1;

    if (t >= n) cout << n, exit(0);
    if (t == 1) cout << max(zero, one), exit(0);
    if (t >= cnt) cout << n, exit(0);

    int ans = 0;
    if (t < cnt) {
        while (t--) {
            pair<pii, int> p = {{0, 0}, 0};
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j++) {
                    if (vis[i] || vis[j]) break;
                    int cur_c = abs(f[i][j][0] - f[i][j][1]);
                    if (p.sec <= cur_c) { p = {{i, j}, cur_c}; }
                }
            }
            int st = p.fir.fir, ed = p.fir.sec, cur = p.sec;
            for (int i = st; i <= ed; i++) vis[i] = 1;
            int len = ed - st + 1;
            ans += (cur + len) / 2;
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