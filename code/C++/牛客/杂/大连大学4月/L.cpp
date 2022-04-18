// Problem: 函数求和
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/L
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

inline void read(int &num) {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    num = s;
}
const int N = 1e7 + 10;

int l[N];
void solve() {
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(l[i]);

    ll ans = 0;
    while (m--) {
        int i;
        read(i);
        if (i == l[i])
            ans = ans + i % mod;
        else
            ans = ans + 1 % mod;
    }
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}