//https : //vjudge.net/problem/HDU-1711

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1e7 + 10;

int t, n, m;
int str[N], p[10005];

void get_Next(int ne[], int p[], int m)
{
    int i = 0, j = -1;
    ne[0] = -1;
    
    while(i < m-1)
    {
        if(j == -1 || p[i] == p[j])
        {
            i++, j++;
            ne[i] = j;
        }else{
            j = ne[j];
        }
    }
}


int KMP(int str[], int p[], int n, int m)
{
    int i = 0, j = 0;
    int ne[10005];
    get_Next(ne, p, m);
    while(i < n && j < m)
    {
        if(j == -1 || str[i] == p[j])
        {
            i++, j++;
        }else{
            j = ne[j];
        }
    }
    if(j >= m)
        return i - m;
    else 
        return -1;
}


int main()
{
    cin >> t;
    while(t --)
    {
        cin >> n >> m;
        
        for (int i = 0; i < n; i++) scanf("%d", &str[i]);
        for (int i = 0; i < m; i++) scanf("%d", &p[i]);

        int ans = KMP(str, p, n, m);
        cout <<  (ans == -1 ? -1 : ans+1) << endl;
    }
    
    return 0;
}