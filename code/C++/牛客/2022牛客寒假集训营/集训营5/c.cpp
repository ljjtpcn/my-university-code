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
const int N = 30010;
struct node{int a, b, c, d, maxx, unmaxx, now;}nd[N];
int n, k, s;
int arr[N], st[N], ans, cnt;
void solve(){
    cin3(n, k, s);
    for(int i = 0; i < n; i ++){
        cin >> arr[i]; arr[i] -= s;
    }
    for(int i = 0; i < n; i ++){
        int a, b, c, d;
        cin4(a, b, c, d);
        //maxx使用礼遇, unmaxx不使用礼遇
        int maxx = max({a, b, c, d}), unmaxx = max(a, b);
        nd[i] = {a, b, c, d, maxx, unmaxx, -1};
    }
    //remain剩余可用礼遇, deep到哪了
    function<void(int, int)> dfs = [&](int remain, int deep) {
        if(deep == n){ //到最后一个了
            node copy[n];
            for(int i = 0; i < n; i ++) copy[i] = nd[i];
            for(int i = 0; i < n; i ++){
                //st决定是否使用礼遇, 最终存在now里面,对now排序
                if(st[i])
                    copy[i].now = max(copy[i].maxx, copy[i].unmaxx);
                else
                    copy[i].now = copy[i].unmaxx;
            }
            sort(copy, copy + n, [](node a, node b){
                return a.now > b.now;
            });

            s = cnt = 0;
            for(int i = 0; i < n; i ++){
               s += copy[i].now;
               if(s >= arr[i]) {
                   cnt++;
               }
            }
            ans = max(ans, cnt);
            return;
        }
        //还有礼遇就可以选和不选
        if(remain > 0){
            st[deep] = 1;
            dfs(remain - 1, deep + 1);
            st[deep] = 0;
            dfs(remain, deep + 1);
        }else{
            //否则只能不选
            st[deep] = 0;
            dfs(remain, deep + 1);
        }
        
    };
    dfs(k, 0);
    cout << ans;
}
int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}