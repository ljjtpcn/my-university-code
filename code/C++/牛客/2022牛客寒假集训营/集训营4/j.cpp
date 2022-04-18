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
const int N = 30010;

int n, m, t;
int st[N];
map<int, bool> mp;
map<int, int> cnt;
void solve(){
    int l, r;
    cin2(l, r);
    //函数式编程 function<返回类型(参数类型...)> 函数名 = lambda表达式(即函数体)
    function<void(int)> getPirme = [&](int n){
        for (int i = 2; i <= n; i ++){
            if(!st[i]){
                mp[i] = true;//存质数
                for(int j = i << 1; j <= n; j += i) st[j] = true;
            }
        }
    };
    getPirme(r);
    // vector<int> composite; composite.clear();
    ll ans = 1;
    auto add = [&](int x) { 
        map<int, int> current; current.clear();
        vector<int> v; v.clear();
        for (int i = 2; i <= x / i; i ++){
            if(x % i == 0){
                while(x % i == 0){
                    if(current[i] == 0) v.push_back(i);
                    current[i]++;
                    x /= i;
                }
            }
        }
        if(x > 1) {if(current[x] == 0) v.push_back(x); current[x]++;}
        
        for(auto t : v){
            if(current[t] > cnt[t]){
                int k = current[t] - cnt[t];
                ans *= inv(t, k);
                ans %= mod;
                cnt[t] = current[t];
            }
        }
    };
    for (int i = l; i <= r; i ++){
        if(!mp[i]) add(i);
    }
    
    cout << (ans == 1 ? -1 : ans);
}

int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}