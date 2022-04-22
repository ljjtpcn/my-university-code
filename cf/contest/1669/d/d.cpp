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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b, w, r;
    b = w = r = 0;
    vector<int> arr;
    for (auto c : s) {
        if (c == 'W') {
            if ((r == 0 && b != 0) || (b == 0 && r != 0)) {
                cout << "NO\n";
                return;
            }
            b = 0, r = 0;
        } else if (c == 'R')
            r++;
        else if (c == 'B')
            b++;
    }
    if ((r == 0 && b != 0) || (b == 0 && r != 0))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}