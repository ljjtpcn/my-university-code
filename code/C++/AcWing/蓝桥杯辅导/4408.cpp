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

const int N = 500 + 10;
int s[N][N];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j];
        }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int l = 1, r = 1, sum = 0; r <= m; r++) {
                sum += s[j][r] - s[i - 1][r];
                while (sum > k) {
                    sum -= s[j][l] - s[i - 1][l];
                    l++;
                }
                ans += r - l + 1;
            }
        }
    }
    cout << ans;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}