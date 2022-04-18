// Problem: C - Product
// Contest: AtCoder - AtCoder Beginner Contest 233
// URL: https://atcoder.jp/contests/abc233/tasks/abc233_c
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

const int N = 1e5 + 10;

ll n, x, cnt;
vector<ll> arr[N];

void dfs(int cur, ll sum) {
    if (cur >= n) {
        if (sum == x) {
            cnt++;
            return;
        }
    }
    for (auto k : arr[cur])
        if (1.0 * x / sum >= k) dfs(cur + 1, sum * k);
}
void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int len, k;
        cin >> len;
        while (len--) cin >> k, arr[i].pb(k);
    }

    dfs(0, 1);
    cout << cnt;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}