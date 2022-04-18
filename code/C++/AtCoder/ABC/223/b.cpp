//https://codeforces.ml/contest/1562/problem/A

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
const int N = 1e5;

vector<int> minx, maxx;
string ansmin, ansmax;
int main()
{
    string s;
    cin >> s;

    char mi, ma;
    mi = ma = s[0];
    ansmin = ansmax = s;
    for (int i = 1; i < s.size(); i++)
    {
        /* code */
        if (s[i] >= ma)
            maxx.push_back(i), ma = s[i];
        if (s[i] <= mi)
            minx.push_back(i), mi = s[i];
    }

    string ss;
    if (minx.size())
    {
        for (int i = 0; i < minx.size(); i++)
        {
            /* code */
            ss = "";
            ss += s.substr(minx[i]);
            ss += s.substr(0, minx[i]);

            if (ss < ansmin)
            {
                ansmin = ss;
            }
        }
        cout << ansmin << endl;
    }
    else
    {
        cout << s << endl;
    }

    if (maxx.size())
    {
        string ss;
        for (int i = 0; i < maxx.size(); i++)
        {
            /* code */
            ss = "";
            ss += s.substr(maxx[i]);
            ss += s.substr(0, maxx[i]);

            if (ss > ansmax)
            {
                ansmax = ss;
            }
        }
        cout << ansmax << endl;
    }
    else
    {
        cout << s << endl;
    }

    return 0;
}