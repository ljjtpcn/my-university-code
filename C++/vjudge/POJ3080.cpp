#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s[100000];
int t;

int main()

{
    cin >> t;
    while(t --)
    {
        string ans = "";
        int flag, n;
        cin >> n;
        for (int i = 0; i < n; i ++)
            cin >> s[i];

        for (int i = 0; i <= s[0].size(); i ++){
            for (int j = 0; j < s[0].size(); j ++){
                flag = 0;
                string tt = s[0].substr(j, i);
                for (int k = 1; k < n; k ++){
                    if(s[k].find(tt) == s[k].npos){
                        flag = 1;
                        break;
                    }
                }
                if(!flag){
                    if(tt.size() > ans.size())
                    ans = tt;
                    else if(tt.size() == ans.size() && tt < ans)
                    ans = tt;
                }
            }
        }
        if(ans.size() < 3)
            cout << "no significant commonalities" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}