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
string s, sub;
int solve(){
    cin >> n >> m;
    cin >> s >> sub;
    map<char, int> mp; mp.clear();
    for (int i = 0; i < sub.size(); i ++){
        mp[sub[i]] = 1;
    }
    map<char, queue<int>> v; v.clear();
    for (int i = 0; i < s.size(); i++){
        if(mp[s[i]]) {
            v[s[i]].push(i);
        }
    }
    int cnt = 0;
    while(1){
        int pre = -1;
        for(int i = 0; i < m; i ++){
            auto &q = v[sub[i]];
            if(q.empty()) return cnt;
            int now;
            while(q.size() && pre != -1 && q.front() < pre){
                    q.pop();
            }
            if(q.empty()) return cnt;
            if(q.size()) now = q.front(), q.pop();
            pre = now;
        }
        cnt++;   
    }
}

int main(){
    IOS;
    int __ = 1;
    cin >> __;
    while(__--){
        cout << solve() << endl;
    }
    return 0;
}