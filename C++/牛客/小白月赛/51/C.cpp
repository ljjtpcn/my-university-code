// Problem: 零一题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11228/C
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
    int a, b, cnt;
    cin >> a >> b >> cnt;
    int k = cnt / 2;
    if (k > a || k > b) {
        cout << -1;
        return;
    } else {
        string ans = "";
        for (int i = 0; i < k; i++) {
            ans += "01";
            a--, b--;
        }
        if (a & 1 || b & 1) {
            cout << -1;
            return;
        }
        while (a--) ans += "0";
        while (b--) ans += "1";
        cout << ans;
    }
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