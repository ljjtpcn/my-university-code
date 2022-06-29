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
int a[N];
vector<pair<int, char> > arr;

bool cmp(pair<int, char> a, pair<int, char> b)
{
    if (a.second == 'B' && b.second == 'B')
        return a.first < b.first;
    if (a.second == 'B' || b.second == 'B')
        return a.second == 'B';
    if (a.second != 'B' && b.second != 'B')
        return a.first < b.first;
}

int main()
{

    cin >> t;
    while (t--){
        
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> str;
        arr.clear();
        for (int i = 0; i < str.size(); i++)
            arr.push_back(make_pair(a[i], str[i]));
        sort(arr.begin(), arr.end(), cmp)
        ;
        
        int flag = 0;
        for (int i = 0; i < n; i++){
            if (arr[i].first == i+1)
                continue;
            else {
                if (arr[i].first != i+1){
                    if ((arr[i].first < i+1 && arr[i].second == 'B') || (arr[i].first > i+1 && arr[i].second == 'R')){
                        flag = 1;
                        cout << "NO\n";
                        break;
                    }
                }
            }
        }

        if (!flag)
            cout << "YES\n";
    }
    
    return 0;
}
