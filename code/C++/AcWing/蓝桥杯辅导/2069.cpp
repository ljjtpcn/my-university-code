#include <bits/stdc++.h>
#define Please return
#define AC 0
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
void split(const string& s, vector<string>& tokens, const string& delimiters)
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


int f[50][50];
void solve(){
    int n, m;
    cin >> n >> m;
    if(n % 2 == 0 && m % 2 == 0) cout << 0, exit(0);
    
    f[1][1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(!(i & 1 || j & 1)) continue;
            f[i][j] += f[i - 1][j] + f[i][j -1];
        }
    }
    cout << f[n][m];
}

int main(){
    int __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    Please AC;
}