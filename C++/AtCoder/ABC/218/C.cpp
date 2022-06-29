#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 300;
int n;
char a[N][N], b[N][N], c[N][N], ans[N][N], res[N][N];
bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] != res[i][j])
                return 0;
        }
    return 1;
}
void init() //初始化res数组
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            res[i][j] = '.';
        }
}
void fun()
{
    init();
    int r1 = 0, c1 = 0, i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            if (c[i][j] == '#' && !r1 && !c1)
            {
                r1 = i;
                c1 = j;
            }
            if (c[i][j] == '#')
                res[i - r1 + 1][j - c1 + 1] = '#';
        }
}
int main()
{
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);
    for (i = 1; i <= n; i++)
        scanf("%s", b[i] + 1);
    //printf("\n");

    for (i = 1; i <= n; i++) //初始化ans
        for (j = 1; j <= n; j++)
        {
            ans[i][j] = res[i][j] = '.';
        }

    int row = 0, col = 0;
    for (i = 1; i <= n; i++) //将b移到左上角
    {
        for (j = 1; j <= n; j++)
        {
            if (b[i][j] == '#' && !row && !col)
            {
                row = i;
                col = j;
            }
            if (b[i][j] == '#')
                ans[i - row + 1][j - col + 1] = '#';
        }
    }

    for (i = 1; i <= n; i++) //不转
    {
        for (j = 1; j <= n; j++)
            c[i][j] = a[i][j];
    }
    fun();
    if (check())
    {
        printf("Yes");
        return 0;
    }

    for (i = 1; i <= n; i++) //转向180
    {
        for (j = 1; j <= n; j++)
            c[i][j] = a[n - i + 1][n - j + 1];
    }
    fun();
    if (check())
    {
        printf("Yes");
        return 0;
    }

    for (i = 1; i <= n; i++) //左转90
    {
        for (j = 1; j <= n; j++)
            c[i][j] = a[j][n - i + 1];
    }
    fun();
    if (check())
    {
        printf("Yes");
        return 0;
    }

    for (i = 1; i <= n; i++) //右转90
    {
        for (j = 1; j <= n; j++)
            c[i][j] = a[n - j + 1][i];
    }
    fun();
    if (check())
        printf("Yes");
    else
        printf("No");
    //for(i=1;i<=n;i++)printf("%s\n",c[i]+1);
    return 0;
}