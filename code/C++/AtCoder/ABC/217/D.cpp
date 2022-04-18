// https://atcoder.jp/contests/abc217/tasks/abc217_d

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 2e5 + 10;

int L, Q;
PII x[N];

set<int> st;

int main()
{
    cin >> L >> Q;
    st.insert(1), st.insert(L);

    for (int i = 0; i < Q; i++)
    {
        /* code */
        int q, x;
        cin >> q >> x;
        if (q == 1)
            st.insert(x);
        else
        {
            auto tmin = st.lower_bound(x);
            if (tmin != st.begin())
                tmin--;
            auto tmax = st.upper_bound(x);
            if (tmax == st.end())
                tmax--;

            if(*tmin == 1) cout << *tmax << endl;
            else cout << *tmax - *tmin<< endl;
        }
    }

    return 0;
}