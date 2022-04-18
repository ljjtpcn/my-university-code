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
    int n, A, B;
    cin >> n >> A >> B;


    int ans = 0;
    auto f = [&](int a, int b){
        int cnt = 0;
        while(a >= A || b >= B){
            int ta = a / A;
            int tb = b / B;
            cnt += ta + tb;
            a = a % A + tb;
            b = b % B + ta;
        }
        return cnt;
    };

    for(int i = 0; i <= n; i ++){
        ans = max(ans, f(i, n - i));
    }
    cout << ans + n << endl;
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}