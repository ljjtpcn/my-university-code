// Problem: F. Jee, You See?
// Contest: Codeforces - Codeforces Round #788 (Div. 2)
// URL: https://codeforces.com/contest/1670/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
#include <stdio.h>
#include <algorithm>
#define N 200008
using namespace std;

char s[N], K[27];
int n, k, T;

int juged(char x) {
    for (int i = 1; i <= k; i++) {
        if (x == K[i]) { return 1; }
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        getchar();
        for (int i = 1; i <= n; i++) scanf("%c", &s[i]);
        getchar();
        scanf("%d", &k);
        for (int i = 1; i <= k; i++) {
            getchar();
            scanf("%c", &K[i]);
        }

        int t = 1, dis = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (juged(s[i])) {
                dis = i - t;
                t = i;
                ans = max(dis, ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}