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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
const int N = 100 + 10;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};

void solve(){
    ll n, m, s, e, f;
    cin >> n >> m >> s >> e >> f;

    vector<array<ll, 2>> v[N]; 
    auto add = [&](ll a,ll b, ll c){
        v[a].push_back({b, c});
    };

    while(m --){
        ll a, b, c, d, cc;
        cin >> a >> b >> c >> d >> cc;
        if(f > d){  
            add(a, b, c * d + (f - d) * cc);
        }else{
            add(a, b, c * f);
        }
    }

    
    auto dij = [&]() -> ll {

        ll dist[N]; int st[N] = {0};
        memset(dist, 0x7f, sizeof dist);
        dist[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while(q.size()){
            auto [distance, now] = q.top();
            q.pop();

            if(st[now]) continue;
            st[now] = 1;
            for(auto [ne, dis] : v[now]){
                if(dist[ne] > distance + dis){
                    dist[ne] = distance + dis;
                    q.push({dist[ne], ne});
                }
            }
        }
        return dist[e];
    };
    
    cout << dij() << endl;
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}