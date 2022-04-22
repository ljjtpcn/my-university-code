// Problem: C - Choose Elements
// Contest: AtCoder - AtCoder Beginner Contest 245
// URL: https://atcoder.jp/contests/abc245/tasks/abc245_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

int a[N], b[N];
int f[N][2];

void solve(){
    int n, k;
    cin2(n, k);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    f[1][0] = 1, f[1][1] = 1;
    for (int i = 1; i < n; i++){
        if((f[i][0] && abs(a[i] - a[i + 1]) <= k) || (f[i][1] && abs(b[i] - a[i + 1]) <= k))
            f[i + 1][0] = 1;
        if((f[i][0] && abs(a[i] - b[i + 1]) <= k) || (f[i][1] && abs(b[i] - b[i + 1]) <= k))
            f[i + 1][1] = 1;  
        
    }
    if(f[n][0] || f[n][1])
        cout << "Yes";
    else 
        cout << "No";
}
int main(){
    IOS;
    int __ = 1;                            
    while(__--){
        solve();
    }
    return 0;
}