// Problem: 环上食虫
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11229/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define yes cout << "Yes\n"
#define no cout << "No\n"
using namespace std;
using i64 = long long;
constexpr int P = 998244353;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// clang-format on
const int N = 2e5 + 10;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(2 * n + 1, 0);
    vector<int> b(2 * n + 1, 0);

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i + n] = b[i];
    }

    if (sum < s) {
        cout << -1 << endl;
        return;
    }

    auto check = [&](int mid) {
        int cur = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (b[i] <= mid) {
                cur += a[i];
                if (cur >= s) return true;
            } else {
                cur = 0;
            }
        }

        if (cur >= s) return true;
        return false;
    };

    // enum all ans
    int l = 1, r = 1e9 + 10;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

// clang-format off
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int __ = 1;
    //cin >> __;
    while (__--) { solve(); }
    Please AC;
}