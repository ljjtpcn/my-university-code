// Problem: D - 250-like Number
// Contest: AtCoder - AtCoder Beginner Contest 250
// URL: https://atcoder.jp/contests/abc250/tasks/abc250_d
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
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *=a;b >>= 1;}return res;}ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on
const int N = 2e6 + 10;

int primes[N], cnt;  // primes[]存储所有素数
bool st[N];          // st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    get_primes(1000000);
    int ans = 0;

    for (int i = 0; i - 1 < cnt; i++) {
        int l = i + 1, r = cnt - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if ((__int128)primes[i] * primes[mid] * primes[mid] * primes[mid] <=
                n)
                l = mid;
            else
                r = mid - 1;
        }
        if ((__int128)primes[i] * primes[l] * primes[l] * primes[l] <= n)
            ans += l - i;
    }
    cout << ans - 2;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
