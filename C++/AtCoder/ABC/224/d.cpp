//https://codeforces.ml/contest/1562/problem/A

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e5;

int n, m, t;
int h[N], e[N], ne[N], w[N], idx;

string S = " ";

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}


int main()
{
    cin >> m;
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    
    for (int i = 1; i <= 8; i ++){
        string c;
        cin >> c;
        S += c;
    }
        return 0;
}