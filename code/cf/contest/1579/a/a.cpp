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

int n, m, t;
string str;
int ne[N];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> str;
        int a, b, c;
        a = b = c = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'A')
                a++;
            if (str[i] == 'B')
                b++;
            if (str[i] == 'C')
                c++;
        }
        if (a + c != b)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
