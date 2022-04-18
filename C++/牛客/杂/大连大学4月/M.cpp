// Problem: Raksasa的棋局
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/M
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

const int N = 1000 + 10;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int mp[N][N];
vector<int> qu[N][N];
int ans[N];
pii st;
int n, m, Q;
void solve() {
    cin >> n >> m >> Q;

    cin >> st.fir >> st.sec;

    auto bfs = [&]() {
        queue<array<int, 3>> q;
        q.push({st.fir, st.sec, 0});
        while (q.size()) {
            auto [x, y, cnt] = q.front();
            q.pop();
            if (qu[x][y].size())
                for (auto id : qu[x][y]) ans[id] = cnt;

            if (mp[x][y]) continue;
            mp[x][y] = 1;

            for (int i = 0; i < 8; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !mp[tx][ty]) {
                    q.push({tx, ty, cnt + 1});
                }
            }
        }

        for (int i = 1; i <= Q; i++) {
            cout << (ans[i] == 0 ? -1 : ans[i]) << endl;
        }
    };

    for (int i = 1; i <= Q; i++) {
        int x, y;
        cin >> x >> y;
        qu[x][y].pb(i);
    }
    bfs();
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}