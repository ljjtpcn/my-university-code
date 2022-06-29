#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int N = 110;

int g[N][N], d[N]; //领接矩阵存图， d[i]表示到集合的最小距离
int st[N];// 判断点是否在集合中
int c, n, m; //c钱n点m边

int Prim()
{
    d[1] = 0;
    int res = 0;
    for (int i = 0; i < n; i ++ ) //循环n次
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
        {
            if(!st[j] && (t == -1 || d[j] < d[t])) // t 找不在集合且距离集合最近的点
                t = j;
        }
        if(i && d[t] == INF) return INF; // 不是第一个点（i==0）且d[t] 最小值为INF  说明图不连通 返回

        if(i) res += d[t];
        st[t] = 1;//加入最小生成树集合
        for (int j = 1; j <= n; j ++ ) d[j] = min(d[j], g[t][j]);//更新不在集合点到集合的最小距离
    }
    return res;
}
int main()
{
    //n点m边
    cin >> c >> m >> n;

    //初始化
    memset(d, 0x3f, sizeof d);
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++ ) g[i][i] = 0;

    while (m -- )
    {
        int a, b, w; cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w); //重边最小
    }

    int t = Prim();
    if(t > c) cout << "No";
    else cout << "Yes";

    return 0;
}