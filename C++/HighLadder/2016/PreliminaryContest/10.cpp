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

int p[N];
map<pii, int> mp;

int find(int x) { return p[x] == x ? p[x] : p[x] = find(p[x]); }

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) { p[fa] = fb; }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 1; i <= m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        if (p == 1)
            merge(a, b);
        else
            mp[{a, b}] = 1, mp[{b, a}] = 1;
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        if (!mp[{a, b}])
            if (find(a) == find(b))
                cout << "No problem\n";
            else
                cout << "OK\n";
        else if (find(a) == find(b))
            cout << "OK but...\n";
        else
            cout << "No way\n";
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}