#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
long long n, q, k, op, t;
string s;
unordered_map<char, int> mp;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q >> s;
    k = 1;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }
    while(q --){
        cin >> op;
        if(op == 1){
            cin >> t;
            k = ((k % mod) * ((t + 1) % mod)) % mod;
        }else if(op ==2){
            char c; cin >> c;
            cout << mp[c] * k % mod << endl;
        }
    }
    return 0;
}
