#include <bits/stdc++.h>
// #define endl "\n"
using namespace std;

void solve(){
    double a, b;
    cin >> a >> b;

    double s;
    // int c = 0;
    vector<double> pre;
    while(cin >> s){
        // cout << "Case = " << c ++ << " --- > ";
        int i = s, j = (int)(s + 1);
        if(0 < s && s < 1) cout << 1 << endl;
        else if(s <= i + a) cout << i << endl;
        else if(i + b <= s) cout << j << endl;
        else {
            double t;
            for (int k = pre.size() - 1; k >= 0; k --) {
                if (pre[k] > i + b || pre[k] < i + a) {
                    t = pre[k];
                    break;
                }
            }
            if(t < i + a) cout << i << endl;
            else if(i + b < t) cout << j << endl; 
        }
        pre.push_back(s);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}