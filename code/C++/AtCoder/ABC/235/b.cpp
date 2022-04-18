#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int arr[N], dp[N];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }
    int maxx = arr[1];
    for(int i = 1; i < n; i ++){
        if(arr[i + 1] > arr[i]){
            maxx = arr[i + 1];
        }else{
            break;
        }
    }
    cout << maxx << endl;
}