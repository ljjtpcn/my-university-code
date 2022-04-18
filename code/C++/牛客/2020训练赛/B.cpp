// Problem: 方碑旋转
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/32577/B
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
const int N = 100 + 10;

string s[N];
void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    m = m > 0 ? m % 4 : 4 - (abs(m) % 4);
    if (m % 4 == 0) {
        for (int i = 0; i < n; i++) cout << s[i] << endl;
        return;
    }

    if (m == 1) {
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) { cout << s[i][j]; }
            cout << endl;
        }
    } else if (m == 2) {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) { cout << s[i][j]; }
            cout << endl;
        }
    } else if (m == 3) {
        for (int j = 0; j < n; j++) {
            for (int i = n - 1; i >= 0; i--) { cout << s[i][j]; }
            cout << endl;
        }
    }
}

int main() {
    int __ = 1;
    //__ = readi();
    while (__--) { solve(); }
    Please AC;
}