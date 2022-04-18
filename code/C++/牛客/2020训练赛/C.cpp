// Problem: 卷王打原魔
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32577/C
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
const int N = 2e4 + 10;
int n, m, s;
map<pii, int> g;
int dist[N];
int vis[N];
int maxx, id = N;

void solve() {
    cin >> n >> m >> s;
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[{x, y}] = 1;
        g[{y, x}] = 1;
    }

    memset(dist, 0x3f, sizeof dist);
    auto bfs = [&]() {
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        dist[s] = 0;
        while (q.size()) {
            auto cur = q.front();
            q.pop();

            for (int i = 1; i <= n; i++) {
                if (!vis[i] && !g.count({cur, i})) {
                    if (dist[i] > dist[cur] + 1) {
                        dist[i] = dist[cur] + 1;
                        if (maxx < dist[i]) {
                            maxx = dist[i];
                            id = i;
                        } else if (dist[i] == maxx)
                            id = min(id, i);
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
    };

    bfs();
    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == 0x3f3f3f3f3f ? -1 : dist[i]) << ' ';
    }
    cout << endl << id;
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}