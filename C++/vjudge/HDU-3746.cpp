//https://vjudge.net/problem/HDU-3746

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2e5;

int t;
int ne[N];

void get_Next(string s)
{
    int i = 0, j = -1;
    ne[0] = -1;

    while(i < s.size())
    {
        if(j == -1 || s[i] == s[j])
        {
            i++, j++;
            ne[i] = j;
        }else{
            j = ne[j];
        }
    }
    
}

int main()
{
    cin >> t;
    while(t --)
    {
        string s;
        cin >> s;
        get_Next(s);
        
        int len = s.size();
        int x = len - ne[len];
        if (ne[len] && len % x == 0)
        {
            cout << 0 << endl;
        }else{
            cout << x - len%x << endl;
        }
    }

    return 0;
}