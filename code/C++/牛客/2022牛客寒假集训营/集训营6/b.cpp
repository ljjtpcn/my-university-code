#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define cin(a) cin >> a;
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
typedef pair<int,int> pii;
const int mod = 998244353;
const int N = 2e5 + 10;
struct node{int x, cnt;} nd[N];
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}


int n, m, t;
int arr[N], d[N];

void solve(){
    cin >> n;

    int idx = 0;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(idx == 0 || x != nd[idx-1].x){
            nd[++idx] = {x, 1};
        }else{
            nd[idx].cnt++;
        }
    }
    ll ans = 1;
    if(idx == 1){
        cout << inv(2, n) - 1;
        return;
    }
    for (int i = 1; i <= idx; i++){
        if(i == 1 || i == idx){
            ans *= inv(2, nd[i].cnt) - 1;
        }else{
            if((nd[i].x >= nd[i-1].x && nd[i].x <= nd[i+1].x) || (nd[i].x <= nd[i-1].x && nd[i].x >= nd[i+1].x)){
                ans *= inv(2, nd[i].cnt);
            }
            else{
                ans *= (inv(2, nd[i].cnt) - 1);
            }
        }
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