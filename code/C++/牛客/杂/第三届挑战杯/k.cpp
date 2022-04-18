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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int idx = 0;
    while(s[idx++] != '0') break;
    cout << s[idx];
    for(int i = 0; i < idx; i ++ ) cout << '0';
    for(int i = idx; i < s.size(); i ++ ) cout << s[i];
    cout << "\n";
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}