
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
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 1e6 + 10;

int n, k, arr[N];

struct node{
    int l, r, maxx, minn;
} t[N * 4];

void build(int p, int l, int r){
    t[p].l = l, t[p].r = r;
    if(l == r){
        t[p].maxx = arr[l];
        t[p].minn = arr[l];
        return;
    }

    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    t[p].maxx = max(t[p << 1].maxx, t[p << 1|1].maxx);
    t[p].minn = min(t[p << 1].minn, t[p << 1|1].minn);
}

pii Query(int p, int l, int r){
    // pii ret = {INT_MIN, INT_MAX};
    pii ret = {0, 1 << 30};
    if(l <= t[p].l && r >= t[p].r){
        return {t[p].maxx, t[p].minn};
    }
    int mid = t[p].l + t[p].r >> 1;
    if(l <= mid) {
        pii t = Query(p << 1, l, r);
        ret = {max(ret.first, t.first), min(ret.second, t.second)};
    }
    if(r > mid) {
        pii t = Query(p << 1|1, l, r);
        ret = {max(ret.first, t.first), min(ret.second, t.second)};
    }
    return ret;
}


void solve(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);

    int r1 = 1, r2 = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        //左端点
        pii t = Query(1, i, r1);
        while(r1 <= n && t.first - t.second < k){
            r1++;
            t = Query(1, i, r1);
        }

        //右端点
        t = Query(1, i, r2);
        while(r2 <= n && t.first - t.second <= k){
            r2++;
            t = Query(1, i, r2);
        }
        if(r1 <= n) ans += r2 - r1;
        else break;
    }
    printf("%lld",ans);
}


int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}