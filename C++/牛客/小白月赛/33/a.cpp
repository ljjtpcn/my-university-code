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
    string s = "";
    int line, word, c_cnt;
    line = word = c_cnt = 0;
    while(getline(cin, s) && s != "====="){
        line++;

        if(s.size() == 0) continue;

        c_cnt += s.size();

        auto v = s_split(s, " ");
        word += v.size();
        if(v[0] == "") word --;
        if(v[v.size() - 1] == "") word --;
    }

    cout << line << ' ' << word << ' ' << c_cnt << '\n';
}

int main(){
    int __ = 1;
    __ = readI();
    while(__--){
        solve();
    }
    return 0;
}