#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
double maxx;
vector<pair<int, int>> v;
double f(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(b.second - a.second, 2) + pow(b.first - a.first, 2));
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(i != j){
                maxx = max(maxx, f(v[i], v[j]));
            }
        }
    }
    printf("%.8lf", maxx);
    return 0;
}