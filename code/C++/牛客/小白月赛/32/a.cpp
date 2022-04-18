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
    vector<int> arr(6, 0);
    for(int i  = 0; i < 6; i ++) cin >> arr[i];

    auto check = [&](int i, int j, int k){
        if(i + j > k && i + k > j && j + k > i) return true;
        return false;
    };

    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            for(int k = j + 1; k < 6; k++){
                vector<int> t; t.clear();
                for(int z = 0; z < 6; z++){
                    if(z != i && z != j && z != k) t.push_back(arr[z]);
                }
                if(check(arr[i], arr[j], arr[k]) && check(t[0], t[1], t[2])){
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
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