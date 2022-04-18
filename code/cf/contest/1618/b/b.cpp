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
/*
7   abbaaba   abbaa ba
ab bb ba aa ba
7 abaabaa
ab ba aa ab ba
3
aa
5
bb ab bb
*/
int main()
{
    cin >> t;
    while( t-- )
    {
        str = "";
        cin >> n >> str;
        for (int i = 1; i < n - 2; i++)
        {
            int length = str.size();
            string ss;
            cin >> ss;
            if(ss[0] == str[length - 1])
                str += ss[1];
            else
                str += ss;
        }
        if(str.size() != n)
            str += "b";
        cout << str << endl;
    }
    return 0;
}
