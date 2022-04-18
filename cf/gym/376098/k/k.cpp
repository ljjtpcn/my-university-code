#include <bits/stdc++.h>
using namespace std;
struct oput {
    string fname, lname, email;
    string FNAME, LNAME, EMAIL;
    bool match;
    bool operator < (const oput& o) {
        return email < o.email;
    }
};
void toLowcase(string& s) {
    for (int i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
}
vector<oput> I, O;
int main()
{
    string s;
    int cnt = 0;
    while (getline(cin, s)) {
        stringstream ss; ss << s;
        if (s == "") {
            cnt++;
            continue;
        }
        string lName, fName, Email;
        ss >> lName >> fName >> Email;
        oput tmp;
        tmp.EMAIL = Email, tmp.FNAME = fName, tmp.LNAME = lName;
        toLowcase(lName), toLowcase(fName), toLowcase(Email);
        tmp.email = Email, tmp.fname = fName, tmp.lname = lName;
        tmp.match = 0;
        if (!cnt) I.push_back(tmp);
        else O.push_back(tmp);
    }
    for (int i = 0; i < I.size(); ++i) {
        for (int j = 0; j < O.size(); ++j) {
            if (I[i].fname == O[j].fname && I[i].lname == O[j].lname)
                I[i].match = O[j].match = 1;
            if (I[i].email == O[j].email)
                I[i].match = O[j].match = 1;
        }
    }
    vector<oput> ans1,ans2;
    for (int i = 0; i < I.size(); ++i) {
        if (!I[i].match) ans1.push_back(I[i]);
    }
    for (int i = 0; i < O.size(); ++i) {
        if (!O[i].match) ans2.push_back(O[i]);
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    for (int i = 0; i < ans1.size(); ++i) {
        cout << "I " << ans1[i].EMAIL << " " <<  ans1[i].FNAME << " " << ans1[i].LNAME << endl;
    }
    for (int i = 0; i < ans2.size(); ++i) {
        cout << "O " << ans2[i].EMAIL << " " << ans2[i].FNAME << " " << ans2[i].LNAME << endl;
    }
    if (ans1.size() == ans2.size() && ans1.size() == 0) {
        cout << "No mismatches." << endl;
    }
    return 0;
}