// Problem: B. Beautiful Graph
// Contest: Codeforces - HNCPC Multi-university Training Round7
// URL: https://codeforces.com/gym/103676/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int N = 1000 + 10;

void solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].fir, arr[i].sec = i;
    sort(arr.begin(), arr.end(), greater<pii>());
    // for (auto [x, y] : arr) cout << x << ' ' << y << endl;
    // cout << "_______" << endl;

    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        sort(arr.begin(), arr.end(), greater<pii>());
        auto &[val, idx] = arr[i];
        for (int j = i + 1; j < n; j++) {
            auto &[ne_val, ne_idx] = arr[j];
            if (val && ne_val) {
                val--, ne_val--;
                ans.pb({idx, ne_idx});
            }
        }
        if (val) cout << -1, exit(0);
    }
    // for (auto [x, y] : arr) cout << x << ' ' << y << endl;
    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x + 1 << ' ' << y + 1 << endl;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}