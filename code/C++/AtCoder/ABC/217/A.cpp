//https://atcoder.jp/contests/abc217/tasks/abc217_a

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

string s, t;

int main()
{
    cin >> s >> t;

    for (int i = 0; i < s.size() && i < t.size(); i++)
    {
        /* code */
        if(s[i] < t[i]){
            cout << "Yes";
            return 0;
        }
        if(s[i] > t[i]){
            cout << "No";
            return 0;
        }
        
    }
    if(s.size() < t.size()) cout << "Yes";
    else cout << "No";

    return 0;
}