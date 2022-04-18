// Problem: 突然的自我
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/J
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

const ll mod = 114514919810;
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on

const int N = 1e6 + 10;

ll f[N], s[N];

int main() {
    int __ = 1;
    scanf("%d", &__);
    f[1] = f[2] = 1;
    for (int i = 3; i < N; i++) f[i] = (f[i - 1] + f[i - 2] % mod + 1) % mod;
    for (int i = 1; i < N; i++) { s[i] = (s[i - 1] + f[i]) % mod; }
    while (__--) {
        int n;
        cin >> n;
        cout << s[n] << endl;
    }
    Please AC;
}