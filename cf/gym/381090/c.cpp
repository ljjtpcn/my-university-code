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
ll n, a, b;
bool check(ll x) {
    ll rs = x * x + x - 2 * n;
    for (ll i = sqrt(rs); i >= 1; i--) {
        if (rs % i == 0) {
            if (i * (i - 1) == rs) {
                a = i;
                return true;
            } else
                return false;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    if (n & 1) {
        printf("%lld = %lld + %lld\n", n, n / 2, n / 2 + 1);
    } else {
        ll l = 1, r = n;
        while (l < r) {
            ll mid = l + r + 1 >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        b = l;
        if ((a + b) * (b - a + 1) / 2 == n) {
            printf("%lld =", n);
            for (ll i = a; i <= b; i++) {
                cout << ' ' << i;
                if (i != b) cout << " + ";
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}