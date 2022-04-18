#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e6 + 10;

int n, m, t;
string str;
deque<int> dq;

int main()
{
    cin >> t;
    while (t--)
    {
        dq.clear();
        cin >> n;
        int x;
        cin >> x;
        dq.push_front(x);
        for (int i = 1; i < n; i++)
        {
            cin >> x;
            if (x < dq.front())
                dq.push_front(x);
            else
                dq.push_back(x);
        }
        for (auto it = dq.begin(); it < dq.end(); it++)
        {
            /* code */
            cout << *it << ' ';
        }
        cout << endl;
    }

    return 0;
}
