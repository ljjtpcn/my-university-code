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
        if(str == ".") break;
        memset(ne, 0, sizeof ne);
        get_Next(str);

        int n = str.size();

        if (n % (n - ne[n]) == 0)
            cout << n / (n - ne[n]) << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}