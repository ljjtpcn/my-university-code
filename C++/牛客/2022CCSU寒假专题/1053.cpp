#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5e4 + 10;
const int mod = 19260817;
int n, m;
int dp[N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = x; j <= m; j ++){
            dp[j] = (dp[j] + dp[j - x])% mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}
