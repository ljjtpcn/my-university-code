#include<bits/stdc++.h>
using namespace std;

int n, m, idx, cnt;
map<string, int> mp; //建立所有字段的映射 样例1的id name val 分别对应 0, 1, 2
map<int, vector<int>> arr; //存储每一条数据
mp<string, int> res; //存储结果集

//这个功能就是根据正则表达式regex分割字符串input,返回分割后的数组
std::vector<std::string> split(const std::string& input, const std::string& regex){
  std::regex re(regex);
  std::sregex_token_iterator first {input.begin(), input.end(), re, -1}, last;
  return {first, last};
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        mp[s] = idx++; //建立所有字段映射
    }
    //存储每行数据
    int k = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            int x; cin >> x;
            arr[k].push_back(x);    
        }
        k++;
    }
    getchar();
    string input, regex;
    getline(cin, input); //读一行查询语句
    //正则处理
    regex = "( )|,";
    vector<string> q = split(input, regex); 
    //样例1分割后为去q = [SELECT,COUNT(*),FROM,Table,GROUP,BY name,id;]

    //注意到最后一个字段一定有分号,因为正则的时候没有处理掉,处理掉分号
    int len = q.size();
    q[len - 1] = q[len - 1].substr(0, q[len - 1].size() - 1);
    //BY 开始后的字段为所有查询字段,所以先找BY的位置备用
    k = 0;
    while(q[k] != "BY") k++;
    //将需要分组的字段放入group中,这时mp的作用就来了
    vector<int> group;
    for(int i = k+1; i < q.size(); i++) group.push_back(mp[q[i]]);
    sort(group.begin(), group.end());//应该也可以不用sort吧
    
    mp<string, boolean> st;
    //遍历每一组
    for(int i = 0; i < n; i ++ ){
        string s = "";
        for(int j = 0; j < group.size(); j++){
            //就把字段值挨个硬拼成s
            s += to_string(arr[i][group[j]]);
        }
        //先++要输出具体每个组多少个的
        res[s]++;
        //看s有没有出现,出现就是相同
        if(!st[s]){
            cnt++;
            st[s] = true;
        }
    }
    //输出
    cout << cnt << endl;
    for(auto it = res.begin(); it != res.end(); it++){
        cout << it->second << ' ';
    }
}
int main(){
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}