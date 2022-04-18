#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2e5 + 10;

int n, m, t;
int vis[N];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        vector<int> arr(n);
        vector<int> un[N];
        int flag = 0, maxx = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxx = max(maxx, arr[i]);
            un[arr[i]].push_back(i);
            if (!vis[arr[i]])
                vis[arr[i]] = 1;
            else
                flag = 1;
        }
        if (!flag)
        {
            cout << -1 << endl;
            continue;
        }
        int x = INT_MAX;
        for (int i = 1; i <= maxx; i++)
        {
            if (un[i].size() >= 2)
            {
                for (int j = 1; j < un[i].size(); j++)
                {
                    x = min(x, un[i][j] - un[i][j - 1]);
                }
            }
        }
        //cout << ll << ' ' << rr << endl;
        cout << n - x << endl;
    }
    return 0;
}
