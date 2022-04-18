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

map<string, int> mp;
void solve(){
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s] ++;
    }

    ll ans = 0;
    for(ull i =                                                                                                                                                                                                                                                                                                                                                                        ; i <= 1e19; i += k){
        string s = to_string(i);
        for(int idx = 1; idx < s.size(); idx ++){
            string a = s.substr(0, idx), b = s.substr(idx);
            if(mp.count(a) && mp.count(b)){
                if(a == b){
                    ans += mp[a] * (mp[a] - 1);    
                }else{
                    ans += mp[a] * mp[b];
                }
            }
        }
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