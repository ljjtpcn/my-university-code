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
const int N = 2e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};

priority_queue<int> q;
vector<ll> arr;
void solve(){
    int n, k, x;
    cin >> n >> k >> x;

    for(int i = 0; i < n; i ++){
        int t; cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto xx : arr){
        if(k == 0) {q.push(xx); continue;}
        int cnt = xx / x;
        if(k >= cnt)
            xx = max(0ll, xx - cnt * x), k -= cnt;
        else
            xx = max(0ll, xx - k * x), k = 0;
        if(xx != 0) q.push(xx);
    }
    while(k > 0 && q.size()){
        q.pop();
        k --;
    }
    ll sum = 0;
    while(q.size()){
        sum += q.top();
        q.pop();
    }
    cout << sum;
}

int main(){
    int __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    Please AC;
}