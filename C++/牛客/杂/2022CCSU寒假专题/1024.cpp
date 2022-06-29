#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
// #define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
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
#define N 1100
int n, m, t;
int beginLevel, maxlevel;
int arr[N],dp[N][N], maxx = -1;

void dfs(int u, int sum){
    if(u == n && sum >= 0 && sum <= maxlevel){
        maxx = max(maxx, sum);
        return;
    }

    if(sum + arr[u] <= maxlevel){
        dfs(u + 1, sum + arr[u]);
    }
    if(sum - arr[u] >= 0){
        dfs(u + 1, sum - arr[u]);
    }
}
//dp[i][j] 前 i 歌 当前音量为j有无可能, 有可能为1,默认没可能为0;
int main(){
    cin >> n >> beginLevel >> maxlevel;
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0][beginLevel] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = maxlevel; j >= 0; j--){
            if(arr[i-1] + j <= maxlevel && dp[i-1][j]){
                dp[i][j + arr[i - 1]] = 1;
            }
            if(j - arr[i-1] >= 0 && dp[i-1][j]){
                dp[i][j - arr[i - 1]] = 1;
            }
        }
    }

    for (int i = maxlevel; i >= 0; i--){
        if(dp[n][i]){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}