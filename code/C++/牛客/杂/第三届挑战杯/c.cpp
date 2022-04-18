#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void split(const string& s, vector<string>& tokens, const string& delimiters)
{
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));//use emplace_back after C++11
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}

void solve(){
    string str;
    vector<string> tokens;
    cin >> str;
    split(str, tokens, ".");

    if(tokens.size() != 4){
        cout << "NO\n";
        return;
    }

    int flag = true;
    for(auto s : tokens){
        for(auto c : s){
            if(c < '0' || c > '9'){
                cout << "NO\n";
                return;
            }
        }
        int num = stoi(s);
        if(flag){
            flag = false;
            if(num <= 0 || num > 255){
                cout << "NO\n";
                return;
            }
        }else{
            if(num < 0 || num > 255){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    int __ = 1;
    cin >> __;
    while(__--){
        solve();
    }
    return 0;
}