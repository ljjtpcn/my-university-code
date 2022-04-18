#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

int n;
double s[N], v[N];
double t, ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> s[i] >> v[i];
        t += s[i] * 1.0 / v[i];
    }
    t = t / 2.0;
    int i = 0;
    while (t != 0)
    {
        if (t >= s[i] / v[i])
        {
            ans += s[i];
            t -= s[i] / v[i];
            i++;
        }
        else
        {
            ans += v[i] * t;
            t = 0;
        }
    }
    printf("%.6lf", ans);

    return 0;
}