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
    int f[MAXN][21]; // 第二维的大小根据数据范围决定，不小于log(MAXN)
    for (int i = 1; i <= n; ++i)
        f[i][0] = read(); // 读入数据
    for (int i = 1; i <= 20; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}