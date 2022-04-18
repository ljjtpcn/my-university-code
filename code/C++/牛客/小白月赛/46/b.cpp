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
#define cin4(a, b, c, d) cin >> a >> b >> c >> d;
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
    vector<int> arr1, arr2;
    int n;cin >> n;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        if(x == 0){
            cout << "NO";
            return;
        }
        if(x < 0) arr1.push_back(x);
        else arr2.push_back(x);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    if(arr1.size() == 0 || arr2.size() == 0){
        cout << "YES";
        return;
    }
    int t1 = arr1[arr1.size()-1], t2 = arr2[0];
    if(t1 + t2 != 0 || (t1 + t2 == 0 && (arr1[0] != t1 || t2 != arr2[arr2.size()-1])))
        cout << "YES";          
    else
        cout << "NO";
}
int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}