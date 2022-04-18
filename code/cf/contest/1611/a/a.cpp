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

int t;
string str;
int ne[N];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> str;
        int n = str.size();
        if ((str[n - 1] - '0') % 2 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if ((str[0] - '0') % 2 == 0)
        {
            cout << 1 << endl;
            continue;
        }
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if ((str[i] - '0') % 2 == 0)
            {
                cout << 2 << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << -1 << endl;
    }

    return 0;
}
