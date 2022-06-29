#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;

int main()
{
    cin >> t;
    while(t --){
        cin >> n >> m >> k;
        string s[n];
        for(int i = 0; i < n; i++) cin >> s[i];

        int flag = 0;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            if(flag) continue;
            if(s[x-1][y-1] == '*'){
                cout << "Game over in step " << i + 1 << endl;
                flag = 1;
            }
            if(s[x-1][y-1] == '.'){
                s[x-1][y-1] = '0';
            }
        }
        if(!flag){
            for(int i = 0; i < n; i++)
                cout << s[i] << endl;
        }
    }
    return 0;
}