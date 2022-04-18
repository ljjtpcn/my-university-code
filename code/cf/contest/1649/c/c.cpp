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
struct node{ll sumx, sumy, xmaxx, cnt, ymaxx;};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 1e6 + 10;

ll n, m;
map<ll, node> arr[2];

void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j ++){
            ll t;cin >> t;
            auto &tt = arr[0][t];
            tt.sumx += i;
            tt.sumy += j;
            tt.xmaxx = max(i, tt.xmaxx);
            tt.ymaxx = max(j, tt.ymaxx);
            tt.cnt += 1;
        }
    }

    ll sum = 0;
    for(int i = 1; i <= 100000; i++){
        if(arr[0][i].cnt <= 1) continue;
        auto t = arr[0][i];
        // debug3(t.maxx, t.cnt, t.sum);
        sum += (t.xmaxx * (t.cnt - 1) - t.sumx + t.xmaxx);
    }
    for(int i = 1; i <= 100000; i++){
        if(arr[1][i].cnt <= 1) continue;
        auto t = arr[1][i];
        // debug3(t.maxx, t.cnt, t.sum);
        sum += (t.ymaxx * (t.cnt - 1) - t.sumy + t.ymaxx);
    }
    cout << sum;
}

int main(){
    IOS;
    int __ = 1;
    // cin >> __;                         
    while(__--){
        solve();
    }
    return 0;
}