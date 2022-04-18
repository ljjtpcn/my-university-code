// Problem: Raksasa的数字
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32275/N
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

const int N = 1000 + 10;

int arr[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> res;
    for (int i = 0; i <= 31; i++) {
        int one = 0, zero = 0;
        for (int j = 1; j <= n; j++) {
            if ((arr[j] >> i) & 1)
                one++;
            else
                zero++;
        }
        if (zero >= one)
            res.pb(0);
        else
            res.pb(1);
    }
    while (res.size() && res.back() == 0) res.pop_back();
    if (res.size() == 0) res.pb(0);
    // for (auto x : res) cout << x;
    reverse(res.begin(), res.end());
    string s = "";
    for (auto c : res) s.pb((char)('0' + c));
    cout << stoi(s, 0, 2) << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}