#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<a<<' '<<#b<<" = "<<b<<' '<<#c<<" = "<<c<<' '<<#d<<" = "<<d<<endl;
#define debugx(a, idx) cout << #a << "[" << idx << "] = " << a[idx] << endl;
#define debugarr(a, x) cout<<#a<<": "; for(int i = 0; i < x; i++) cout << a[i] << ' '; cout << endl;
#define debugvec(a) cout<<#a<<": "; for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define cin(a) cin >> a;
#define cin2(a, b) cin >> a >> b;
#define cin3(a, b, c) cin >> a >> b >> c;
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
const int mod = 1000000007;
struct node{int x, y, cnt;};struct cmp{bool operator()(node a, node b){return a.cnt > b.cnt;}};
//快速幂, 逆元 求逆元前提mod质数
ll inv(ll a, ll b) {ll ans = 1;while(b) {if(b & 1) ans = ans * a % mod;a = a * a % mod;b >>= 1LL;}return ans % mod;}
const int N = 30010;

int n, m, t;
map<string, bool> mp;
int ans = 0;
char arr[4] = {'1', '2', '4', '6'};
// bool check(string s){
//     if(s == "1") return true;
//     for (int i = 1; i < s.size(); i ++){
//         int x = (s[i] - '0') + (s[i-1] - '0');
//         if(x != 2 && x != 3 && x != 5 && x != 7 && x != 11 && x != 13 && x != 17)
//             return false;
//     }
//     return true;
// }

void solve(){
    int l, r;
    cin2(l, r);
    string l_str = to_string(l), r_str = to_string(r);
    int st = l_str.size(), ed = r_str.size();
    
    function<void(int, string, bool)> dfs = [&](int now, string num_str, bool st) {
        if(stoll(num_str) > r) return;
        if(!mp[num_str] && st){
            if(stoll(num_str) >= l){
                ans++;
                mp[num_str] = true;
            }

        }
        if(num_str[num_str.size() - 1] == '0'){
            dfs(now + 1, num_str + '2', st);
            dfs(now + 1, num_str + '3', st);
            dfs(now + 1, num_str + '5', st);
            dfs(now + 1, num_str + '7', st);
        }else if(num_str[num_str.size() - 1] == '1'){
            dfs(now + 1, num_str + '1', true);
            dfs(now + 1, num_str + '2', true);
            dfs(now + 1, num_str + '4', true);
            dfs(now + 1, num_str + '6', true);
        }else if(num_str[num_str.size() - 1] == '2'){
            dfs(now + 1, num_str + '0', st);
            dfs(now + 1, num_str + '1', true);
            dfs(now + 1, num_str + '3', st);
            dfs(now + 1, num_str + '5', st);
            dfs(now + 1, num_str + '9', st);
        }else if(num_str[num_str.size() - 1] == '3'){
            dfs(now + 1, num_str + '0', st);
            dfs(now + 1, num_str + '2', st);
            dfs(now + 1, num_str + '4', st);
            dfs(now + 1, num_str + '8', st);
        }else if(num_str[num_str.size() - 1] == '4'){
            dfs(now + 1, num_str + '1', true);
            dfs(now + 1, num_str + '3', st);
            dfs(now + 1, num_str + '7', st);
            dfs(now + 1, num_str + '9', st);
        }else if(num_str[num_str.size() - 1] == '5'){
            dfs(now + 1, num_str + '0', st);
            dfs(now + 1, num_str + '2', st);
            dfs(now + 1, num_str + '6', st);
            dfs(now + 1, num_str + '8', st);
        }else if(num_str[num_str.size() - 1] == '6'){
            dfs(now + 1, num_str + '1', true);
            dfs(now + 1, num_str + '5', st);
            dfs(now + 1, num_str + '7', st);
        }else if(num_str[num_str.size() - 1] == '7'){
            dfs(now + 1, num_str + '0', st);
            dfs(now + 1, num_str + '4', st);
            dfs(now + 1, num_str + '6', st);
        }else if(num_str[num_str.size() - 1] == '8'){
            dfs(now + 1, num_str + '3', st);
            dfs(now + 1, num_str + '5', st);
            dfs(now + 1, num_str + '9', st);
        }else if(num_str[num_str.size() - 1] == '9'){
            dfs(now + 1, num_str + '2', st);
            dfs(now + 1, num_str + '4', st);
            dfs(now + 1, num_str + '8', st);
        }
    };
    for (int j = 1; j <= 9; j++){
        string s = "";
        s.push_back(char('0' + j));
        j == 1 ? dfs(1, s, true) : dfs(1, s, false);
    }    
    
    cout << ans;
}

int main(){
    IOS;
    int __ = 1;
    while(__--){
        solve();
    }
    return 0;
}