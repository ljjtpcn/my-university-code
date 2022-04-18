#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5e5 + 10;

int n, m, t;
ll ans, cnt;
int arr[N];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] & 1)
        {
            v.push_back(i);
        }
    }
    if (v.size() == 1)
    {
        ans += v[0] * (n - v[0] + 1);
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            int l, r;
            if (v[i] == 1)
            {
                ans += n;
            }
            else
            {
                l = v[i - 1];
                r = v[i];
                int _l = r - l, _r = n - r + 1;
                ans += _l * _r;
            }
        }
    }

    cout << ans;
    return 0;
}
