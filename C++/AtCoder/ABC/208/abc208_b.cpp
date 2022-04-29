// Problem: B - Factorial Yen Coin
// Contest: AtCoder - AtCoder Beginner Contest 208
// URL: https://atcoder.jp/contests/abc208/tasks/abc208_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
const int N = 2e3 + 10;

ll arr[N];
void solve() {
    ll n;
    cin >> n;
    arr[1] = 1;
    for (int i = 2; i <= 20; i++) { arr[i] = i * arr[i - 1]; }
    int cnt = 0;
    while (n) {
        int l = 1, r = 20;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (arr[mid] > n)
                r = mid - 1;
            else
                l = mid;
        }
        n -= arr[l];
        cnt++;
    }
    cout << cnt;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
