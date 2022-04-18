// Problem: 全体目光看向我，我宣布个事
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/G
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

map<char, int> mp;
void solve() {
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        mp[c]++;
    }

    int ans = 0;
    char res;
    for (auto [c, cnt] : mp) {
        if (cnt > ans) {
            ans = max(ans, cnt);
            res = c;
        }
    }
    cout << res;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}