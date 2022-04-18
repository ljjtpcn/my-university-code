#include <bits/stdc++.h>
#define Please return
#define AC 0
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
#define fir first
#define sec second
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;

int a[N];
int st_min[N][21], st_max[N][21], LOG[N];
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i], st_max[i][0] = st_min[i][0] = a[i];

    auto init = [&]() {
        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                st_min[j][i] =
                    min(st_min[j][i - 1], st_min[j + (1 << (i - 1))][i - 1]);
                st_max[j][i] =
                    max(st_max[j][i - 1], st_max[j + (1 << (i - 1))][i - 1]);
            }
        }

        for (int i = 2; i <= n; ++i) LOG[i] = LOG[i / 2] + 1;
    };
    init();

    auto getMax = [&](int l, int r) {
        int s = LOG[r - l + 1];
        return max(st_max[l][s], st_max[r - (1 << s) + 1][s]);
    };
    auto getMin = [&](int l, int r) {
        int s = LOG[r - l + 1];
        return min(st_min[l][s], st_min[r - (1 << s) + 1][s]);
    };

    auto check1 = [&](int l, int r) {
        int maxx = getMax(l, r);
        int minn = getMin(l, r);
        if (maxx < x || minn > y) return false;
        return true;
    };
    auto check2 = [&](int l, int r) {
        int maxx = getMax(l, r);
        int minn = getMin(l, r);
        if (minn >= y && maxx <= x) return true;
        return false;
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check1(i, mid))
                r = mid;
            else
                l = mid + 1;
        }
        int maxx = getMax(i, l);
        int minn = getMin(i, l);
        if (maxx != x || minn != y) continue;
        int L = l;

        l = i, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check2(i, mid))
                l = mid;
            else
                r = mid - 1;
        }
        int R = l;
        ans += R - L + 1;
    }
    cout << ans;
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}