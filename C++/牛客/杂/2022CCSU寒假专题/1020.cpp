#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 25;

int n;
string s[N];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, [](string s1, string s2)
         { return s1 + s2 > s2 + s1; });
    for(int i = 0; i < n; i++)
        cout << s[i];
    return 0;
}
