#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define ep emplace
#define ggg ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int N = 1e5 + 10;
int n, m;

bool check_Self(string s){
    for (int i = 0, j = s[s.size() - 1]; i <= j; i ++, j --){
        if(s[i] != s[j]) return false;
    }
    return true;
}

void solve(){
    map<string, int> mp;mp.clear();
    cin >> n;
    int flag = 0;
    for(int i = 0; i < n; i++){
        string t; cin >> t;
        mp[t] = 1;
        if(check_Self(t)) flag = 1;
        reverse(t.begin(), t.end());
        if(mp.count(t) || mp.count(t.substr(0, t.size() - 1))) flag = 1;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp.count(t+c)) flag = 1;
        }
    }
    if(flag)
        cout << "yes\n";
    else
        cout << "no\n";
}
int main(){
    // ggg;
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}