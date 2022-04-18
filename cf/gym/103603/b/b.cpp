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
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 500 + 10;

int n,  m, t;
char s[N][N];
void solve(){
    cin >> n;

    
    for(int i = 0; i < n; i ++){
        s[n - 1][i] = 'B';
        s[i][n - 1] = 'B';
    }
    for(int i = 0; i < n; i ++){
        s[n - 2][i] = 'W';
        s[i][n - 2] = 'W';
    }
    int len = n - 2;
    for(int k = 0; k < n - 2; k ++){
        for(int i = k; i < len; i ++){
            s[k][i] = k % 2 == 0 ? 'W' : 'B';
            s[i][k] = k % 2 == 0 ? 'W' : 'B';
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cout << s[i][j];
        }
        cout << endl;
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