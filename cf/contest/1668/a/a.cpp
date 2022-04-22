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
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    ll n, m;
    cin >> n >> m;
    if((n == 1 && m > 2) || (n > 2 && m == 1)){
        cout << -1 << endl;
        return;
    }
    ll minn = min(n, m);
    ll st = max(n, m) - minn + 1;

    ll ans = 0;
    if(st & 1){
        // ans += (st - 1) << 1;
        // ans += (minn - 1) << 1;
        ans += (st + minn - 2) << 1;
    }else{
        // ans += (st - 2) << 1;
        // ans += 1;
        // ans += (minn - 1) << 1;
        ans += ((st + minn - 3) << 1) + 1;
    }
    cout << ans << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}