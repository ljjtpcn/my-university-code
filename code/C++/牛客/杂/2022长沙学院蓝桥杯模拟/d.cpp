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



void solve(){
    int ans = 0;
    string s; cin >> s;
    if((s[0] - s[1] == 1 && s[1] - s[2] == 1 && s[2] - s[3] == 1) || (s[0] - s[1] == -1 && s[1] - s[2] == -1 && s[2] - s[3] == -1)) ans += 5;     
    if(s[0] == s[1] && s[1] == s[2]) ans += 3; 
    if(s[3] == s[2] && s[2] == s[1]) ans += 3;
    if(s[0] == s[1] && s[2] == s[3]) ans += 1; 
    if(s[0] == s[2] && s[1] == s[3]) ans += 1;
    for(auto c : s) if(c == '6' || c == '8' || c == '9') ans++;
    cout << ans << endl;
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}