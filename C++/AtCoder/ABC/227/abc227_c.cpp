// Problem: C - ABC conjecture
// Contest: AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest
// 227) URL: https://atcoder.jp/contests/abc227/tasks/abc227_c Memory Limit:
// 1024 MB Time Limit: 2000 ms
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

ll n;

void solve() {
    cin >> n;

    ll ans = 0;
    for (ll i = 1; i * i * i <= n; i++) {
        for (ll j = i; i * j * j <= n; j++) { ans += n / i / j - j + 1; }
    }
    printf("%lld", ans);
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}