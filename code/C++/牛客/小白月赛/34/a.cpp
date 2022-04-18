#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
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
std::vector<std::string> s_split(const std::string& in, const std::string& delim) {
    std::regex re{ delim };
    // 调用 std::vector::vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
    // 构造函数,完成字符串分割
    return std::vector<std::string> {
        std::sregex_token_iterator(in.begin(), in.end(), re, -1),
        std::sregex_token_iterator()
    };
}

typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<char> dp;
    for(int i = 0; i < s.size(); i ++){
        if(dp.size() == 0 || s[i] >= dp.back())
            dp.pb(s[i]);
        else
            dp[upper_bound(dp.begin(), dp.end(), s[i]) - dp.begin()] = s[i];
    }
    cout << s.size() - dp.size();
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}