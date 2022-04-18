#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t, n, x, xx;
    cin >> t;
    while (t--)
    {
        priority_queue<int, vector<int>, greater<int> > qu;
        int minmax = -1e9;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            qu.push(x);
        }
        int jian = 0;
        for (int i = 0; i < n; i++)
        {
            xx = qu.top() + jian;
            minmax = max(xx, minmax);
            jian -= xx;
            qu.pop();
        }
        printf("%d\n", minmax);
    }
    return 0;
}
