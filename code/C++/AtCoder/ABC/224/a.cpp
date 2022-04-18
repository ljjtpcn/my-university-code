//https://codeforces.ml/contest/1562/problem/A

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
const int N = 1e5;

int n, m, t;

int main()
{
    string s;
    cin >> s;
    if(s.substr(s.size()-2) == "er")
        cout <<"er";
    else
        cout << "ist";
    return 0;
}