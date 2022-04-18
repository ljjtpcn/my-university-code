#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 100 + 10;

int qmi(int m, int k)
{
    int res = 1, t = m;
    while (k)
    {
        if (k&1) res = res * t;
        t = t * t;
        k >>= 1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    map<int, int> cnt[N];
    for(int i = 1; i <= n; i ++){
        int t = i;
        for(int j = 2; j <= t; j ++){
            if(t % j == 0){
                while(t % j == 0) cnt[i][j]++, t /= j;
            }
        }
        if(t != 1) cnt[i][t] ++;
    }

    auto mul = [&](vector<int> &A, int b){
        // C = A * b, A >= 0, b >= 0
        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size() || t; i ++ ){
            if (i < A.size()) t += A[i] * b;
            C.push_back(t % 10);
            t /= 10;
        }
        while (C.size() > 1 && C.back() == 0) C.pop_back();

        return C;
    };
    
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i <= n; i ++){
        int k = 0;
        for(int j = 2; j <= n; j ++) k = max(cnt[j][i], k);
        ans = mul(ans, qmi(i, k));
    }
    for(int i = ans.size() - 1; i >= 0; i --) cout << ans[i];
}

int main(){
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}