#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
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
const int N = 2e5 + 10;
pii d[4] = {{0, 1}, {1, 0}, {-1, -1}, {1, -1}};    
map<pii, int> g;
vector<pii> q;
ll maxx, maxy;

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
       ll x, y;
       cin >> x >> y;
       maxx = max(x, maxx);
       maxy = max(y, maxy);
       q.pb({x, y});
       g[{x, y}] = 1;
    }

    
    ll minn; pii res;
    function<void(int, int, int, int, int)> dfs = [&](int x, int y, int row, int col, int i){
        int tx1 = x + row, ty1 = y + col;
        int tx2 = x - row, ty2 = y - col;
        if(tx1 < 0 || ty1 < 0 || tx1 >= maxx + 2 || ty1 >= maxy + 2) return;
        if(tx2 < 0 || ty2 < 0 || tx2 >= maxx + 2 || ty2 >= maxy + 2) return;
        if(g[{tx1, ty1}] != 1){
            int t = abs(row) + abs(col);
            if(minn > t){
                minn = t;
                res = {tx1, ty1};
            }
            return;
        }
        if(g[{tx2, ty2}] != 1){
            int t = abs(row) + abs(col);
            if(minn > t){
                minn = t;
                res = {tx2, ty2};
            }
            return;
        }
        dfs(x, y, row + d[i].fir, col + d[i].sec, i);
    };

    for(auto t : q){
        auto [x, y] = t;
        minn = 1e10;
        for(int i = 0; i < 4; i++) dfs(x, y, 0, 0, i);

        cout << res.fir << ' ' << res.sec << endl;
    }   
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