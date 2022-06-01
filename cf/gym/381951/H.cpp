// Problem: H. Heart of the Swamp
// Contest: Codeforces - HNCPC Multi-university Training Round #9
// URL: https://codeforces.com/gym/381951/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/**
 *    author:  tourist
 *    created: 14.05.2022 16:04:48
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    const long long inf = (long long)1e18;
    long long ans = inf;
    for (int x = 0; x < 2; x++) {
        vector<long long> dp(2, inf);
        dp[x] = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> new_dp(2, inf);
            new_dp[0] = dp[1];
            new_dp[1] = min(dp[0], dp[1]) + a[i];
            swap(dp, new_dp);
        }
        ans = min(ans, dp[x]);
    }
    cout << ans << '\n';
    return 0;
}
