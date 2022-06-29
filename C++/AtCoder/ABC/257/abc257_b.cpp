// Problem: B - 1D Pawn
// Contest: AtCoder - NS Solutions Corporation Programming Contest 2022（AtCoder
// Beginner Contest 257） URL: https://atcoder.jp/contests/abc257/tasks/abc257_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)
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
const int mod = 1e9 + 7;
const int N = 1e3 + 10;

int a[N], b[N];
map<int, int> mp;
void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    mp[a[i]] = 1;
  }

  while (q--) {
    int op;
    cin >> op;
    if (!mp[a[op] + 1] && a[op] + 1 <= n) {
      mp[a[op]] = 0;
      a[op] += 1;
      mp[a[op]] = 1;
    }
  }
  for (int i = 1; i <= k; i++) cout << a[i] << ' ';
}

int main() {
  int __ = 1;
  // scanf("%d", &__);
  while (__--) {
    solve();
  }
  Please AC;
}
