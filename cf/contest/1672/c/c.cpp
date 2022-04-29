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

int arr[N];
void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];        
    }

    int l = 0, r = n - 1;
    for(int i = 0; i < n - 1; i ++){
        if(arr[i] == arr[i + 1]){
            l = i;  
            break;
        }
    }
    for(int i = n - 1; i >= 1; i --){
        if(arr[i] == arr[i - 1]){
            r = i - 1;  
            break;
        }
    }
    if((l == 0 && r == n - 1) || (l == r)) cout << 0  << endl;
    else cout << (l + 1 == r ? 1 : r - l - 1)<<endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}