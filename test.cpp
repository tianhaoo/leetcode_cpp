#include"utils.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

// 分割字符串
// path 字符串数组
// res 二维字符串数组
void dfs(vector<vector<string>> &res, vector<string> &path, string &s, int start){
    if(start >= s.size()){
        res.push_back(path);
        return;
    }
    for(int i : {1, 2}){
        if(i == 1){
            path.emplace_back(1, s[start]);
            dfs(res, path, s, start+1);
            path.pop_back();
        }
        if(i==2 && start <= s.size()-2){
            path.push_back(s.substr(start, 2));
            dfs(res, path, s, start+2);
            path.pop_back();
        }
    }



}


int main(){

    string s = "1234";
    vector<vector<string>> res;
    vector<string> path;
    dfs(res, path, s, 0);
    printMatrix<string>(res);




    return 0;
}