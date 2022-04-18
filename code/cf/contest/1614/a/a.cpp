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

int t, l, r, k, n;
string str;
vector<int> arr;

int main()
{
    cin >> t;
    while(t --){
        arr.clear();
        int ans = 99999999;
        cin >> n >> l >> r >> k;
        for (int i = 0; i < n; i ++)
        {
            int x;
            cin >> x;
            if(x >= l && x <= r)
                arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = 0; i < arr.size(); i ++){
            if(k >= arr[i]){
                cnt++;
                k -= arr[i];
            }else{
                break;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
