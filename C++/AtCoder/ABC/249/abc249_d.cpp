// Problem: D - Index Trio
// Contest: AtCoder - Monoxer Programming Contest 2022（AtCoder Beginner Contest
// 249） URL: https://atcoder.jp/contests/abc249/tasks/abc249_d Memory Limit:
// 1024 MB Time Limit: 2000 ms
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
const int N = 2e5 + 10;

ll arr[N];
map<ll, ll> mp;
void solve() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }


    ll sum = 0;
    for (auto it : mp) {
        ll x = it.fir, cnt = it.sec;
        for (ll i = 1; i <= x / i; i++) {
            if (x % i == 0) {
                ll z = x / i;
                sum += mp[i] * mp[z] * cnt * (z == i ? 1 : 2);
            }
        }
    }
    cout << sum;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
