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
string str;
vector<int> arr;
deque<int> q;
int main()
{
    cin >> t;
    while (t--)
    {
        arr.clear();
        q.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        if (arr[0] == n || arr[n - 1] == n)
        {
            int i = 0, j = n - 1;
            while (q.size() != n)
            {
                if (arr[i] < arr[j])
                {
                    q.push_back(arr[j]);
                    j--;
                }
                else
                {
                    q.push_front(arr[i]);
                    i++;
                }
                if (i == j)
                    q.push_back(arr[i]);
            }
            for (auto i : q)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
