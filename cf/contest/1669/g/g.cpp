#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec sec
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
const int N = 50 + 10;

string s[N];
void solve() {
    int n, m;
    read(n), read(m);
    for(int i = 0; i < n; i ++) cin >> s[i];

    for(int j = 0; j < m; j ++){
        int cnt = 0;
        for(int i = 0; i < n; i ++){
            if(s[i][j] == 'o' || i == n - 1){
                for(int k = s[i][j] == '.' ? i : i - 1; cnt > 0; cnt --, k --){
                    s[k][j] = '*';
                }
            }else if(s[i][j] == '*'){
                cnt ++;
                s[i][j] = '.';
            }
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cout << s[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}