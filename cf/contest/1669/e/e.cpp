#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec sec
using namespace std;
// clang-format off
inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *= a;b >>= 1;}return res;}
ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on

const int N = 2e5 + 10;

vector<string> arr;
map<string, int> mp;
map<char, int> st1, st2;
void solve() {
    int n;
    cin >> n;
    arr.clear(), mp.clear(), st1.clear(), st2.clear();
    for(int i = 0; i < n;  i++){
        string s;
        cin >> s;
        arr.pb(s);
        mp[s] ++;
        st1[s[0]] ++;
        st2[s[1]] ++;
    }

    ll ans = 0;
    for(auto s : arr){
        char a = s[0], b = s[1];
        ans += st1[a] + st2[b] - 2 * mp[s];
        st1[a] --;
        st2[b] --;
        mp[s] --;
    }
    cout << ans << endl;
}


int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}