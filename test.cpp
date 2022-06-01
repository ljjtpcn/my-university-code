#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef int_fast64_t ll;

#define print(a) \
    for (auto& _ : a) cout << _ << " ";
#define input(a) \
    for (auto& _ : a) cin >> _;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define int ll

using namespace std;

const ll INF = 4e18, MOD = 1e9 + 7, MOD2 = 998244353, LOG = 30;
const long double EPS = 1e-9, PI = acos(-1);

template <typename T>
bool assign_max(T& a, T b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool assign_min(T& a, T b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { cin >> a[i][j]; }
    }
    map<int, long long> sum1, sum2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum1[i + j] += a[i][j];
            sum2[i - j] += a[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = max(ans, sum1[i + j] + sum2[i - j] - a[i][j]);
        }
    }
    cout << "n = " << n << " m = " << m << '\n';
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
