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
ll st[20], ans;
void init(){
    st[0] = 1;
    for(int i = 1; i <= 15; i++){
        st[i] = st[i - 1] * i;
    }
}



void solve(){
    cin >> n;
    init();
    ans = LLONG_MAX;
    for(int i = 0; i < (1 << 15); i ++){
        ll sum = n, cnt = 0;
        for(int j = 1; j <= 15; j++){
            if((i >> (j - 1)) & 1){
                // if(st[j] == 1 || st[j] == 2) continue;
                sum -= st[j];   
                cnt ++;
            }
        }
        if(sum < 0) continue;
        int t = 0;
        while(sum){
            if(sum & 1) t++;
            sum >>= 1;
        }
        ans = min(ans, cnt + t);
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