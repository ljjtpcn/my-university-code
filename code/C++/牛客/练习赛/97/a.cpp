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
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 100 + 10;

ll n, m, s, t;
ll arr[N];

vector<pair<int, int>> segs;
vector<int> a1, a2, idx1, idx2;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] & 1) a1.push_back(arr[i]), idx1.push_back(i);
        else a2.push_back(arr[i]), idx2.push_back(i);
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    for(int i = 0; i < a1.size(); i ++){
        segs.push_back({a1[i], idx1[i]});
    }
    for(int i = 0; i < a2.size(); i ++){
        segs.push_back({a2[i], idx2[i]});
    }
    
    sort(segs.begin(), segs.end());
    for(int i = 1; i < segs.size(); i++){
        if(segs[i].second < segs[i - 1].second){
            cout << "No";
            return;
        }
    }
    cout << "Yes";

    

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