#include <bits/stdc++.h>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define endl '\n'

using namespace std;
using LL = long long;

const int N = 100005, M = 50005, mod = 998244353;

struct Node {
    LL rge, fac;
    bool operator<(const Node& a) const { return rge < a.rge; }
};

void solve() {
    LL n, xx;
    cin >> n;
    vector<Node> a(n);
    LL maxx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].rge >> a[i].fac;
        maxx = max(maxx, a[i].rge);
    }
    cin >> xx;
    if (xx >= maxx)
        cout << 1 << endl;
    else {
        LL ans = 0;
        maxx = 0;
        for (int i = 0; i < n; i++) {
            LL x = xx * a[i].fac;
            LL L = max(maxx, x), R = min(a[i].rge - 1, x + a[i].fac - 1);
            maxx = max(maxx, a[i].rge);
            if (L > R) continue;
            ans += R - L + 1;
        }
        cout << ans << endl;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
