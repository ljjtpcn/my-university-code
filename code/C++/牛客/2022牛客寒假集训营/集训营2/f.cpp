#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define ep emplace
#define ggg ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
// #define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
    char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
    int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
    if(nega==-1) return -ans;
    return ans;
}
inline char rdchar()
{
    char ch=getchar();
    while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
    return ch;
}
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
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

int n, m, q;
string s;
ll arr[N], f[N], res[N];
int st[N];
void solve(){
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int idx = 1, base = 1;
    f[base++] = idx++;
    for (int i = 0; i < s.size(); i++){ 
        if(s[i] == '+'){
            f[base++] = idx++;
        }else{
            f[base] = f[base - 1];
            st[f[base - 1]] = 1;
            base++;
        }
    }

    int loc = f[1];
    for(int i = 1; i <= n;){
        res[loc] = 1;
        do{
            res[loc] = mul(res[loc] % mod, arr[i] % mod);
            i++;
        } while (f[i] == loc);
        loc++;
    }

    ll sum = 0;
    for(int i = 1; i < idx; i ++){
        sum = add(sum % mod, res[i] % mod);
        sum %= mod;
    }
   
    while(q --){
        int x, y;
        cin >> x >> y;
        if(!st[f[x]]){
            sum -= arr[x];
            sum += y;
            sum = (sum + mod) % mod;
            arr[x] = y;
            cout << sum << endl;
        }else{
            sum -= res[f[x]];
             res[f[x]] = res[f[x]] * inv(arr[x], mod - 2) % mod;
             res[f[x]] = res[f[x]] * y % mod;
             sum += res[f[x]];
             sum = (sum + mod) % mod;
             arr[x] = y;
             cout << sum << endl;
        }
    }
}
int main(){
    ggg;
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}