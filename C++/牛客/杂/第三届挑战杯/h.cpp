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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i]; 
    sort(v.begin(), v.end());

    deque<int> dq;
    for(auto x : v) dq.push_back(x);
    
    int flag = 1; ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(dq.size()){
        int t1, t2;
        if(flag){
            t1 = dq.front(); dq.pop_front();
            t2 = dq.front(); dq.pop_front();
        }else{
            t1 = dq.back(); dq.pop_back();
            t2 = dq.back(); dq.pop_back();
        }
        ans += max(t1, t2);
        pq.push(t1), pq.push(t2);
        if(dq.size() == 0) break;
        int back = pq.top();
        pq.pop();
        ans += back;
        dq.push_front(back);
        flag = !flag;
    }
    cout << ans << endl;
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}