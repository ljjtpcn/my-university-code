// Problem: Raksasa的轻功
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/K
// Memory Limit: 524288 MB
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

int arr[N], s1[N], s2[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i], s1[i] = 1, s2[i] = 1;

    for (int i = 1; i <= n; i++) {
        if (arr[i] < arr[i - 1])
            s1[i] = s1[i - 1] + 1;
        else
            s1[i] = 1;
    }

    for (int i = n; i >= 1; i--) {
        if (arr[i] < arr[i + 1])
            s2[i] = s2[i + 1] + 1;
        else
            s2[i] = 1;
    }

    int maxx = 0;
    for (int i = 1; i <= n; i++)
        maxx = max(maxx, s1[i]), maxx = max(maxx, s2[i]);
    cout << maxx - 1;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
