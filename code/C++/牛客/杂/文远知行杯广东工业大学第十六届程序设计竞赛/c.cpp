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
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


void solve(){

}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}