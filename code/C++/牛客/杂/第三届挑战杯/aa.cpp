# include<iostream>
# include<queue>
# include<cstring>
# include<algorithm>
using namespace std;
// typedef pair<int, int> PII;
char g[110][110];
int mp[110][110][4];//f[i][j][x]表示从哪个方向来(i,j)点，0-东，1-南，2-西，3-北
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int sx, sy, n;
bool vis[110][110];
struct node
{
    int x, y, steps, dir;//分别代表x坐标，y坐标，拐弯次数，上一步的方向
    bool operator< (const struct node &a)const
    {
        return steps > a.steps;
    }
};

priority_queue<node> q;

void bfs()
{       
    int res = 1e9;//记录最小值
    
    while(!q.empty())
    {

        node t = q.top();
        q.pop();
        int x = t.x, y = t.y;

        // cout << "x = " << x << " y  = " << y << " steps = " << t.steps << " dir = " << t.dir << endl;
        // system("pause");
        if(g[x][y] == 'B')//到达终点
        {
            res = min(res,t.steps);
            continue;
        }
            
        for (int i = 0; i < 4;i++)//分别枚举下一步的四个方向
        {
            int a = x + dx[i], b = y + dy[i];
            int steps = t.steps, dir = t.dir;
            if(g[a][b] == 'x' || a < 0 || a >= n || b < 0 || b >= n)
                continue;
            if(i != dir)//两个方向不同时，拐弯数++
                steps++;
            if(mp[a][b][i] > steps)//判断大小，是否可以入队
            {
                mp[a][b][i] = steps;
                q.push({a, b, steps, i}); 
            }
        }

    }

    if(res < 1e9)
        printf("%d\n", res);
    else
        printf("-1\n");
    while(!q.empty())
        q.pop();
}

void solve()
{
    memset(mp, 0x3f, sizeof mp);
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        scanf("%s", g[i]);

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            vis[i][j] = 0;
            if(g[i][j] == 'A')
            {
                for (int k = 0; k < 4; k++)
                    q.push({i, j, 0, k});
            } 
        }   
    }
    bfs();
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while(t --)
    {
        solve();
    }
    return 0;
}