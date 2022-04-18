#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
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
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


void solve(){
    int n, m;
    n = readI(), m = readI();

    map<string, int> mp;
    for(int i = 0; i < n; i ++){
        string s; int cnt;
        cin >> s >> cnt;
        mp[s] = cnt - m;
    }

    for(int i = 0; i < m; i ++){
        int cnt; cin >> cnt;
        while(cnt --){
            string s; cin >> s;
            mp[s] ++;
        }
    }

    int ans = 0;
    for(auto[s, cnt] : mp){
        if(cnt > 0) ans ++;
    }
    if(ans > 0) cout << ans << endl;
    else cout << "Need to be lucky" << endl;
}

int main(){
    int __ = 1;
    __ = readI();
    while(__--){
        solve();
    }
    return 0;
}