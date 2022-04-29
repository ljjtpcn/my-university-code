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
const int N = 2e5 + 10;

void solve() {
    ll p, k;
    cin >>p >> k;
    if(k == 0){
        cout << 0 <<endl;;
        return;
    }else if(k == 1){
        cout << max(0ll, p - 1) <<endl;
        return;
    }else if(k == 2){
        cout << min(2ll, p - 1) << endl;
        return;
    }
    ll temp = p - 1;
    string s = "";
    
    int cnt = 0;
    while(temp){
        if(temp & 1) s.pb('1'), cnt ++;
        else s.pb('0');
        temp >>= 1;
    }
    reverse(s.begin(), s.end());
    ll t = s.size() + (cnt - 1);
    // cout << t <<"!!!!!!";
    for(int i = s.size() - 1; i >= 1; i --){
        if(s[i] == '1' && t > k) s[i] = '0', t -= 1;
        if(t <= k){
            cout << stol(s, nullptr, 2) << endl;
            // cout << s << endl;
            return;
        }
    }
    // cout << stol(s, nullptr, 2) << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}