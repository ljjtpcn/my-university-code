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
vector<int> v;
int main()
{

    cin >> t;

    while (t--)
    {
        v.clear();
        for (int i = 0; i < 7; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << v[0] << " " << v[1] << " ";
        for (int i = 2; i < 7; i++)
        {
            if (v[6] - v[0] - v[1] == v[i])
            {
                cout << v[i] << endl;
                break;
            }
        }
    }
    return 0;
}
