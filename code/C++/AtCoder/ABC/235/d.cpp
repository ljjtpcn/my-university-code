#include <bits/stdc++.h>
using namespace std;
int a;
string N;
unordered_map<string, bool> mp;

int bfs(){
    queue<pair<string, int>> q;
    q.push({N, 0});
    mp[N] = true;
    while(q.size()){
        auto [s, cnt] = q.front(); q.pop();
        int x = stoi(s);
        if(x == 1) return cnt;
        if(x % a == 0) {
            string to_1 = to_string(x / a);
            if(!mp.count(to_1)) q.push({to_1, cnt + 1}), mp[to_1] = true;
        } 
        if(s.size() > 1 && s[1] != '0') {
            string to_2(s.begin() + 1, s.end()); to_2 += s[0];
            if(!mp.count(to_2)) q.push({to_2, cnt + 1}), mp[to_2] = true;
        }    
    }
    return -1;
}

int main(){
    cin >> a >> N;
    cout << bfs();
    return 0;
}
