// Problem: E - K-colinear Line
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022（AtCoder Beginner
// Contest 248） URL: https://atcoder.jp/contests/abc248/tasks/abc248_e Memory
// Limit: 1024 MB Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
using namespace std;
// clang-format off
inline void read(int &num) {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    num = s;
}
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

const int N = 2e5 + 10;

map<pii, set<pii>> mp;
vector<pii> arr;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.pb({x, y});
    }

    for (int i = 0; i < n; i++) {
        auto [x1, y1] = arr[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = arr[j];
            int x = x2 - x1, y = y2 - y1;
            int z = abs(__gcd(x, y));
            x /= z;
            y /= z;
            
            mp[{x, y}].insert({x1, y1});
            mp[{x, y}].insert({x2, y2});
        }
    }

    ll ans = 0;
    for (map<pii, set<pii>>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (it->second.size() >= k) ans++;
    }
    cout << ans << endl;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}