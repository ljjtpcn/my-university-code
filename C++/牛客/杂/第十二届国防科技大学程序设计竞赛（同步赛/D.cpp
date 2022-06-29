// Problem: D. Swap Permutation
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/35627/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define yes cout << "Yes\n"
#define no cout << "No\n"
using namespace std;
using i64 = long long;
constexpr int P = 998244353;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// clang-format on
const int N = 2e5 + 10;

int arr[N];

int cnt[N], p[N];

int find(int x) {
    if (p[x] != x)
        return p[x] = find(p[x]);
    else
        return x;
}

void merge(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return;
    p[fa] = fb;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        merge(i, arr[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) cnt++;
    }
    int need = min(cnt - 1, k);
    cnt -= need;
    k -= need;

    if (k & 1)
        cout << cnt + 1;
    else
        cout << cnt;
}

// clang-format off
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int __ = 1;
    //cin >> __;
    while (__--) { solve(); }
    Please AC;
}

