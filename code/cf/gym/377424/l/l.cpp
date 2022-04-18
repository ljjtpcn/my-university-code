#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;

ll ans = 0;
unordered_map<ll, bool> mp;
int flag;
ll dfs(ll n){
    if(mp[n]) {
        flag = 1;
        return 0;
    }
    mp[n] = 1;
    if(n == 2) return 2;
    if(n == 3) return 24;
    if(n == 4) return 6;
    if(n == 5) return 20;
    if(n == 6) return 30;
    if(n == 7) return 128;
    if(n == 8) return 14;
    if(n == 9) return 152;
    if(n == 10) return 30;
    if(n % 2 == 0){
        return n + dfs(n / 2);
    }else{
        return n + 1 + dfs(n / 2 + 1 + n);
    }
}

void solve() {
    int n;
    cin >> n;
    ans = dfs(n);  
    if(flag) ans = -1;  
    cout << ans;
}
// clang-format on

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) {
        solve();
    }
    return 0;
}