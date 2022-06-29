#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e3 + 10;

int n, m;
int book[N], person[N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> book[i];
    sort(book, book + n);

    while(m--){
        int idx;string sub;
        cin >> idx >> sub;

        int flag = 0;
        for (int j = 0; j < n; j++){
            string s = to_string(book[j]);
            if (s.rfind(sub) != s.npos && s.rfind(sub) == s.size()-idx){
                cout << book[j] << endl;
                flag = 1;break;
            }
        }
        if(!flag) cout << -1 << endl;           
    }
    return 0;
}
