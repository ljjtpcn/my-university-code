//https : //www.cnblogs.com/yym2013/p/3586495.html
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    long long ans = 0;
    do
    {
        for (int i = 1; i < s.size(); i++)
        {
            long long t1 = atoi(s.substr(0, i).c_str());
            long long t2 = atoi(s.substr(i).c_str());
            ans = max(ans, 1ll * t1 * t2);
            //cout << t1 << "*" << t2 << "==" << t1 * t2 << endl;
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << ans;
    return 0;
}