#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define int long long
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e6 + 10;

int n, t;
string str;
vector<PII> arr;

vector<PII> ans;

signed main()
{
    cin >> t;
    while(t --){
        arr.clear();
        ans.clear();

        cin >> n;
        for (int i = 1; i <= n; i ++){
            int x;
            cin >> x;
            arr.push_back({x, i});//123
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        int r = 1, l = -1, sum = 0;
        //0号楼卡死在坐标0
        ans.push_back({0,0});
        //轮流
        int flag = 1;
        for (int i = 0; i < arr.size(); i ++){
            if(flag){
                ans.push_back({arr[i].second, r});
                sum += abs(arr[i].first * 2 * r);
                r++, flag = 0;
            }else{
                ans.push_back({arr[i].second, l});
                sum += abs(arr[i].first * 2 * l);
                l--, flag = 1;
            }
        }
        cout << sum << endl;
        sort(ans.begin(), ans.end());
        for (auto k : ans){
            cout << k.second << ' ';
        }
        cout << endl;
    }

    return 0;
}
