// Problem: A - Jogging
// Contest: AtCoder - Monoxer Programming Contest 2022（AtCoder Beginner Contest
// 249） URL: https://atcoder.jp/contests/abc249/tasks/abc249_a Memory Limit:
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

void solve() {
    int a1, b1, c1, a2, b2, c2, x;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> x;
    int t1 = x / (a1 + c1), t2 = x / (a2 + c2);
    int ans1 = 0, ans2 = 0;
    ans1 = t1 * a1 * b1 + min(a1, x - t1 * (a1 + c1)) * b1;
    ans2 = t2 * a2 * b2 + min(a2, x - t2 * (a2 + c2)) * b2;

    if (ans1 > ans2)
        cout << "Takahashi";
    else if (ans1 == ans2)
        cout << "Draw";
    else
        cout << "Aoki";
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
