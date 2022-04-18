// Problem: 造桥
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11224/D
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
const int N = 2e5 + 10;
string s;
int f[26];
void solve() {
    int n;
    cin >> n;
    memset(f, 0, sizeof f);

    for (int i = 1; i <= n; i++) {
        cin >> s;
        int st = s.front() - 'a', ed = s.back() - 'a', len = s.size();
        f[ed] = max(f[ed], f[st] + len);
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) ans = max(ans, f[i]);
    cout << ans << endl;
}

int main() {
    int __ = 1;
    __ = readi();
    while (__--) { solve(); }
    Please AC;
}