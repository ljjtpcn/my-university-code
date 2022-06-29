#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, t;
int main()
{
    cin >> t;
    while( t --){
        cin >> n >> m;
        cout << min((n + m) / 4, min(n, m)) << endl;
    }
    return 0;
}