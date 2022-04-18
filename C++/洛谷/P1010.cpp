#include <bits/stdc++.h>
using namespace std;
int f[30];

string ans;
// string ss[13] {
//     "2(0)", "2", "2(2)", "2(2 + 2(0))",
//     "2(2(2))", "2(2(2) + 2(0))", "2(2(2) + 2(0))"
// }
// 
void dfs(int n, bool flag)
{
    if (flag) ans += '+';
    ans += '2';
    if (n == 1)
        return;
    ans += '(';
    int t = log(n) / log(2);
    int sum = 0;
    flag = false;
    if (n == 2 || n == 0)
        ans += n + '0';
    else for (int i = t; i >= 0; i -- )
    {
        if (sum + f[i] <= n)
        {
            sum += f[i];
            dfs(i, flag);
            flag = true;
        }
    }
    ans += ')';
}

void init()
{
    f[0] = 1;
    for (int i = 1; i <= 26; i ++ )
        f[i] = 2 * f[i - 1];
}

int main()
{
    init();
    int n;
    cin >> n;
    dfs(n, false);
    for (int i = 2; i < ans.size() - 1; i ++ )
        cout << ans[i];
        return 0;
}