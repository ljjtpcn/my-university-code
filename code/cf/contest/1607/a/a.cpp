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
string s, tt;
int ne[N];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> tt;
        int cnt = 0;
        for (int i = 1; i < tt.size(); i++)
        {
            int x = s.find(tt[i]) - s.find(tt[i - 1]);
            cnt += abs(x);
        }
        cout << cnt << endl;
    }

    return 0;
}
