#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, x, arr[N];
map<int, int> st;
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st[arr[i]] = 1;
    }
    int t = -x;
    int a, b, c;
    for (int i = 0; i < n; i++)
    {
        a = arr[i];
        b = a * 2 * t;
        c = a * t * t;
        if (st[b] && st[c])
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}