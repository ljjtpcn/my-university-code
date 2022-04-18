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
    ull n, ans = 1e19;
    cin >> n;

    for(int i = 0; i <= 1e6; i ++){
        ull a = i;
        ull l = 0, r = 1e6 + 10;
        while(l < r){
            int mid = (l + r) / 2;
            if(a * a * a + a * a * mid + a * mid * mid + mid * mid * mid >= n)
                r = mid;
            else
                l = mid + 1;
        }
        ull x = a * a * a + a * a * l + a * l * l + l * l * l;
        if(x >= n) ans = min(ans, x);
    }

    cout << ans;
}

int main(){
    int __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    Please AC;
}