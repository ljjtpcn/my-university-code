// Problem: C. Detective Task
// Contest: Codeforces - Codeforces Round #787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/C
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

int s[4][N];
void solve() {
    string ss;
    cin >> ss;
    memset(s, 0, sizeof s);
    for (int i = 1; i <= ss.size(); i++) {
        s[0][i] = s[0][i - 1], s[1][i] = s[1][i - 1], s[2][i] = s[2][i - 1];
        if (ss[i - 1] == '0') s[0][i]++;
        if (ss[i - 1] == '1') s[1][i]++;
        if (ss[i - 1] == '?') s[2][i]++;
    }

    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= ss.size(); i++) {
        char c = ss[i - 1];
        if (s[1][ss.size()] - s[1][i]) mp[i] = 1;
    }
    for (int i = ss.size(); i >= 1; i--) {
        char c = ss[i - 1];
        if (s[0][i - 1]) mp[i] = 1;
    }

    int cnt = 0;
    for (int i = 1; i <= ss.size(); i++) {
        if (!mp[i]) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
