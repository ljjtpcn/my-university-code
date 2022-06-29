//https://vjudge.net/problem/HDU-2087

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
const int N = 1e5;

int n, m;
int ne[N];

void get_Next(string p)
{
    int i = 0, j = -1;
    ne[0] = -1;

    while (i < p.size() - 1)
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
    int i = 0, j = 0;
    get_Next(p);

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

        if (j >= m)
        {
            cnt++;
            j = 0;
        }
    }

    return cnt;
}
int main()
{
    string str, p;
    cin >> str;
    while (str != "#")
    {
        cin >> p;
        cout << KMP(str, p) << endl;
        cin >> str;
    }

    return 0;
}