#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e6 + 10;

int n, m, t;
string s;
int arr[N], vis[N];
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char a , b, c;
    cin >> a >> b >> c;
    string abc({a, b, c});
    string bca({b, c, a});
    string cab({c, a, b});
    cout << stoi(abc) + stoi(bca) + stoi(cab);
    return 0;
}
