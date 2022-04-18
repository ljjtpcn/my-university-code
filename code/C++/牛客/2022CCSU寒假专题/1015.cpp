#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, ans;
vector<pii> node;
priority_queue<pii> q;

bool cmp(pii a, pii b) {
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int cost, end;
        cin >> cost >> end;
        node.push_back({cost, end});
    }
    sort(node.begin(), node.end(), cmp);

    int time = 0;
    for(int i = 0; i < n; i++){
        if(time + node[i].first <= node[i].second){
            time += node[i].first;
            q.push(node[i]);
        }else{
            if(q.top().first > node[i].first){
                time -= q.top().first;
                q.pop();
                time += node[i].first;
                q.push(node[i]);
            }
        }
    }
    cout << q.size();
    return 0;
}