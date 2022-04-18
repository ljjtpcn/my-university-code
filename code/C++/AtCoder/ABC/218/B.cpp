//https://codeforces.ml/contest/1562/problem/A

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e5;

int main()
{
    for(int i = 0; i < 26; i ++)
    {
        int c; cin >> c;
        cout << (char)('a' + c - 1);
    }

    return 0;
}  