#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec sec
using namespace std;
// clang-format off
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

int arr[N];
void solve() {
    int n, k;
    cin >> n >> k;

    int cnt[40] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        int x = arr[i];
        int idx = 0;
        while (x) {
            if (x & 1) cnt[idx]++;
            idx++;
            x >>= 1;
        }
    }
    string ans = "";
    for (int i = 30; i >= 0; i--) {
        if (k >= (n - cnt[i])) {
            ans += '1';
            k -= n - cnt[i];
        } else {
            ans += '0';
        }
    }
    cout << stoi(ans, nullptr, 2) << endl;
}

int main() {
    int __ = 1;
    scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}