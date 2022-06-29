// Problem: 填空题
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11228/B
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

void solve() {
    int n;
    cin >> n;
    int arr[N] = {-1};
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        if (arr[1] == 0) arr[1] = 1;
        if (arr[i] == 0) { arr[i] = arr[i - 1] + 1; }
    }

    ll sum = arr[1];
    for (int i = 2; i <= n; i++) {
        sum += arr[i];
        if (arr[i] <= arr[i - 1]) {
            cout << -1;
            return;
        }
    }
    cout << sum;
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

