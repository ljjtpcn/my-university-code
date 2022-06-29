#include <bits/stdc++.h>
using namespace std;

const int N = 510;
typedef pair<int, int> PII;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, T;
PII st, ed, K, D;
string s[N];

//不拿钥匙直接走
int bfs1()
{
    queue<pair<PII, int>> q;
    map<PII, int> vis;
    q.push({st, 0});
    vis[st] = 1;

    while (q.size())
    {
        pair<PII, int> t = q.front();
        q.pop();

        if (t.first.first == ed.first && t.first.second == ed.second)
        {
            return t.second;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = t.first.first + dx[i], ty = t.first.second + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m &&
                s[tx][ty] != 'W' && s[tx][ty] != 'D' &&
                !vis[{tx, ty}])
            {
                vis[{tx, ty}] = 1;
                q.push({{tx, ty}, t.second + 1});
            }
        }
    }
    return 999999;
}

//先拿钥匙
int bfs2()
{
    queue<pair<PII, int>> q;
    map<PII, int> vis;
    q.push({st, 0});
    vis[st] = 1;

    while (q.size())
    {
        pair<PII, int> t = q.front();
        q.pop();

        if (t.first.first == K.first && t.first.second == K.second)
        {
            return t.second;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = t.first.first + dx[i], ty = t.first.second + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m &&
                s[tx][ty] != 'W' && s[tx][ty] != 'D' &&
                !vis[{tx, ty}])
            {
                vis[{tx, ty}] = 1;
                q.push({{tx, ty}, t.second + 1});
            }
        }
    }
    return 999999;
}

//拿到钥匙后找出口
int bfs3()
{
    queue<pair<PII, int>> q;
    map<PII, int> vis;
    q.push({K, 0});
    vis[K] = 1;

    while (q.size())
    {
        pair<PII, int> t = q.front();
        q.pop();

        if (t.first.first == ed.first && t.first.second == ed.second)
        {
            return t.second;
        }
        for (int i = 0; i < 4; i++)
        {
            int tx = t.first.first + dx[i], ty = t.first.second + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m &&
                s[tx][ty] != 'W' &&
                !vis[{tx, ty}])
            {
                vis[{tx, ty}] = 1;
                q.push({{tx, ty}, t.second + 1});
            }
        }
    }
    return 999999;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
                st.first = i, st.second = j;
            if (s[i][j] == 'E')
                ed.first = i, ed.second = j;
            if (s[i][j] == 'K')
                K.first = i, K.second = j;
            if (s[i][j] == 'D')
                D.first = i, D.second = j;
        }
    }

    int ans1 = bfs1();
    int ans2 = bfs2();
    int ans3 = bfs3();
    // cout << ans1 << " " << ans2 << " " << ans3 << endl << endl;
    int ans = min(ans1, ans2 + ans3);
    if (ans >= 999999)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}