#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int n, vis[N];
stack<int> st;
vector<int> arr;

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int idx = n;
    for(int i = 0; i < n; i++){
        vis[arr[i]] = 1;
        st.push(arr[i]);
        while(idx && vis[idx]) idx--;
        while(st.size() && st.top() >= idx){
            if (st.top() != n)
                cout << ' ';
            cout << st.top();
            st.pop();
        } 
    }
    while(st.size()){
        cout << ' ' << st.top();
        st.pop();
    }

    return 0;
}