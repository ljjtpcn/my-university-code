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
const int N = 1e4 + 10;

int n, m;
int a[N][N];
int f[N][N];

int main()
{

    cin >> n >> m;
    for (int  i = 1; i <= n; i++)
        for (int j = 1; j <= m; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j++)
        {
            if(i > 1){
                if(a[i-1][j] > a[i][j])
                    f[i][j] = max(f[i][j], f[i - 1][j] + 1);
            }
            if (i < n){
                if (a[i+1][j] > a[i][j])
                    f[i][j] = max(f[i][j], f[i+1][j] + 1);
            }
            if (j > 1){
                if (a[i][j-1] > a[i][j])
                    f[i][j] = max(f[i][j], f[i][j-1] + 1);
            }
            if (j < m){
                if (a[i][j + 1] > a[i][j])
                    f[i][j] = max(f[i][j], f[i][j + 1] + 1);
            }
        }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, f[i][j]);

    cout << res;
    return 0;
}