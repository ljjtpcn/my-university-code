#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5e4 + 10;
int n, t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t; 
    while(t --){
        vector<int> v;
        map<string, bool> mp;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(mp[to_string(x)] == false)
                v.push_back(x), mp[to_string(x)] = true;
        }
        for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << endl;
        
    }
    return 0;
}
