// Problem: D - Range Count Query
// Contest: AtCoder - UNIQUE VISION Programming Contest 2022（AtCoder Beginner
// Contest 248） URL: https://atcoder.jp/contests/abc248/tasks/abc248_d Memory
// Limit: 1024 MB Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
using namespace std;
// clang-format off
inline void read(int &num) {
    int s = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
    num = s;
}
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

vector<int> arr[N];
void solve() {
    int n, x, q;
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x);
        ar[i] = x;
        arr[x].pb(i);
    }
    read(q);
    while (q--) {
        int a, b, x;
        read(a), read(b), read(x);
        if (arr[x].empty()) {
        puts("0");
        continue;
        }
        int l = 0, r = arr[x].size() - 1;
        while (l < r) {
        int mid = l + r + 1 >> 1;
        if (arr[x][mid] <= b)
        l = mid;
        else
        r = mid - 1;
        }
        if (arr[x][l] > b || arr[x][l] < a) {
        cout << 0 << endl;
        continue;
        }
        int R = l;
        l = 0, r = arr[x].size() - 1;
        while (l < r) {
        int mid = l + r >> 1;
        if (arr[x][mid] >= a)
        r = mid;
        else
        l = mid + 1;
        }
        int L = l;
        printf("%d\n", R - L + 1);
        // cout << count(ar.begin() + a, ar.begin() + b + 1, x) << endl;
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}