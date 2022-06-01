#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 5010, mod = 998244353;
char s[20];
bool v[20];

ll qmi(ll a, int b) {
    ll t = 1;
    while (b) {
        if (b & 1) t = t * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return t;
}

int main() {
    int n;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        cnt += (s[i] != 'x');
        if (s[i] == 'o') v[i] = true;
    }
    ll ans = qmi(cnt, n);
    for (int i = 1; i < (1 << 10); i++) {
        
        bool flag = false;
        for (int j = 0; j < 10; j++) {
            if ((i >> j & 1) && !v[j]) flag = true;
        }
        if (flag) continue;
        
        int num = __builtin_popcount(i);
        if (num & 1)
            ans = (ans - qmi(cnt - num, n) + mod) % mod;
        else
            ans = (ans + qmi(cnt - num, n)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}