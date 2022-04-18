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
string str;
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

    while (cin >> str)
    {
        get_Next(str);
        for (int i = 0; i <= str.size(); i ++)
            cout << ne[i] << ' ';
    }

    return 0;
}