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
const int mod = 998244353;
const int N = 1e5 + 10;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
struct node{
	int x, y, cnt;
};
struct cmp{
	bool operator()(node a, node b){
		return a.cnt > b.cnt;
	}
};
int n, m;
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
map<char, int> mp{{'C', 1}, {'D', 2}, {'E', 3}, {'F', 4}, {'G', 5}, {'A', 6}, {'B', 7}};
void solve(){
    string s;
    cin >> s;
    string ss;
    for(int i = s.size() - 1;i >= 0; i --){
        if(s[i] == '<' || s[i] == '>') continue;
        ss.push_back(s[i]);
    }
    reverse(ss.begin(), ss.end());
    s = ss;
    int dian = 0, xin = 0;
    for (int i = 0; i < s.size(); i ++){
        if(s[i] != '<' && s[i] != '>'){
            cout << mp[s[i]];
            if(dian != 0){
                string out(dian, '.');
                cout << out;
            }
            if(xin != 0){
                string out(xin, '.');
                cout << out;
            }
        }else{
            if(s[i] == '<')
                dian++;
            if(s[i] == '>')
                xin++;
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