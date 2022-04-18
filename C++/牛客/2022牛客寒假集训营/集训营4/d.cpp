#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;

ll mx, my, sx, sy;
void solve(){
    cin >> n;
    cin >> mx >> my >> sx >> sy;
    double ans = sqrt(pow(my - sy, 2) + pow(mx - sx, 2));
    while(n --){
        ll dx, dy;
        cin >> dx >> dy;
        ll X2 = dx + mx, Y2 = dy + my;
        ll X1 = mx, Y1 = my;
        //钝角
        if((X1-X2)*(sx-X2) + (Y1-Y2)*(sy-Y2) <= 0){
            ans = min(ans, sqrt(pow(Y2 - sy, 2) + pow(X2 - sx, 2)));
            continue;
        }
        ll A, B, C;
        A = Y2 - Y1, B = X1 - X2, C = X2 * Y1 - X1 * Y2;
        ans = min(ans, abs(A * sx + B * sy + C) * 1.0 / sqrt(A * A + B * B));
        mx = X2, my = Y2;
    }
    printf("%.8lf", ans);
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}