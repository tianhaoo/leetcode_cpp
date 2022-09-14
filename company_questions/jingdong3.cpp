//



#include "../utils.h"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <random>

using namespace std;


// 字符串分割
void dfs(string &s, int i, vector<string> &path, vector<vector<string>> &res){
    if (i == s.size()){
        res.push_back(path);
        return;
    }
    // 分割一个
    path.push_back(s.substr(i, 1));
    dfs(s, i+1, path, res);
    path.pop_back();

    // 分割两个
    if(i < s.size()-1){
        path.push_back(s.substr(i, 2));
        dfs(s, i+2, path, res);
        path.pop_back();
    }
}


bool isOk(long long k, string s){
    vector<string> path;
    vector<vector<string>> results;
    dfs(s, 0, path, results);
    if(results.size() == k){
        return true;
    }
    return false;
}


// 从26个里面选k个
void dfs2(long long k, string &path, vector<string> &res, bool &ok){
    if(ok) return;
    if(path.size() >= k){
        res.push_back(path);
        if(isOk(k, path)){
            cout << path << endl;
            ok = true;
        }
        return;
    }
    for (int i = 1; i <= 26; ++i) {
        path += to_string(i);
        dfs2(k, path, res, ok);
        path.pop_back();
        if(i >= 10){
            path.pop_back();
        }
    }
}


int main() {

    long long k;
    while (cin >> k){
        string res;
        // 从26个里面选3个
        string p;
        vector<string> candidates;
        bool ok = false;
        dfs2(k, p, candidates, ok);

        if(!ok) cout << -1 << endl;
    }

    return 0;
}
