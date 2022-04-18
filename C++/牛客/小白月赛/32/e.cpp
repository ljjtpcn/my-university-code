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
const int mod = 1000000007;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};

ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 30010;


void solve(){
    ll n, a, b;
    cin3(n, a, b);
    ll ans1 = n / 2 * a + (n % 2 == 0 ? 0 : min(a, b));
    ll ans2 = n / 3 * b + (n % 3 == 0 ? 0 : min(a, b));
    ll ans3 = (n + 2 - 1) / 2 * a;
    
    ll ans4 = (n + 3 - 1) / 3 * b;
    ll ans5 = LLONG_MAX;
     if(n >= 4) ll ans5 = (n - 4 + 3 - 1) / 3 * b + 2 * a;
//     debug4(ans1, ans2, ans3, ans4);
    cout << min(ans1, min(ans2, min(ans3, min(ans4, ans5)))) << endl;
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