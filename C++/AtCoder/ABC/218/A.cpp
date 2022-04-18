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
    int day;
    string s;
    cin >> day >> s;
    if (s[day - 1] == 'o')
        cout << "Yes";
    else
        cout << "No";

    return 0;
}