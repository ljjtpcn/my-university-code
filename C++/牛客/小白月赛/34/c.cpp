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
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10;


int dp[N][30]; //dp[i][j]表示到第i个时修改第i个为字符'a'+j的最小贡献

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    memset(dp, 0x3f, sizeof dp);
    // i从0开始
    for(int j = 0; j < 26; j ++) dp[0][j] = abs('A' + j - s[0]);
    
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < 26; j ++){
            for(int k = 0; k <= j; k ++){
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs('A' + j - s[i]));
            }
        }
    }
    
    cout << *min_element(dp[n - 1], dp[n - 1] + 26);
}

int main(){
    int __ = 1;
    // __ = readi();
    while(__--){
        solve();
    }
    Please AC;
}