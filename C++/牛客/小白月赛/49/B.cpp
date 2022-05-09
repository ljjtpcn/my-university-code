// Problem: 佛
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11226/B
// Memory Limit: 524288 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
// clang-format on
const int mod = 998244353;
const int N = 200 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    int vis[N] = {0}, mp[N][N] = {0};
    vector<int> arr[N];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            arr[i].pb(x);
            mp[i][x] = 1;
        }
    }

    int ans = n;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= n; j++) {
            if (vis[j]) continue;
            if (mp[j][x] == 0) {
                ans--;
                vis[j] = 1;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
