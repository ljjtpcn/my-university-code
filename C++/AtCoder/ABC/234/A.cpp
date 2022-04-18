#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;

int f(int t)
{
    return t * t + 2 * t + 3;
}

int main()
{
    cin >> t;
    int ans = f(f(f(t) + t) + f(f(t)));
    cout << ans << endl;
    return 0;
}