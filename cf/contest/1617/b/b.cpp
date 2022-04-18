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
    while(t --){

            cin >> n;
            int x = n - 1;
            if (x & 1)
                cout << x / 2 << ' ' << x / 2 + 1 << ' ' << 1 << endl;
            else
            {
                if (x / 2 & 1)
                {
                    cout << x / 2 - 2 << ' ' << x / 2 + 2 << ' ' << 1 << endl;
                }
                else
                {
                    cout << x / 2 - 1 << ' ' << x / 2 + 1 << ' ' << 1 << endl;
                }
            }

    }


    return 0;
}
