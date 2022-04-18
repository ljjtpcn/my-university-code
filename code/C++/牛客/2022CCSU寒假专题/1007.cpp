#include<bits/stdc++.h>
using namespace std;

int n, k, cnt;
int arr[10] = {1};

void dfs(int idx, int s){
    if(idx == k){
        if(s >= arr[idx-1]) cnt ++;
        return;
    }

    for (int i = arr[idx - 1]; i < s; i ++){
        arr[idx] = i;
        dfs(idx + 1, s - i);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    dfs(1, n);
    cout << cnt;
}