#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e6 + 10;

int n, m, t;
string s;
int arr[1010], ans[1010];
vector<int> v;

bool check(int x){
    int cnt = 0;
    for (int i = 1; i <= x; i++){
        if(x % i == 0){
            arr[++cnt] = i;
        }
    }
    if(arr[cnt] % arr[(cnt+1)/2] == 0)
        return true;
    return false;
}
void init(){
    for (int i = 1; i <= 1000; i ++){
        if(check(i))
            ans[i] = ans[i-1] + 1;
        else{
            ans[i] = ans[i - 1];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}
