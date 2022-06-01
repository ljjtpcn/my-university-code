// Problem: M. Master of Shuangpin
// Contest: Codeforces - The 15th Chinese Northeast Collegiate Programming
// Contest URL: https://codeforces.com/gym/103145/problem/M Memory Limit: 256 MB
// Time Limit: 1000 ms
#include <bits/stdc++.h>
#define Please return
#define AC 0
#define pb push_back
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
using i64 = long long;
// clang-format off
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int P = 998244353;
int norm(int x) {if (x < 0) { x += P; }if (x >= P) { x -= P; }return x;}inline void read(int &num) {int s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}inline void read(ll &num) {ll s = 0;char ch = getchar();while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9')s = (s << 3) + (s << 1) + ch - '0', ch = getchar();num = s;}template <class T>T power(T a, i64 b) {T res = 1;for (; b; b /= 2, a *= a) {if (b % 2) { res *= a; }}return res;}
struct Z {int x;Z(int x = 0) : x(norm(x)) {}Z(i64 x) : x(norm(x % P)) {}int val() const { return x; }Z operator-() const { return Z(norm(P - x)); }Z inv() const {assert(x != 0);return power(*this, P - 2);}Z &operator*=(const Z &rhs) {x = i64(x) * rhs.x % P;return *this;}Z &operator+=(const Z &rhs) {x = norm(x + rhs.x);return *this;}Z &operator-=(const Z &rhs) {x = norm(x - rhs.x);return *this;}Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }friend Z operator*(const Z &lhs, const Z &rhs) {Z res = lhs;res *= rhs;return res;}friend Z operator+(const Z &lhs, const Z &rhs) {Z res = lhs;res += rhs;return res;}friend Z operator-(const Z &lhs, const Z &rhs) {Z res = lhs;res -= rhs;return res;}friend Z operator/(const Z &lhs, const Z &rhs) {Z res = lhs;res /= rhs;return res;}friend std::istream &operator>>(std::istream &is, Z &a) {i64 v;is >> v;a=Z(v);return is;}};
ll ksm(ll a, ll b){ll res = 1;while(b){if(b & 1)res *= a;a *=a;b >>= 1;}return res;}ll ksm(ll a, ll b, int mod){ll res = 1;while(b){if(b & 1)res = res * a % mod;a = a * a % mod;b >>= 1;}return res;}
// clang-format on
const int N = 2e5 + 10;

map<string, vector<string>> mp;
map<char, vector<string>> val;
void solve() {
    val['q'] = {"q", "iu"}, val['w'] = {"w", "ei"}, val['e'] = {"e"},
    val['r'] = {"r", "uan"}, val['t'] = {"t", "ue"}, val['y'] = {"y", "un"},
    val['u'] = {"u", "sh"}, val['i'] = {"i", "ch"}, val['o'] = {"o", "uo"},
    val['p'] = {"p", "ie"}, val['a'] = {"a"}, val['s'] = {"s", "ong", "iong"},
    val['d'] = {"d", "ai"}, val['f'] = {"f", "en"}, val['g'] = {"g", "eng"},
    val['h'] = {"h", "ang"}, val['j'] = {"j", "an"},
    val['k'] = {"k", "uai", "ing"}, val['l'] = {"l", "uang", "iang"},
    val['z'] = {"z", "ou"}, val['x'] = {"x", "ia", "ua"},
    val['c'] = {"c", "ao"}, val['v'] = {"v", "zh", "ui"},
    val['b'] = {"b", "in"}, val['n'] = {"n", "iao"}, val['m'] = {"m", "ian"};

    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            string t = "";
            t += i, t += j;
            for (auto s1 : val[i]) {
                for (auto s2 : val[j]) { mp[t].pb(s1 + s2); }
            }
        }
    }
    string s;
    while (getline(cin, s)) {
        stringstream ss;
        ss << s;

        while (ss >> s) {
            if (s == "ang")
                cout << "ah ";
            else if (s == "eng")
                cout << "eg ";
            else if (s.size() == 1)
                cout << s << s << ' ';
            else if (s.size() == 2)
                cout << s << ' ';
            else {
                bool flag = false;
                for (char i = 'a'; i <= 'z' && !flag; i++) {
                    for (char j = 'a'; j <= 'z' && !flag; j++) {
                        string t = "";
                        t += i, t += j;
                        for (auto v : mp[t]) {
                            if (v == s) {
                                cout << t << ' ';
                                flag = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int __ = 1;
    // scanf("%d", &__);
    while (__--) { solve(); }
    Please AC;
}
