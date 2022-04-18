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

int main()
{
    int x;
    cin >> x;
    if(x == 0){
        cout << "No";
        return 0;
    }
    cout << (x % 100 == 0 ?  "Yes" : "No");
    return 0;
}