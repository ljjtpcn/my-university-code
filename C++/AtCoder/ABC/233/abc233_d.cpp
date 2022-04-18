// Problem: D - Count Interval
// Contest: AtCoder - AtCoder Beginner Contest 233
// URL: https://atcoder.jp/contests/abc233/tasks/abc233_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec sec
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

const int N = 2e5 + 10;
ll s[N];
map<ll, ll> mp;
void solve() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        mp[s[i - 1]]++;
        ans += mp[s[i] - k];
    }
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}