#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
// clang-format on
const int mod = 1e9 + 7;
const int N = 3e5 + 10;

vector<pii> g;
map<pii, int> mp; 
int vis[N];
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size() - 1; i ++){
        if(vis[i]) continue;
        if((s[i] == 'L' && s[i + 1] == 'R') || (s[i] == 'R' && s[i + 1] == 'L')
        || (s[i] == 'D' && s[i + 1] == 'U') || (s[i] == 'U' && s[i + 1] == 'D'))
        {
            vis[i] = vis[i + 1] = 1;
        }
    }
    int x = 0, y = 0;
    mp[{0, 0}] = 1;
    set<pii> res;
    res.clear();
    int i = 0;
    for(auto c :s){
        if(vis[i]) continue;
        if(c == 'L'){
            x --; 
        }else if(c == 'R'){
            x ++;
        }else if(c == 'D'){
            y --;
        }else if(c == 'U'){
            y ++;
        }
        if(mp[{x,  y}]) res.insert({x, y});
        else mp[{x, y}] = 1;
        i ++;
    }
    cout << res.size() + 1;
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}