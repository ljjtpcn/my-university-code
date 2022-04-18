// https : //ac.nowcoder.com/acm/contest/11178/A

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
const int N = 5e6 + 10;

int V, I, maxn, T;
int a[N];

int main()
{
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &V, &I, &maxn);

        if(V+I <= maxn)
        {
            for (int i = 0; i < V; i++)
            {
                /* code */
                printf("%c", '5');
            }
            for (int i = 0; i < I; i++)
            {
                /* code */
                printf("%c", '1');
            }
            puts("");
            continue;

        }else{
            int x = V + I - maxn;
            for (int i = 0; i < maxn; i++)
            {
                if(V)
                {
                    V--;
                    int cnt = 5;
                    while(x && I)
                    {
                        cnt ++;
                        x--, I --;
                        if(cnt == 8) break;
                    }
                    printf("%d", cnt);

                }else if(I){
                    I--;
                    int cnt = 1;
                    while(x && I)
                    {
                        cnt ++;
                        x --, I --;
                        if(cnt == 3) break;

                    }
                    printf("%d", cnt);
                    
                }
            }
            puts("");
        }

    }

    return 0;
}