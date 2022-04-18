//https://vjudge.net/problem/HDU-1686

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
const int N = 1e6 + 10;

int t, n, m;
int ne[10005];

void get_Next(string p)
{
    int m = p.size();
    int i = 0, j = -1;
    ne[0] = -1;

    while (i < m - 1)
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

int KMP(string str, string p)
{
    n = str.size(), m = p.size();
    get_Next(p);

    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m)
    {
        if (j == -1 || str[i] == p[j])
        {
            i++, j++;
        }
        else
        {
            j = ne[j];
        }
        //....................
        if (j >= m)
        {
            j = ne[j - 1];
            i--;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin >> t;
    while (t--)
    {
        string str, p;
        cin >> p >> str;
        cout << KMP(str, p) << endl;
        //for (int i = 0; i < p.size(); i ++ ) cout << ne[i] << ' ';
    }

    return 0;
}