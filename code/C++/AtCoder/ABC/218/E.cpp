#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int p[N];
int n, m;
long long res, sum, fu, futu;

struct node
{
    int a, b, w;
    bool operator<(const node &t) const
    {
        return w < t.w;
    }
} e[N];

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        sum += w;
        if (w < 0)
            fu += w;
        e[i] = {a, b, w};
    }


    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(e, e + m);

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = e[i].a, b = e[i].b, w = e[i].w;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            if (w < 0)
                futu += w;
            res += w;
            cnt++;
        }
        //if(cnt == n-1) break;
    }
    cout << sum - res - (fu - futu);

    return 0;
}