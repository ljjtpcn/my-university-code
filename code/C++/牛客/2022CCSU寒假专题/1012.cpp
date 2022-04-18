#include"bits/stdc++.h"
using namespace std;

int q;
stack<string> pre;
int main(){
    ios::sync_with_stdio(false);

while(cin >> q){
    pre.push("");
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string s;
            cin >> s;
            pre.push(pre.top() + s);
        }
        else if (op == 2)
        {
            int k;
            cin >> k;
            pre.push(pre.top().substr(0, pre.top().length() - k));
        }
        else if (op == 3)
        {
            int k;
            cin >> k;
            cout << pre.top()[k - 1] << endl;
        }
        else if (op == 4)
        {
            pre.pop();
        }
    }
}
    
    return 0;
}