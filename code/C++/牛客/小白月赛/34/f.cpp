#include <bits/stdc++.h>
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
#define fir first
#define sec second
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
const int N = 1e7 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


ll arr[N], sum[N];

void solve(){
    ll n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) arr[i] = readi(), sum[i] = sum[i - 1] + arr[i];
    
    int L = 1, R = 1e9 + 10;
    for(int i = 1; i <= n; i ++){
        int l = i, r = n;
        while(l < r){
            ll mid = l + r >> 1;
            if(sum[mid] - sum[i - 1] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if(sum[l] - sum[i - 1] >= x && l - i + 1 < R - L + 1)
            L = i, R = l;
        
    }
    cout << L << ' ' << R;
}

int main(){
    int __ = 1;
    // cin >> __;
    while(__--){
        solve();
    }
    return 0;
}