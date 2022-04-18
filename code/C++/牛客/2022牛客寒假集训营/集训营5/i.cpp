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
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 1e6 + 10;

int n, m, q;
ll arr[N], c[N], s[N];
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(i > 1) c[i-1] = arr[i] - arr[i-1];
    }
    sort(c + 1, c + n);
    for (int i = 1; i < n; i++) s[i] = s[i-1] + c[i];
    while (q--)
    {
        int k, t;
        cin >> k >> t;
        int idx = upper_bound(c + 1, c + n, k) - (c + 1);
        ll sum = s[n - 1] - s[idx - 1];
        sum -= k * (n - idx);
        if(sum > 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}