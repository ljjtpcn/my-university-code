// Problem: D - Weak Takahashi
// Contest: AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner
// Contest 232) URL: https://atcoder.jp/contests/abc232/tasks/abc232_d Memory
// Limit: 1024 MB Time Limit: 2000 ms

#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define pb push_back
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

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 100 + 10;
struct node {
    int x, y, cnt;
    bool operator<(const node& b) const { return cnt < b.cnt; }
};

void solve() {
    int n, m;
    string s[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    int vis[N][N] = {0}, ans = 1;
    auto bfs = [&]() {
        priority_queue<node> q;
        q.push({0, 0, 1});
        while (q.size()) {
            auto [x, y, cnt] = q.top();
            q.pop();

            ans = max(ans, cnt);
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (y + 1 < n && s[x][y + 1] == '.') q.push({x, y + 1, cnt + 1});
            if (x + 1 < n && s[x + 1][y] == '.') q.push({x + 1, y, cnt + 1});
        }
        return ans;
    };

    cout << bfs();
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    return 0;
}