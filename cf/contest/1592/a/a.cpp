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

int n, h, t;
string str;
int a[N];

int main()
{

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &h);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int d = a[n - 1] + a[n - 2];
        if (h <= a[n - 1])
        {
            puts("1");
            continue;
        }
        else if (h > a[n - 1] && h < d)
        {
            puts("2");
            continue;
        }
        else
        {
            int k = h / d * 2;
            int kk = h % d;
            if (kk != 0)
            {
                if (kk <= a[n - 1])
                {
                    printf("%d\n", k + 1);
                }
                else
                {
                    printf("%d\n", k + 2);
                }
            }
            else
            {
                printf("%d\n", k);
            }
        }
    }
    return 0;
}
