// Problem: 小猫排队
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11224/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define Please return
#define AC 0
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
#define fir first
#define sec second
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
struct node {
    int x, y, cnt;
};
struct cmp {
    bool operator()(node a, node b) { return a.cnt > b.cnt; }
};
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10;

deque<int> dq;
void solve() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    cin >> k;
    // dq.push_back(k);
    int ans = 0;
    while (dq.size()) {
        int sum = 0;
        while (dq.size() && dq.back() <= k)  //统计前面没自己可爱的个数
        {
            dq.pop_back();
            sum++;
        }
        if (!dq.size())  //如果直接空了说明不能使用魔法加上前面所有的
        {
            // printf("sum = %d",sum);
            ans += sum;
            break;
        }
        if (dq.back() > k) dq.pop_back();
        if (dq.size()) {
            dq.pop_front();
            ans++;
        }
    }
    cout << ans + 1;
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}
