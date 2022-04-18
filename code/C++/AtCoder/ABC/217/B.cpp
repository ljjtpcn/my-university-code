//https://atcoder.jp/contests/abc217/tasks/abc217_b
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

string s1, s2, s3;
map<string, int> mp = { 
        {"ABC", 0}, {"AHC", 0}, {"ARC", 0}, {"AGC", 0} 
    };

int main()
{
    cin >> s1 >> s2 >> s3;
    mp[s1] ++;
    mp[s2] ++;
    mp[s3] ++;
    
    for (auto it = mp.begin(); it != mp.end(); it ++)
    {
        /* code */
        if(it->second == 0)
            cout << it->first;

    }
    
    return 0;
}