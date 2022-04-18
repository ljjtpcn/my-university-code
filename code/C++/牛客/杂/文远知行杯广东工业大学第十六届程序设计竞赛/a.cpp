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
        int dl = n / l;
        int dr = n / r;
        if(dl == dr) cout << n % l << endl;
        else{
            cout << n % (n / (dr + 1) + 1) << endl;
        }
    }
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}