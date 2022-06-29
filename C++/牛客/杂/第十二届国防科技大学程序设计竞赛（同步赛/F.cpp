// Problem: F. This is a number theory problem
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/35627/F
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

    auto check = [&](int x) {
        string s = to_string(x);
        int sum = 0;
        for (int i = 0; i < s.size(); i++) sum += s[i] - '0';

        if (sum == 1) return false;
        for (int i = 2; i < sum; i++) {
            if (sum % i == 0) return false;
        }
        return true;
    };
    ll cur = 1;
    int cnt = 0;
    while (cnt < n) {
        if (check(cur)) cnt++;
        cur++;
    }
    cout << cur - 1;
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

