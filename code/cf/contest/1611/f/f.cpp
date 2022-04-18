#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2e6 + 10;

int n, t, s;
string str;
vector<int> arr;

signed main()
{
    cin >> t;
    while (t--)
    {
        PII p = {0, 0};
        arr.clear();
        cin >> n >> s;

        arr.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        int sum = 0, cnt = 0;
        //2 6 -164 1 -1 -6543
        //     i
        //  j
        //2+6-2-6

        int i = 1, j = 0;
        while (i <= n)
        {
            while (j + 1 <= n && sum + arr[j + 1] >= -s)
            {
                sum += arr[j + 1];
                j++;
            }
            if ((p.second < j - i + 1) && sum >= -s)
            {
                p.first = i, p.second = j - i + 1;
            }
            sum -= arr[i];
            i++;
        }
        
        if (p.first == 0 && p.second == 0)
            cout << -1 << endl;
        else
            cout << p.first << ' ' << p.first + p.second - 1 << endl;
    }

    return 0;
}
