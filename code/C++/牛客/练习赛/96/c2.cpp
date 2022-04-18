
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

int n, k;
int st_min[N][20], st_max[N][20], LOG[N];

void init(){
    //预处理st表
    for (int j = 1; (1 << j) <= n; j ++){
        for (int i = 1; i + (1 << j) - 1 <= n; i ++){
            st_min[i][j] = min(st_min[i][j-1], st_min[i + (1 << j-1)][j-1]);
            st_max[i][j] = max(st_max[i][j-1], st_max[i + (1 << j-1)][j-1]);
        }
    }
    // 预处理k数组
    for (int i = 2; i <= N; i ++){
        LOG[i] = LOG[i / 2] + 1;
    }
}

int check(int l, int r){
    int k = LOG[r-l+1];
    int maxx = max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
    int minn = min(st_min[l][k], st_min[r - (1 << k) + 1][k]);

    return maxx - minn;
}


void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> st_min[i][0];
        st_max[i][0] = st_min[i][0];
    }

    init();

    ll ans = 0;
    for (int i = 1; i <= n; i++){
        int l = i, r = n;
        
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(i, mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        int L = l;

        if(check(i, L) != k) continue;

        l = i, r = n;
        while(l < r){                      
            int mid = l + r + 1 >> 1;
            if(check(i, mid) <= k)
                l = mid;
            else
                r = mid - 1;
        }
        int R = r;

        ans += R - L + 1;
    }
    cout << ans << endl;
}


int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}