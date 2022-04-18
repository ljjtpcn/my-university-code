#include <bits/stdc++.h>
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
using namespace std;

template<typename T> inline T read()
{
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch=='-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5e7 + 10;

void solve(){
    int n, m;
    cin >> n >> m;
    while(m --){
        int l, r;
        cin >> l >> r;
        if(l <= n / 2 + 1 && r >= n / 2 + 1){
            cout << n % (n / 2 + 1) << endl;
            continue;
        }
        if(l >= n / 2 + 1){
            cout << n - l << endl;
            continue;
        }

        int ans = 0;
        int t = ceil(((n % r) * r + 2 * r + (n % r)) / (3.0 + (n % r)));
        if(t >= l && t <= r) cout << n % t << endl;
        else cout << n % l << endl;
    }
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}