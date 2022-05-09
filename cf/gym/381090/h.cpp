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

vector<int> arr;
int flag[100][100];
void init() {
    for (int i = 1; i <= 19; i++) arr.pb(i);

    for (int i = 0; i <= 9; i++) flag[1][i] = 1;
    flag[2][2] = flag[2][3] = flag[2][5] = flag[2][6] = flag[2][8] =
        flag[2][9] = flag[2][0] = 1;
    flag[3][3] = flag[3][6] = flag[3][9] = 1;
    flag[4][4] = flag[4][5] = flag[4][6] = flag[4][8] = flag[4][9] =
        flag[4][0] = 1;
    flag[5][5] = flag[5][6] = flag[5][8] = flag[5][9] = flag[5][0] = 1;
    flag[6][6] = flag[6][9] = 1;
    flag[7][7] = flag[7][8] = flag[7][9] = flag[7][0] = 1;
    flag[8][8] = flag[8][9] = flag[8][0] = 1;
    flag[9][9] = flag[0][0] = 1;
    for (int i = 20; i <= 999; i++) {
        string s = to_string(i);
        bool f = false;
        for (int i = 1; i < s.size(); i++) {
            int pre = s[i - 1] - '0', now = s[i] - '0';
            if (!flag[pre][now]) f = true;
        }
        if (!f) arr.pb(i);
    }
    // for (auto x : arr) cout << x << endl;
}
void solve() {
    int n;
    cin >> n;

    sort(arr.begin(), arr.end());
    int l = *--lower_bound(arr.begin(), arr.end(), n);
    int r = *lower_bound(arr.begin(), arr.end(), n);
    int d1 = abs(l - n), d2 = abs(r - n);
    cout << (d1 < d2 ? l : r) << endl;
}

int main() {
    int __ = 1;

    init();

    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}