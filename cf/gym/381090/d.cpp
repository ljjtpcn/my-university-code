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
const int N = 1000 + 10;
struct cir {
    int x, y, r, id;
} nd[N];

int length(cir a, cir b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool check(cir a, cir b) { return length(a, b) == (a.r + b.r) * (a.r + b.r); }

int n, order[N], vis[N];
string ss[] = {"counterclockwise", "clockwise"};

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nd[i].x >> nd[i].y >> nd[i].r;
        nd[i].id = i;
        order[i] = vis[i] = 0;
    }

    auto bfs = [&]() {
        queue<cir> q;
        q.push(nd[1]);
        order[1] = 1;
        vis[1] = 1;

        while (q.size()) {
            auto now = q.front();
            q.pop();

            for (int i = 1; i <= n; i++) {
                auto next = nd[i];
                if (now.id == next.id || vis[next.id]) continue;

                if (check(now, next)) {
                    q.push(next);
                    vis[next.id] = 1;
                    order[next.id] = !order[now.id];
                }
            }
        }
    };

    bfs();

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
            cout << "not moving\n";
        else {
            int d = __gcd(nd[1].r, nd[i].r);
            if (nd[1].r % nd[i].r == 0) {
                cout << nd[1].r / nd[i].r << " " << ss[order[nd[i].id]] << endl;
            } else {
                cout << nd[1].r / d << '/' << nd[i].r / d << " "
                     << ss[order[nd[i].id]] << endl;
            }
        }
    }
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}