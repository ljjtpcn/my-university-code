#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define cin1(a) cin >> a;
#define cin2(a, b) cin >> a >> b;
#define cin3(a, b, c) cin >> a >> b >> c;
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef pair<int,int> pii;
const int mod = 1000000007;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 1e6 + 10;

ll n;

void solve(){
   cin >> n;
   vector<ll> v1(n, 0), v2(n, 0); v1.clear() ,v2.clear();
   vector<vector<ll>>mp(2, vector<ll>(n, 0));
   for(int i = 0; i < n; i++){
       cin >> v1[i];
       mp[0][i] = v1[i];
   }
   for(int i = 0; i < n; i++){
       cin >> v2[i];
       mp[1][i] = v2[i];
   }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
   map<pair<int, int>, int> st;
   st[{0, 0}] = 0;
   st[{1, 0}] = 0;
   st[{0, n - 1}] = 0;
   st[{1, n - 1}] = 0;

    ll ans = 0;
    if(!st[{0, 0}]){
        ll t = LLONG_MAX;
        int idx = 0;
        for(int i = 0; i < n; i ++){
            if(t > abs(mp[0][0] - mp[1][i])){
                idx = i;
                t = abs(mp[0][0] - mp[1][i]);
            }
        }
        if(abs(mp[0][0] - mp[1][0]) == t) {
            st[{1, 0}] = 1;
        }else if(abs(mp[0][0] - mp[1][n - 1]) == t){
            st[{1, n - 1}] = 1;
        }
        ans += t;
        
    }
    if(!st[{0, n - 1}]){
        ll t = LLONG_MAX;
        int idx = 0;
        for(int i = n - 1; i >= 0; i --){
            if(t > abs(mp[0][n - 1] - mp[1][i])){
                idx = i;
                t = abs(mp[0][n - 1] - mp[1][i]);
            }
        }
        if(abs(mp[0][n - 1] - mp[1][0]) == t && st[{1, n - 1}] == 1) {
            st[{1, 0}] = 1;
        }else if(abs(mp[0][n - 1] - mp[1][n - 1]) == t && st[{1, 0}] == 1){
            st[{1, n - 1}] = 1;
        }
        ans += t;
    
    }
    if(!st[{1, 0}]){
        ll t = LLONG_MAX;
        int idx = 0;
        for(int i = 0; i < n; i ++){
            if(t > abs(mp[1][0] - mp[0][i])){
                idx = i;
                t = abs(mp[1][0] - mp[0][i]);
            }
        }
        if(abs(mp[0][n - 1] - mp[1][0]) == t && st[{1, n - 1}] == 1) {
            st[{1, 0}] = 1;
        }else if(abs(mp[0][n - 1] - mp[1][n - 1]) == t && st[{1, 0}] == 1){
            st[{1, n - 1}] = 1;
        }
        ans += t;
    }
    
    if(!st[{1, n - 1}]){
        ll t = LLONG_MAX;
        int idx = 0;
        for(int i = n - 1; i >= 0; i --){
            if(t > abs(mp[1][n - 1] - mp[0][i])){
                idx = i;
                t = abs(mp[1][n - 1] - mp[0][i]);
            }
        }
        st[{0, idx}] = 1;
        ans += t;
    }
    cout << ans << endl;
}

int main(){
    IOS;
    int __ = 1;
    cin >> __;                         
    while(__--){
        solve();
    }
    return 0;
}