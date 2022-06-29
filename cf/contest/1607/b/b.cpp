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

ll s, n, m, t;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> n;
        if (s % 2 == 0)
        {
            if (n % 4 == 0)
                cout << s << endl;
            else if (n % 4 == 1)
                cout << s - n << endl;
            else if (n % 4 == 2)
                cout << s + 1 << endl;
            else
                cout << s + 1 + n << endl;
        }
        else
        {
            if (n % 4 == 0)
                cout << s << endl;
            else if (n % 4 == 1)
                cout << s + n << endl;
            else if (n % 4 == 2)
                cout << s - 1 << endl;
            else
                cout << s - 1 - n << endl;
        }
    }

    return 0;
}