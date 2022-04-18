#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define pb push_back
using namespace std;

template <typename T>
inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void split(const string& s, vector<string>& tokens, const string& delimiters) {
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(
            s.substr(lastPos, pos - lastPos));  // use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}
// clang-format off
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;
struct node { int x, y, cnt; };
struct cmp {bool operator()(node a, node b) { return a.cnt > b.cnt; }};

ll arr[N];

void solve() {
    ll n, w;
    cin >> n >> w;
    for(int i = 1; i <= n; i ++ ) cin >> arr[i];
    
    
    auto check = [&](ll row){
        ll ans = 0, len, col = n / row + (n % row ? 1 : 0);
            
        for(int i = 1; i <= col; i ++ ){
            ll len = 0;
            for(int j = (i - 1) * row + 1; j <= i * row && j <= n; j ++) 
                len = max(len, arr[j]);
            ans += len + 1;
        }
        ans -= 1;
        if(ans <= w) return true;
        
        return false;
    };
    
    ll l = 1, r = n;
    while(l < r){
        ll mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
}
// clang-format on

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    return 0;
}