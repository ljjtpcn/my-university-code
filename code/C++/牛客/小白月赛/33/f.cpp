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
    int op; cin >> op;

    ll cur = 0, x = 0, y = 0;
    while(op --){
        char c; ll k;
        cin >> c >> k;
        if(c == 'r'){
            k %= 4;
            cur -= k;
            cur = (cur + 4) % 4;
        }else if(c == 'l'){
            k %= 4;
            cur += k;
            cur = cur % 4;
        }else if(c == 'w'){
            if(cur == 0) y += k;
            if(cur == 1) x += k;
            if(cur == 2) y -= k;
            if(cur == 3) x -= k;
        }else if(c == 's'){
            if(cur == 0) y -= k;
            if(cur == 1) x -= k;
            if(cur == 2) y += k;
            if(cur == 3) x += k;
        }else if(c == 'a'){
            if(cur == 0) x -= k;
            if(cur == 1) y += k;
            if(cur == 2) x += k;
            if(cur == 3) y -= k;
        }else if(c == 'd'){
            if(cur == 0) x += k;
            if(cur == 1) y += k;
            if(cur == 2) x -= k;
            if(cur == 3) y += k;
        }
    }
    cout << x << ' ' << y << endl;
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}