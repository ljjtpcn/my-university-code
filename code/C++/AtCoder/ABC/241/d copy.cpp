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
#define endl '\n'
typedef pair<int,int> pii;
const int mod = 1000000007;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 30010;

int n, m, t;
multiset<ll> st;
void solve(){
    cin >> t;
    while(t--){
        int op;
        cin >> op;
        if(op == 1){
            ll x;
            cin >> x;
            st.insert(x);

        }else if(op == 2){
            ll x, k;
            cin >> x >> k;
            if(st.size() == 0) {
                cout << -1 << endl;
            }else{
                auto it = st.upper_bound(x);
                for (;; it--){      
                    if(it == st.end()) {
                        continue;
                    }
                    if(*it <= x) k--;
                    if(k == 0) {
                        cout << *it << endl;
                        break;
                    }
                    if(it == st.begin()) break;
                }
                if(k > 0) cout << -1 << endl;
            }

        }else if(op == 3){
            ll x, k;
            cin >> x >> k;
            if(st.size() == 0){
                cout << -1 << endl;
            }else{
                auto it = st.lower_bound(x);
                for (; it != st.end(); it++){
                    if(*it >= x) k--;
                    if(k == 0){
                        cout << *it << endl;
                        break;
                    }
                }
                if(k > 0) cout << -1 << endl;
            }
            
        }
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