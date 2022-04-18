#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1000;

int n, m;
char g[N][N];
int f[N][N];
int maxn = 0;
int score[N];

int main()
{
    score['l'] = 4, score['o'] = 3, score['v'] = 2, score['e'] = 1;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j],
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + score[g[i][j]];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            maxn = max(maxn, f[i][j]);
    cout << maxn;
    return 0;
}