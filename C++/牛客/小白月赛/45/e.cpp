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
const int N = 1e5 + 10;

int n, m, t;
int h[N], ne[N], e[N], w[N], idx;
int cu[N];
map<int, int> mp;
ll res;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int root){
    mp[idx] = 1;
    res = max(res, res + cu[root]);
    for(int i = h[idx]; i != -1; i = ne[i]){
        int j = e[i];
        res += w[i];
        if(!mp[j]) dfs(j);
    }
}

void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++) cin >> cu[i];
    for(int i = 0; i < n - 1; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    vector<int> ans;
    for(int i = h[1]; i != -1; i = ne[i]){
        int j = e[i];
        res += w[i];
        dfs(j);
        ans.push_back(res);
        res = 0;
    }
    ans.push_back(cu[1]);
    sort(ans.begin(), ans.end(), greater<int>());
    if(ans[0] <= 0) cout << 0 << endl;
    else{
        ll sum = 0;
        for(int i = 0; i < ans.size(); i ++){
            if(ans[i] < 0) break;
            sum += ans[i];
        }
        cout << sum;
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