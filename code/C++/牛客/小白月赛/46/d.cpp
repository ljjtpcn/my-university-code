#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
const int N = 1e6 + 10;

vector<pii> g[N];

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> mp(N, 0);
    for(int i = 2; i <= n; i ++){
        int f, d; scanf("%d%d", &f, &d);
        g[f].emplace_back(i, d);
        g[i].emplace_back(f, d);
        if(d == 1) ++mp[f], ++mp[i];
    }

    for(int i = 1; i <= n; i ++){
        int ans = 1;
        for(auto [s, d] : g[i]){
            if(d > 2) continue;
            if(d == 2) {++ans; continue;}
            else if(d == 1){
                ++ans; 
                ans += mp[s] - (mp[s] == 0 ? 0 : 1);
            } 
        }    
        printf("%d\n", ans);
    }
}
int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}