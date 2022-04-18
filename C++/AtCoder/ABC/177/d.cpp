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
const int N = 2e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


int p[N], cnt[N];

int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int a, int b){
    
    if(find(a) != find(b)){
        cnt[find(b)] += cnt[find(a)];
        p[find(a)] = find(b);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) p[i] = i, cnt[i] = 1;
    for(int i = 1; i <= m; i ++){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++){
        ans = max(cnt[i], ans);
    }
    cout << ans;
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}