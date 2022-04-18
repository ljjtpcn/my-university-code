#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
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
struct node{
	int x, y, cnt;
};
struct cmp{
	bool operator()(node a, node b){
		return a.cnt > b.cnt;
	}
};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return ans % mod;
}
int n, m;
const int N = 1e5 + 10;
void solve(){
    ull x; cin >> x;
    // bitset<200> s(x);
    // string b = s.to_string();

    // reverse(b.begin(), b.end()); //去前导零
    // for (int i = b.size() - 1; b[i] == '0'; i--) b.pop_back();
    // reverse(b.begin(), b.end());

    // b += b;//构造
    // bitset<200> res(b);
    // cout << res.to_ullong();
    //----------------------//
    cout << ((x << 30) + x) << endl;
}
int main(){
    IOS;
    unsigned
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}