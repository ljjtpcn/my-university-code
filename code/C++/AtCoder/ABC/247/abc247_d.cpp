// Problem: D - Cylinder
// Contest: AtCoder - AtCoder Beginner Contest 247
// URL: https://atcoder.jp/contests/abc247/tasks/abc247_d
// Memory Limit: 1024 MB
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

deque<pii> q;
void solve() {
    int m;
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, c;
            cin >> x >> c;
            q.push_back({x, c});
        } else if (op == 2) {
            int c;
            cin >> c;
            ll ans = 0;
            while (c) {
                auto t = q.front();
                q.pop_front();
                if (c >= t.sec) {
                    ans += 1ll * t.sec * t.fir;
                    c -= t.sec;
                } else {
                    ans += 1ll * c * t.fir;
                    t.sec -= c;
                    c = 0;
                    q.push_front({t.fir, t.sec});
                }
            }
            cout << ans << endl;
        }
    }
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}