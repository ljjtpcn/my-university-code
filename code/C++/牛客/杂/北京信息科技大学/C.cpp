#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 4e5;

int n, s;
set<int> st;
long long ans;
int minx = 99999999999999, maxn;

signed main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        minx = min(minx, x);
        maxn = max(maxn, x);
    }
    if (s <= minx)
        cout << maxn - s;
    else if (s < maxn)
    {
        if (abs(s - minx) <= abs(s - maxn))
            cout << abs(s - minx) + (maxn - minx);
        else
            cout << abs(s - maxn) + (maxn - minx);
    }
    else if (s >= maxn)
        cout << s - minx;
    
    
    return 0;
}