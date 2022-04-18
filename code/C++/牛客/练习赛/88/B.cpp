// https : //ac.nowcoder.com/acm/contest/11178/B

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
typedef unsigned long long ull;
const int N = 5e5;

ull p[N], hm[N], hc[N];
int T, len;
char M[N], C[N];
ull base = 131;

ull get(ull* h, int l, int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}

int main()
{
    cin >> T;

    p[0] = 1;
    for(int i = 1; i < N; i ++ ) p[i] = p[i-1] * base;

    while (T--)
    {
        scanf("%s%s%d", M+1, C+1, &len);
        if (strlen(M+1) != strlen(C+1))
        {
            puts("NO");
            continue;
        }

        int n = strlen(M+1);
        for (int i = 1; i <= n; i++)
            hm[i] = hm[i - 1] * base + M[i],
            hc[i] = hc[i - 1] * base + C[i];
        ull end = get(hc, n - len + 1, n);

        int flag = 0;
        for(int i = 1; i+len-1 <= n; i ++)
            if(get(hm, 1,  i-1) == get(hc, 1, i-1) and get(hm, i, i+len-1) == end and get(hm, i+len, n) == get(hc, i, n-len)){
                flag = 1;
                break;
            }
        puts(flag ? "YES" : "NO");


    }
    return 0;
}