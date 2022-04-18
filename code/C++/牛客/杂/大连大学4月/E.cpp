// Problem: 数圆圈
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/E
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

void solve() {
    ll x, k;
    cin >> x >> k;
    x = abs(x);
    if (x == 0) {
        cout << (k & 1 ? 1 : 0) << endl;
        return;
    }

    int cnt = 0;
    while (k--) {
        if (x == 0) {
            cout << (k & 1 ? 0 : 1) << endl;
            return;
        }
        cnt = 0;
        while (x) {
            int t = x % 10;
            x /= 10;
            if (t == 0) cnt++;
            if (t == 6) cnt++;
            if (t == 9) cnt++;
            if (t == 8) cnt += 2;
        }
        x = cnt;
    }
    cout << cnt << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}