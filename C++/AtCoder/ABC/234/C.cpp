#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> arr;

int find(int x){
    int l = 0, r = k - 1;
    while(l <= r){
        int mid = l + r >> 1;
        if(arr[mid] > x){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
        if(arr[mid] == x){
            return mid;
        }
    }
    return l;
}
int main()
{

    cin >> n >> k;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if(i < k) arr.push_back(x);
        else{
            if(x > arr[k-1]){

                int idx = find(x);
                arr.insert(arr.begin() + idx, x);
            }
        }
        if (arr.size() == k)
            sort(arr.begin(), arr.end(), greater<int>());

        if (i >= k - 1)
            cout
                << arr[k - 1] << endl;
    }
    return 0;
}

