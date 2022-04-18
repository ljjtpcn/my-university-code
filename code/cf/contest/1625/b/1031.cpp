#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int cnt[N];
int l, r, ans;

void init(){
    string s;
    for(int i = 1; i < N; i++){
        s = to_string(i);
        if (s.find("38") != -1 || s.find("4") != -1)
            cnt[i] = cnt[i - 1] + 1;
        else
            cnt[i] = cnt[i - 1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    while(cin >> l >> r, l||r)
        cout << cnt[r] - cnt[l - 1] << endl;
}