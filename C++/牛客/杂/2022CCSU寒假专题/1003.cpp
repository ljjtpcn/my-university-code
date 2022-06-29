#include <bits/stdc++.h>
using namespace std;

const int N = 510;
typedef pair<int, int> PII;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, T;
PII st, ed;
int g[N][N];

void bfs(){
    queue<PII> q;
    map<PII, int> vis;
    q.push(st);
    vis[st] = 1;

    while(q.size()){
        PII t = q.front();
        q.pop();

        if(t.first == ed.first && t.second == ed.second){
            cout << "YES" << endl;
            return;
        }
        for (int i = 0; i < 4; i ++){
            int tx = t.first + dx[i], ty = t.second + dy[i];
            if(tx >=0 && tx < m && ty >= 0 && ty < m && g[tx][ty] != 1 && !vis[{tx, ty}]){
                vis[{tx, ty}] = 1;
                q.push({tx, ty});
            }
        }
    }
    cout << "NO" << endl;
}
int main()
{
    cin >> T;
    while(T--){
        cin >> n >> m;
        getchar();
        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j ++){
                char c = getchar();
                if (c == 's')
                    st.first = i, st.second = j, g[i][j] = 0;
                if(c == 'x')
                    g[i][j] = 1;
                if(c == '.')
                    g[i][j] = 0;
                if(c == 't')
                    ed.first = i, ed.second = j, g[i][j] = 0;
            }
            getchar();
        }
        // for(int i = 0; i < n; i++){
        //     for (int  j = 0; j < m; j++)
        //     {
        //         cout << g[i][j];
        //     }
        //     cout << endl;
        // }
        bfs();
    }
    return 0;
}