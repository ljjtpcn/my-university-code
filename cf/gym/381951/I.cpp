#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define ls u << 1
#define rs u << 1 | 1
#define lowbit(x) x & -x
#define pb push_back
#define FOR(i, a, n) for (int i = a; i <= n; i++)

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2002;
mt19937_64 mrand(random_device{}());
char s[N][N];
bool v[N][N][4];

template <typename T>
inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
struct node {
    int x, y, w, dir;
};

int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};  // 下，上，右，左
int n;
bool check(int x, int y) { return x <= n && y <= n && x >= 1 && y >= 1; }
void solve() {
    n = readI();
    for (int i = 1; i <= n; i++) { scanf("%s", s[i] + 1); }
    deque<node> p;
    if (s[1][1] == '*') {
        p.push_back({1, 1, 0, 0});
        p.push_back({1, 1, 1, 2});
        // v[1][1][0] = v[1][1][1] = v[1][1][2] = v[1][1][3] = true;
    } else if (s[1][1] == '\\') {
        p.push_back({1, 1, 0, 2});
        p.push_back({1, 1, 1, 0});
    } else {
        p.push_back({1, 1, 1, 0});
        p.push_back({1, 1, 1, 2});
    }
    v[1][1][1] = v[1][1][3] = true;
    while (p.size()) {
        auto [x, y, w, dir] = p.front();
        p.pop_front();
        if (v[x][y][dir]) continue;
        v[x][y][dir] = true;
        if (x == n && y == n && dir == 0) {
            printf("%d\n", w);
            return;
        }
        // 下，上，右，左   0 1 2 3
        int tx = x + d[dir][0], ty = y + d[dir][1];
        if (!check(tx, ty)) continue;
        if (s[tx][ty] == '*') {
            p.push_front({tx, ty, w, dir});
            if (dir == 0) {
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
            } else if (dir == 1) {
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
            } else if (dir == 2) {
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
            } else {
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
            }
        } else if (s[tx][ty] == '\\') {
            p.push_back({tx, ty, w + 1, dir});
            if (dir == 0) {
                if (!v[tx][ty][2]) p.push_front({tx, ty, w, 2});
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
            } else if (dir == 1) {
                if (!v[tx][ty][3]) p.push_front({tx, ty, w, 3});
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
            } else if (dir == 2) {
                if (!v[tx][ty][0]) p.push_front({tx, ty, w, 0});
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
            } else {
                if (!v[tx][ty][1]) p.push_front({tx, ty, w, 1});
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
            }
        } else if (s[tx][ty] == '/') {
            p.push_back({tx, ty, w + 1, dir});
            if (dir == 0) {
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
                if (!v[tx][ty][3]) p.push_front({tx, ty, w, 3});
            } else if (dir == 1) {
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
                if (!v[tx][ty][2]) p.push_front({tx, ty, w, 2});
            } else if (dir == 2) {
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
                if (!v[tx][ty][1]) p.push_front({tx, ty, w, 1});
            } else {
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
                if (!v[tx][ty][0]) p.push_front({tx, ty, w, 0});
            }
        } else {
            p.push_back({tx, ty, w + 1, dir});
            if (dir == 0) {
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
            } else if (dir == 1) {
                if (!v[tx][ty][3]) p.push_back({tx, ty, w + 1, 3});
                if (!v[tx][ty][2]) p.push_back({tx, ty, w + 1, 2});
            } else if (dir == 2) {
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
            } else {
                if (!v[tx][ty][1]) p.push_back({tx, ty, w + 1, 1});
                if (!v[tx][ty][0]) p.push_back({tx, ty, w + 1, 0});
            }
        }
    }
}
// *()
int main() {
    int t = 1;
    // t = read<int>();
    while (t--) solve();
    return 0;
}

/*

4
\**\
###*
###*
###/

*###
#/*\
\///
/#\/

*/
