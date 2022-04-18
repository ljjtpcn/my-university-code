#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, r, t;

int solve(int x)
{
    queue<int> q;
    q.push(4);
    q.push(7);
    while (!q.empty())
    {
        t = q.front();
        if (t >= x)
            return t;
        q.pop();
        q.push(10 * t + 4);
        q.push(10 * t + 7);
    }
    return -1;
}

signed main()
{
    cin >> l >> r;

    long long sum = 0;
    while (l <= r)
    {
        int x = l;
        int _r = solve(x);
        // cout << _r << "________" << x << endl;
        if (_r <= r)
        {
            sum += (_r - l + 1) * _r;
            l = _r + 1;
        }
        else
        {
            sum += (r - l + 1) * _r;
            break;
        }
    }
    cout << sum;
}