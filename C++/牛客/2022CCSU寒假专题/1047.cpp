#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 2e5 + 10;

int n, m, st, ed;
int h[N], e[N*2], ne[N*2], w[N*2], idx;
int dist[N], vis[N];
 
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dij(){
    memset(dist, 0x3f, sizeof(dist));
    dist[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, st});
    while(q.size()){
        auto t = q.top(); q.pop();
        
        int u = t.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for (int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[u] + w[i]){
                dist[j] = dist[u] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[ed];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    st = 1, ed = n;
    dij();
    if(dist[ed] >= 0x3f3f3f3f)
        cout << "qwb baka";
    else
        cout << dist[ed];
    return 0;
}
