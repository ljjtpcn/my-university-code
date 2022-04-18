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

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e6 + 10;

int n;
string str;
int ne[N];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() != s2.size())
    {
        cout << "No";
        return 0;
    }
    if (s1 == s2)
    {
        cout << "Yes";
        return 0;
    }
    vector<int> a;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
            a.push_back(i);
    }
    if (a.size() == 2 && (int)abs(a[1] - a[0]) == 1)
    {
        if (s1[a[0]] == s2[a[1]] && s1[a[1]] == s2[a[0]])
            cout << "Yes";
        else
            cout << "No";
    }
    else
        cout << "No";
    return 0;
}