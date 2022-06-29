#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 4e5 + 10;

int n, m, t, sum, ans;
map<int, int> mp;

void dfs_back(int now){
    if(now == 1){
        ans++;
    }
    for (int i = 1; i <= m; i++){
        if(now - i >= 1 && mp[now - i] == 1){
            dfs_back(now - i);
        }
    }
}
void dfs_go(int now){
    if(now == sum){
        dfs_back(sum);
    }
    for (int i = 1; i <= n; i ++){
        if(now + i <= sum){
            mp[now] = 1;
            dfs_go(now + i);
            mp[now] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t --){
        ans = 0;
        mp.clear();
        cin >> sum >> n >> m;
        dfs_go(1);
        cout << ans << endl;
    }
    return 0;
}
