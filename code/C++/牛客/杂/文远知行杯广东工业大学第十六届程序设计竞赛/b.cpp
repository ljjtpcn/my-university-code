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
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};


void solve(){
    string s;
    cin >> s;
    int base = 30;
    int flag = 0;
    for(int i = 0; i < s.size();){
        int start = i * base;
        int idx = i, cnt = 0;
        while(s[i++] == '1') cnt ++;
        int end = start + base * cnt;

        int hh1 = start / 60; int mm1 = start % 60;
        int hh2 = end / 60; int mm2 = end % 60;

        if(cnt > 0){
            flag = 1;
            string a = to_string(hh1), b = to_string(mm1), c = to_string(hh2), d = to_string(mm2);
            cout << (a.size() == 2 ? a : '0' + a) << ":" << (b.size() == 2 ? b : '0' + b) << " - " << (c.size() == 2 ? c : '0' + c) << ":" << (d.size() == 2 ? d : '0' + d) << endl;
        }
    }
    if(!flag) cout << "00:00 - 00:00" << endl;
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}