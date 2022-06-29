//https://codeforces.ml/contest/1562/problem/A

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
const int N = 1e5;

int n, m, t;

int x[N], y[N];

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
            {
                if ((x[k] - x[j]) * (y[k] - y[i]) != (x[k] - x[i]) * (y[k] - y[j]))
                    cnt++;
            }
    cout << cnt;
    return 0;
}