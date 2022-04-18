#include <bits/stdc++.h>
#define readi() read<int>()
#define readl() read<ll>()
#define pb push_back
using namespace std;

template<typename T> inline T read()
{
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch=='-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
void split(const string& s, vector<string>& tokens, const string& delimiters)
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}
typedef pair<int, int> pii;
typedef long long ll;
const int N = 100 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


void solve(){
    int n; cin >> n;
    string g[n];

    pair<int, int> st, ed;
    for(int i = 0; i < n; i++){
        cin >> g[i];
        for(int j = 0; j < n; j ++ ){
            if(g[i][j] == 'A')  st = {i, j};
            if(g[i][j] == 'B')  ed = {i, j};
        } 
    } 
    
    int dic[N][N][4];
    memset(dic, 0x3f, sizeof dic);
    int res = INT_MAX;
    auto bfs = [&](){
        deque<array<int, 4>> dq;
        dq.push_front({st.first, st.second, 0, 0});
        dq.push_front({st.first, st.second, 1, 0});
        dq.push_front({st.first, st.second, 2, 0});
        dq.push_front({st.first, st.second, 3, 0});

        while(dq.size()){
            auto[x, y, dir, step] = dq.front();
            dq.pop_front();

            if(x == ed.first && y == ed.second){
                res = min(res, step);
                continue;
            }

            for(int i = 0; i < 4; i ++){
                int tx = x + dx[i], ty = y + dy[i];
                if(tx < 0 || tx >= n || ty < 0 || ty >= n|| g[tx][ty] == 'x') continue;

                if(i != dir){
                    if(dic[tx][ty][i] > step + 1)
                        dq.push_back({tx, ty, i, step + 1});
                        dic[tx][ty][i] = step + 1;
                }else{
                    if(dic[tx][ty][i] > step)
                        dq.push_front({tx, ty, i, step});
                        dic[tx][ty][i] = step;
                }
            }
        }
       cout << (res == INT_MAX ? -1 : res) << endl;
    };

    bfs();
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
} 