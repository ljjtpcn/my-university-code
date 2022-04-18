#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
const int maxn = 1e6 + 5;

int a, b;
map<int, int> mp;
vector<int> ans;
int main()
{
    int d;
    while(cin >> a >> b)
    {
        printf("%d/%d = ", )
        int cnt = 0;
        ans.clear();
        mp.clear();
        if(a < b)
        while (1)
        {
            /* code */
            d = a % b;
            if(mp[d] == 1)
                break;
            else
                mp[d] = 1;
            cnt++;
            a = d * 10;
        }
        if(mp[0] != 1)cout << cnt << endl;
    }
    return 0;
}
