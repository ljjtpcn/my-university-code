#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;

int n, q;
vector<int> arr[N];
int idx;
map<int, int> mp;
int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(!mp[x]){
            mp[x] = ++idx;
        }
        arr[mp[x]].push_back(i);
    }
    for (int i = 0; i < q; i ++){
        int x, k;
        cin >> x >> k;
        if(mp.count(x) == 0) cout << -1 << endl;
        else{
            if(arr[mp[x]].size() < k)
                cout << -1 << endl;
            else
                cout << arr[mp[x]][k - 1] << endl;
        }
    }
    return 0;
}
