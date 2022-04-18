// Problem: H - King's Tour
// Contest: AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner
// Contest 232) URL: https://atcoder.jp/contests/abc232/tasks/abc232_h Memory
// Limit: 1024 MB Time Limit: 2000 ms

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
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
struct node {
  int x, y, cnt;
};
struct cmp {
  bool operator()(node a, node b) { return a.cnt > b.cnt; }
};

void solve() {}

int main() {
  int __ = 1;
  scanf("%d", &__);
  while (__--) {
    solve();
  }
  return 0;
}