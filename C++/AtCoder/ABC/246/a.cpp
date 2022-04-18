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
typedef unsigned long long ull;
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


void solve(){
    array<int ,3> x, y;
    for(int i = 0; i < 3; i ++){
        int a, b;
        cin >> a >> b;
        x[i] = a, y[i] = b;
    }
    if(x[0] == x[1]){
        cout << x[2] << ' ';
    }else if(x[0] == x[2]){
        cout << x[1] << ' ';
    }else if(x[1] == x[2]){
        cout << x[0] << ' ';
    }

    if(y[0] == y[1]){
        cout << y[2] << ' ';
    }else if(y[0] == y[2]){
        cout << y[1] << ' ';
    }else if(y[1] == y[2]){
        cout << y[0] << ' ';
    }


}

int main(){
    int __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    Please AC;
}