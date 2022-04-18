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

ll n, m, t;
map<ll ,ll> mp;


void solve(){
    for(int i = 1; i <= 8; i ++) {
        int x;
        cin >> x;
        mp[i] = x;
    }
    ll ans = 0;
    for(int i = 1; i <= 8; i ++){
        if(mp[i] < 3) continue;
        if(mp[i] % 3 == 0) {
            int t = mp[i] / 3;
            mp[i + 1] += t;
            ans += mp[i] * i;
        }else if(mp[i] % 3 == 1){
            int t = mp[i] / 3;
            mp[i + 1] += t;
            ans += mp[i] * i;
            
        }else if(mp[i] % 3 == 2){
            int t = mp[i] / 3;
            if(t > 0) {ans += 4 * i; t--; mp[i + 1] ++;} 
            if(t > 0) {ans += 4 * i; t--; mp[i + 1] ++;} 
            mp[i + 1] += t;
            ans += t * 3 * i;
        }
    }
    cout << ans;
}

int main(){
    IOS;
    int __ = 1;                            
    while(__--){
        solve();
    }
    return 0;
}

/******************************
 * 
 * #include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll a[10],ans;
void solve()
{   
    for(int i=1;i<=8;i++) cin>>a[i];
    for(ll i=1;i<=8;i++)
    {
        if(a[i]<3) continue;
        if(a[i]%3==0)
        {
            a[i+1] += a[i]/3;
            ans += a[i]*i;
        }
        else if(a[i]%3==1)
        {
            a[i+1] += a[i]/3;
            ans += a[i]*i;
        }
        else if(a[i]%3==2)
        {
            if(a[i]>=8)
            {
                a[i+1] += a[i]/3;
                ans += a[i]*i;
            }
            else
            {
                a[i+1] ++;
                ans += 4*i;
            }
        }
    }
    printf("%lld",ans);
}
int main()
{
    solve();
    return 0;
}

 * */