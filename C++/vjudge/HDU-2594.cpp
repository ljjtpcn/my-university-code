#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e6 + 10;

int n;
string s1, s2;
int ne[N];

void get_Next(string p)
{
    int i = 0, j = -1;
    ne[0] = -1;

    while (i < p.size())
    {
        if (j == -1 || p[i] == p[j])
        {
            i++, j++;
            ne[i] = j;
        }
        else
        {
            j = ne[j];
        }
    }
}

int main()
{
    while(cin >> s1 >> s2)
    {
        string s = s1 + s2;
        get_Next(s);
        long long ans = ne[s.size()];
        while(ans > s1.size() || ans > s2.size())
            ans = ne[ans];
        if(ne[s.size()] == 0){
            cout << 0 << endl;
            continue;
        }else{
            cout << s.substr(0, ans) << ' ' << ans << endl;
        }

            
    }
    return 0;
}