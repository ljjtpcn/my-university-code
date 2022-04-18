#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N = 1e6 + 10;
typedef pair<int, int> PII;

int n;
int h[N], e[2 * N], ne[2 * N], idx;
int maxx, son[N];


/***********************************dfs****************************************/
// void init(){
//     memset(h, -1, sizeof(h));
// }

// void add(int a, int b){
//     e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// }

// void dfs(int now, int pre){
//     son[now] = 1;
//     for (int i = h[now]; i != -1; i = ne[i]){
//         int next = e[i];
//         if(next == pre)
//             continue;
//         dfs(next, now);
//         son[now] += son[next];
//     }
// }

// int main()
// {
//     cin >> n;
//     init();
//     for (int i = 0; i < n-1; i++){
//         int a, b;
//         cin >> a >> b;
//         add(a, b), add(b, a);
//     }

//     dfs(1, 0);
//     for(int i = h[1]; i != -1; i = ne[i]){
//         maxx = max(maxx, son[e[i]]); 
//     }
//     cout << maxx;
//     return 0;
// }

/***********************************并查集****************************************/

int fa[N];
int cnt[N];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        cnt[b] += cnt[a];
        fa[a] = b;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
        cnt[i] = 1;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != 1 && b != 1)
            merge(a, b);
    }

    for (int i = 1; i <= n; i++)
        maxx = max(cnt[i], maxx);
        
    printf("%d", maxx);
}