// Problem: C. Where is the Pizza?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/C
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
inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
// clang-format on
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int a[N], b[N], c[N], d[N];
int vis[N];
int p[N];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) p[fa] = fb;
}

map<int, int> mp;
void solve() {
    int n;
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), vis[i] = 0, p[i] = i;
    for (int i = 1; i <= n; i++) read(b[i]);
    for (int i = 1; i <= n; i++) read(d[i]);

    ll ans = 1;mp.clear();
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            vis[a[i]] = 1;
            continue;
        }
        if (!d[i])
            merge(a[i], b[i]), vis[d[i]] = 1;
        else {
            merge(a[i], b[i]); 
            if (vis[a[i]])
                vis[b[i]] = 1;
             else if (vis[b[i]])
                vis[a[i]] = 1;
        }
    }
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}