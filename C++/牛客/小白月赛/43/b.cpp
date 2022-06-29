#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e6 + 10;

ll n, m, t;
string s;
ll arr[N];
vector<ll> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t --){
        ll a, b, target;
        cin >> a >> b >> target;
        if(target == a || target == b) {
            cout << 0 << endl;
            continue;
        }else if(target % 2){
            cout << -1 << endl;
            continue;
        }else if(target < (a+b)){
            cout << 1 << endl;
            continue;
        }else {
            ll cnt = 0;
            a = a + b;
            while(a < target){
                cnt++;
                a *= 2;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
