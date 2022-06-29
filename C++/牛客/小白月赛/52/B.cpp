// Problem: 牛牛的身高
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/36500/B
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
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    int flag = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - '0' >= 5) {
            s[i + 1]++;
            flag = i + 1;
        }
    }

    if (flag == -1) {
        reverse(s.begin(), s.end());
        cout << s << endl;
    } else if (flag != s.size()) {
        string ans = "";
        for (int i = s.size() - 1; i >= flag; i--) { ans += s[i]; }
        while (ans.size() < s.size()) ans += '0';
        cout << ans << endl;
    } else {
        cout << 1;
        for (int i = 0; i < s.size(); i++) cout << '0';
        cout << endl;
    }
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

