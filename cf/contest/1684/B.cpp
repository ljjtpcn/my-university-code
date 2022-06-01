// Problem: B. Z mod X = C
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/B
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

/*
for all a < b < c
have:
    x=a+b+c
    y=b+c
    z=c
that
    x mod y == (a+b+c) % (b+c) = a
    y mod z = (b+c) % c = b
    z mod x == c % (a+b+c) = c
*/
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c << ' ' << b + c << ' ' << c << endl;
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