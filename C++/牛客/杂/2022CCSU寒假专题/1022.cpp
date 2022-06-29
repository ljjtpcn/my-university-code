#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e4 + 10;

int n;
ll ans;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pii> arr(n+1);
    for(int i = 0; i <= n; i++){
        int l, r; cin >> l >> r;
        arr[i] = {l, r};
    }
    sort(arr.begin(), arr.end(), [](pii l, pii r){ return (l.first / r.second) < (r.first / l.second);});

    ll base = arr[0].first;
    for(int i = 1; i <= n; i++){
        ans = max(ans, base / arr[i].second);
        base *= arr[i].first;
    }
    cout << ans;
    return 0;
}
