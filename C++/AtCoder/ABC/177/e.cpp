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
const int N = 1e6 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};

unordered_map<int, int> mp;
vector<int> arr;
void solve(){
    int n; cin >> n;
    int flag = 0;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        arr.push_back(x);
        if(!mp[x]) mp[x] = 1;
        else if(x != 1) flag = 1;
    }
    if(flag){
        int t = __gcd(arr[0], arr[1]);
        for(int i = 2; i < arr.size(); i ++){
            t = __gcd(t, arr[i]);
        }
        if(t == 1)
            cout << "setwise coprime";
        else
            cout << "not coprime";
        return;
    }

    int f = 1;
    for(int i = 2; i <= (int)1e6; i ++){  
        int cnt = 0;
        for(int j = i; j <= (int)1e6; j += i){
            if(mp[j]) cnt ++;
        }
        if(cnt >= 2){f = 0; break;} 
    }
    if(f){
        cout << "pairwise coprime";
        return;
    } 


    int t = __gcd(arr[0], arr[1]);
    for(int i = 2; i < arr.size(); i ++){
        t = __gcd(t, arr[i]);
    }
    if(t == 1)
        cout << "setwise coprime";
    else
        cout << "not coprime";
    return;
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}