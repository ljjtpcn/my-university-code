#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<pair<int, int> , int> pii;

int t, n, m;
pair<int, int> st, ed, fire;
string s[35];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(){
    queue<pii> q;
    q.push({{st}, 0});
    s[st.first][st.second] = '#';
    while(q.size()){
        pii t = q.front();
        q.pop();
        int x = t.first.first ,y = t.first.second;
        for (int i = 0; i < 4; i ++){
            int tx = x + dx[i], ty = y + dy[i], td = t.second + 1;
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && s[tx][ty] != '#'){
                if (s[tx][ty] == 'E' && td <= max(abs(tx - fire.first), abs(ty - fire.second))){
                    cout << td << endl;
                    return;
                }
                if(td < max(abs(tx - fire.first), abs(ty - fire.second))){
                    q.push({{tx, ty}, td});
                    s[tx][ty] = '#';
                }
            }
        }
    }
    cout << "T_T" << endl;
    return;
}

int main()
{
    cin >> t;
    while(t --){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> s[i];
            for(int j = 0; j < m; j++){
                if(s[i][j] == 'S')
                    st = {i, j};
                if(s[i][j] == 'E')
                    ed = {i, j};
                if(s[i][j] == '*')
                    fire = {i, j};
            }
        }
        bfs();
    }
    return 0;
}