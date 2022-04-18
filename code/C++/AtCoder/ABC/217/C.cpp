//https://atcoder.jp/contests/abc217/tasks/abc217_c

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
const int N = 2e5 + 10;

int p[N], q[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        int x; cin >> x;
        p[i] = x;
        q[x] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cout << q[i] << ' ';
    }
    

    return 0;
}
