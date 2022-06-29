// Problem: 签到时刻
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/36500/A
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
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s[0] == '8') {
            int a = s[2] - '0';
            a = a * 10 + s[3] - '0';
            if (a <= 5 && a > 0)
                ans1++;
            else if (a > 5)
                ans2++;
        } else if (s[0] == '9') {
            ans2++;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}

// clang-format off
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int __ = 1;
    cin >> __;
    while (__--) { solve(); }
    Please AC;
}

