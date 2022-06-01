#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define ls u << 1
#define rs u << 1 | 1
#define lowbit(x) x & -x
#define pb push_back
#define FOR(i, a, n) for (int i = a; i <= n; i++)

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2e5 + 10;
mt19937_64 mrand(random_device{}());
int f[N][2];  // f[i][0]表示第i个数是0的最小操作次数
int g[N][2];  // g[i][0]表示在最小操作数的前提下的最小段数
int a[N], b[N];
int c[N];

template <typename T>
inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void solve() {
    int n = readI();
    for (int i = 1; i <= n; i++) { scanf("%1d", &c[i]); }
    int cnt = 0;
    for (int i = 1; i <= n; i += 2) {
        if (c[i] != c[i + 1])
            b[++cnt] = 2, a[cnt] = 1;
        else
            b[++cnt] = c[i], a[cnt] = 2;
    }
    if (b[1] == 2) {
        f[1][0] = 1, f[1][1] = 1;
        g[1][0] = 1, g[1][1] = 1;
    } else {
        g[1][0] = g[1][1] = 1;
        f[1][b[1]] = 0, f[1][b[1] ^ 1] = 2;
    }
    for (int i = 2; i <= cnt; i++) {
        if (b[i] == 2) {
            if (f[i - 1][1] > f[i - 1][0]) {
                f[i][0] = f[i - 1][0] + a[i];
                g[i][0] = g[i - 1][0];
                f[i][1] = f[i - 1][0] + a[i];
                g[i][1] = g[i - 1][0] + 1;
            } else if (f[i - 1][1] < f[i - 1][0]) {
                f[i][0] = f[i - 1][1] + a[i];
                g[i][0] = g[i - 1][1] + 1;
                f[i][1] = f[i - 1][1] + a[i];
                g[i][1] = g[i - 1][1];
            } else {
                f[i][0] = f[i - 1][0] + a[i];
                g[i][0] = min(g[i - 1][0], g[i - 1][1] + 1);
                f[i][1] = f[i - 1][0] + a[i];
                g[i][1] = min(g[i - 1][0] + 1, g[i - 1][1]);
            }
        } else if (b[i] == 0) {
            if (f[i - 1][1] > f[i - 1][0]) {
                f[i][0] = f[i - 1][0];
                g[i][0] = g[i - 1][0];
                f[i][1] = f[i - 1][0] + a[i];
                g[i][1] = g[i - 1][0] + 1;
            } else if (f[i - 1][1] < f[i - 1][0]) {
                f[i][0] = f[i - 1][1] + a[i];
                g[i][0] = g[i - 1][1] + 1;
                f[i][1] = f[i - 1][1];
                g[i][1] = g[i - 1][1];
            } else {
                f[i][0] = f[i - 1][0];
                g[i][0] = min(g[i - 1][0], g[i - 1][1] + 1);
                f[i][1] = f[i - 1][0] + 2;
                g[i][1] = min(g[i - 1][0] + 1, g[i - 1][1]);
            }
        } else {
            if (f[i - 1][1] > f[i - 1][0]) {
                f[i][0] = f[i - 1][0] + a[i];
                g[i][0] = g[i - 1][0] + 1;
                f[i][1] = f[i - 1][0];
                g[i][1] = g[i - 1][0];
            } else if (f[i - 1][1] < f[i - 1][0]) {
                f[i][0] = f[i - 1][1];
                g[i][0] = g[i - 1][1];
                f[i][1] = f[i - 1][1] + a[i];
                g[i][1] = g[i - 1][1] + 1;
            } else {
                f[i][0] = f[i - 1][0] + 2;
                g[i][0] = min(g[i - 1][0], g[i - 1][1] + 1);
                ;
                f[i][1] = f[i - 1][0];
                g[i][1] = min(g[i - 1][0] + 1, g[i - 1][1]);
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j < 2; j++) {
            cout << "j = " << f[i][j] << " " << g[i][j] << endl;
        }
    }
    if (f[cnt][0] < f[cnt][1]) {
        printf("%d %d\n", f[cnt][0], g[cnt][0]);
    } else if (f[cnt][1] < f[cnt][0]) {
        printf("%d %d\n", f[cnt][1], g[cnt][1]);
    } else {
        printf("%d %d\n", f[cnt][0], min(g[cnt][1], g[cnt][0]));
    }
}

int main() {
    int t = 1;
    t = read<int>();
    while (t--) solve();
    return 0;
}