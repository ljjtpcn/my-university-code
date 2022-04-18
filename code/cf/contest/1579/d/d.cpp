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
priority_queue<PII> q;
vector<PII> vc;

int main()
{

    cin >> t;
    while (t--)
    {
        vc.clear();
        while (!q.empty())
            q.pop();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            /* code */
            int x;
            cin >> x;
            if (x != 0)
                q.push({x, i});
        }

        int ans = 0;
        while (q.size() > 1)
        {
            int max = q.top().first;
            int idx = q.top().second;
            q.pop();
            int min = q.top().first;
            int idx2 = q.top().second;
            q.pop();
            if (max >= 1 && min >= 1)
            {
                ans++;
                vc.push_back({idx, idx2});
                q.push({max - 1, idx});
                q.push({min - 1, idx2});
            }
        }

        cout << ans << endl;
        for (auto it = vc.begin(); it < vc.end(); it++)
        {
            /* code */
            cout << (*it).first << ' ' << (*it).second << endl;
        }
    }

    return 0;
}
