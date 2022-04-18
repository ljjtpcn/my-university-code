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
int cnt[31][2];
int main()
{

    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            for (int j = 0; j < m; j++)
            {
                int k = ((x >> j) & 1);
                cnt[j][k]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int k;
            if (cnt[i][0] != cnt[i][1])
            {
                k = cnt[i][0] > cnt[i][1] ? 0 : 1;
            }
            else
            {
                k = 0;
            }
            ans += (int)(pow(2, i) * k);
        }
        cout << ans << endl;
    }
    return 0;
}
