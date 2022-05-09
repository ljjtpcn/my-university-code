// Problem: E. Replace With the Previous, Minimize
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/E
// Memory Limit: 256 MB
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
const int N = 2e5 + 10;

string s;
int n, k;

vector<pair<char, char>> st;
void solve() {
    cin >> n >> k >> s;

    st.clear();
    // cout << '' - 'a';
    for (int i = 0; i < n; i++) {
        for (auto [l, r] : st) {
            if (s[i] == 'a') continue;
            if (s[i] <= r && s[i] >= l) s[i] = l;
        }
        if (k == 0) continue;
        char c = s[i];
        if (s[i] - 'a' >= k) {
            s[i] -= k;
            k = 0;
            st.pb({s[i], c});
        } else {
            k -= s[i] - 'a';
            s[i] = 'a';
            st.pb({'a', c});
        }
    }
    cout << s << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
