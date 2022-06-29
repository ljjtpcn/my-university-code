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
const int N = 1e6 + 10;

int n, cnt, t;
string str;
vector<int> v, a , b;

int main()
{
    cin >> t;
    while (t --)
    {
        /* code */
        v.clear();
        a.clear();
        b.clear();
        int sum = 0;
        cin >> n >> cnt;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            v.push_back(x);
            sum += x;
        }
        
        if(cnt == 0){
            cout << sum << endl;
            continue;
        }

        sort(v.begin(), v.end());

        if (cnt < n / 2){
            for (int i = 0; i < cnt; i++)
            {
                int len = v.size();
                sum -= v[len - 1];
                sum -= v[len - 2];
                sum += v[len - 1] / v[len - 2];
                v.pop_back();
                v.pop_back();
            }
            cout << sum << endl;
            continue;
        }


        for(int i = 0; i < n; i++){
            if(i < n / 2) a.push_back(v[i]);
            else b.push_back(v[i]);
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        int len_a = a.size(), len_b = b.size();     
        for (int i = 0; i < cnt; i++){
            sum -= a[i];
            sum -= b[i];
            sum += a[i] / b[i];
        }
        cout << sum << endl;
    }
    
    
    return 0;
}
