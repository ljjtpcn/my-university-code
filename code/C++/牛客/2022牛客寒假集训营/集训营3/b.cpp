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
#define mod 1000000007
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
const int N = 1e3 + 10;
int n, m;
int arr[N], dp[N][N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    //dp[i][j]表示前i个西瓜重量j的方案 dp[0][0] = 1;dp[i][0] = i;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        //f[i][j] = 第i个不选+选一般+全选
        for (int j = m; j >= 0; j--){
            dp[i][j] = dp[i - 1][j] % mod;
            if(j - arr[i] >= 0){
                dp[i][j] = (dp[i][j] + dp[i-1][j - arr[i]]) % mod;
            }
            if(j - arr[i] / 2 >= 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i] / 2]) % mod;
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << dp[n][i] << ' ';
}
int main(){
    ggg;
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}