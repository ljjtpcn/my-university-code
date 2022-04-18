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
typedef pair<int,int> pii;
const int mod = 1000000007;
struct node{ll a, p, b, idx, val;};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 1e5 + 10;

ll n, m, s, t;
ll a[N], p[N], b[N];
node nd[N];
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) nd[i] = {a[i], p[i], b[i], i, a[i] - p[i]};

    ll ans = 0;
    for(int j = 0; j < 2; j++){
        vector<ll> v;
        ll pans = 0;
        for(int i = 0; i < n; i++){
            if(b[i] == j){
                pans += max(a[i], 0ll);
                v.push_back(-p[i] - max(a[i], 0ll));
            }else{
                v.push_back(max(a[i], -p[i]));
            }
        }
    }


    

}

int main(){
    IOS;
    int __ = 1;
    //cin >> __;
    while(__--){
        solve();
    }
    return 0;
}