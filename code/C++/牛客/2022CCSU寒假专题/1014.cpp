#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int t, n;
vector<int> arr;

int main()
{
    cin >> t;
    while(t --){
        arr.clear();
        cin >> n;
        for (int i = 0; i < n; i ++){
            int x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        vector<int>::iterator new_end = unique(arr.begin(), arr.end());
        arr.erase(new_end, arr.end());
        cout << arr.size() << endl;
    }
    return 0;
}