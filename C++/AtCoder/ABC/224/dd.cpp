#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int n;
int vis[1000];
vector<int> g[1000];
string str, End = "12345678";
map<string, int> mp;

struct node
{
    string s;
    int cnt, o;
};


int fun(string a)
{
    for (int i = 1; i <= 9; i++)
        vis[i] = 0;
    for (int i = 0; i < 8; i++)
        vis[a[i] - '0']++;
    for (int i = 1; i <= 9; i++)
        if (!vis[i])
            return i;
}
void bfs()
{
    queue<node> q;
    q.push({str, 0, fun(str)});
    while (!q.empty())
    {
        node k = q.front();
        q.pop();
        mp[k.s]++;
        if (k.s == End)
        {
            printf("%d", k.cnt);
            return;
        }
        
        for (int i = 0; i < g[k.o].size(); i++)
        {
            string t = k.s;
            int v = g[k.o][i];

            int j;
            for (j = 0; j < 8; j++)
                if (t[j] - '0' == v)
                    break;

            t[j] = k.o + '0';
            if (mp[t] == 0)
            {
                mp[t]++;
                q.push({t, k.cnt + 1, fun(t)});
            }
        }
    }
    cout << -1;
}
int main()
{
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
   
    for (int i = 1; i <= 8; i++)
    {
        string s;
        cin >> s;
        str += s[0];
    }

    bfs();

    return 0;
}
