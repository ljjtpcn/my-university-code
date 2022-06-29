#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, cnt;
int t, flag;
string s[N];

void dfs(int x, int y){
    s[x][y] = '@';
    t++;

    if(x == 0 || x == n-1 || y == 0 || y == m-1){
        flag = 1;
    }
    for (int i = 0; i < 4; i ++){
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && ty >= 0 && tx < n && ty < m && s[tx][ty] == '.'){
            dfs(tx, ty);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++){
            if(s[i][j] == '.'){
                flag = t = 0;
                dfs(i, j);
                if(!flag) cnt += t;
            }else if(s[i][j] == '#'){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}