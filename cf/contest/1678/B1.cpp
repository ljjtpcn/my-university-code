// Problem: B1. Tokitsukaze and Good 01-String (easy version)
// Contest: Codeforces - Codeforces Round #789 (Div. 2)
// URL: https://codeforces.com/contest/1678/problem/B1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    string s;
    cin >> s;
    s = " " + s;
    n /= 2;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (s[i * 2 - 1] != s[i * 2]) ans++;
    cout << ans << endl;
}

// clang-format off
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout<<fixed<<setprecision(12);
    int __ = 1;
    cin >> __;
    while (__--) { solve(); }
    Please AC;
}