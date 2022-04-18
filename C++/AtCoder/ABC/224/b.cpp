//https://codeforces.ml/contest/1562/problem/A

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
const int N = 1e4;

int n, m, t;
int a[N][N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];

    for (int i1 = 1; i1 <= n; i1++)
        for (int i2 = i1 + 1; i2 <= n; i2++)
            for (int j1 = 1; j1 <= m; j1++)
                for (int j2 = j1+1; j2 <= m; j2++)
                {
                    if(a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2])
                        {
                            cout << "No";
                            return 0;
                        }
                }

    cout << "Yes";
    return 0;
}