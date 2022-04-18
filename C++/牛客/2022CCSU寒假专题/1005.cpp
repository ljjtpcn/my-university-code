#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;

int n;
int h[N], ne[N * 2], e[N * 2], idx;
int maxx, t;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int now, int pre,int cnt)
{
    if (cnt > maxx)
    {
        maxx = cnt;
        t = now;
    }
    for (int i = h[now]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j != pre) dfs(j, now,cnt + 1);

    }
}
int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1, 0, 1);
    dfs(t, 0, 1);
    printf("%d", maxx);
    return 0;
}