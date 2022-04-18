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

int n, m, t;
vector<int> arr;
int ne[N];

int main()
{

    cin >> t;
    while (t--)
    {
        memset(ne, 0, sizeof ne);
        arr.clear();
        cin >> n;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
            ne[i] = x;
        }
        sort(ne, ne + n);
        for (int i = 0; i < n; i++)
        {
            int t = find(arr.begin(), arr.end(), ne[i]) - arr.begin();
            if (t == i)
                continue;
            int x = arr[t], j;
            for (j = t - 1; j >= i; j--)
                arr[j + 1] = arr[j];
            arr[j] = x;
            cout << i + 1 << ' ' << t + 1 << ' ' << t - i << endl;
        }
    }
    
    return 0;
}
