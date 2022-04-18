#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e6 + 10;

int n, m, sum, ans;
string str;
int ne[N];
multiset<int> st;
signed main()
{

    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%lld", &x);
        st.insert(x);
        sum += x;
    }
    scanf("%lld", &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        ans = 999999999;
        auto it = st.lower_bound(x);
        auto itt = st.lower_bound(x);
        if (itt != st.begin())
            itt--;
        if (it != st.end())
        {
            //printf("%d\n", sum - *it > y ? 0 : y - (sum - *it));
            if (it != itt)
                ans = min((sum - *it >= y ? 0 : y - (sum - *it)), (x - *itt + (sum - *itt >= y ? 0 : y - (sum - *itt))));
            else
                ans = sum - *it >= y ? 0 : y - (sum - *it);
            printf("%lld\n", ans);
        }
        else
        {
            --it;
            int d = x - *it;
            printf("%lld\n", sum - *it >= y ? d : y - (sum - *it) + d);
        }
    }
    return 0;
}

