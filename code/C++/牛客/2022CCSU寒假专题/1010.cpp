#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
    while(cin >> s){
        while(s.find("oo") != s.npos || s.find("OO") != s.npos){
            int i, j;
            i = j = -1;
            if(s.find("oo") != s.npos) i = s.find("oo");
            if(s.find("OO") != s.npos) j = s.find("OO");

            if(i == -1){
                s = s.replace(s.find("OO"), 2, "");
            }else if(j == -1){
                s = s.replace(s.find("oo"), 2, "O");
            }else if(i < j){
                s = s.replace(s.find("oo"), 2, "O");
            }else{
                s = s.replace(s.find("OO"), 2, "");
            }
        }
        cout << s << endl;
    }
    return 0;
}