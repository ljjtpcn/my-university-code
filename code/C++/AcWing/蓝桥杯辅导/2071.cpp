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



int p[N], d[N];
void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) p[i] = i;
    function<int(int)> find = [&](int x){
        if(x == p[x] || p[x] == p[p[x]]) return x; // 如果p[x](x)是根节点或者x的父亲就是根节点直接返回
        int root = find(p[x]); // 找到x的根节点
        d[x] += d[p[x]]; // 加权
        p[x] = root; // 路径压缩让x直接指向root
        return root; // 一路返回root
    };
    
    while(m --){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            a = find(a), b = find(b);
            if(a != b){
                d[a] -= d[b];
                p[a] = b;    
            }
        }else{
            d[find(a)] += b;
        }
    }

    for(int i = 1; i <= n; i ++){
        if(i == find(i)) cout << d[i] << ' ';
        else cout << d[i] + d[find(i)] << ' ';
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