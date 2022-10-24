//
// Created by Tiana on 2022/10/16.
//



#include "../utils.h"


#include <cstdio>
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
#include <list>
#include <climits>
#include <iomanip>
#include <random>

using namespace std;

void dfs(vector<int> &lst, int x, int y, int cur, string &path, vector<string> &res){
    if(cur >= lst.size()){
        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            if(path[i] == 'X'){
                sum += x*lst[i];
            }else{
                sum += y*lst[i];
            }
        }
        if(sum==0){
            res.push_back(path);
        }
        return;
    }

    path.push_back('X');
    dfs(lst, x, y, cur+1, path, res);
    path.pop_back();

    path.push_back('Y');
    dfs(lst, x, y, cur+1, path, res);
    path.pop_back();

}


string check(vector<int> &lst, int x, int y){
    string path;
    vector<string> res;
    dfs(lst, x, y, 0, path, res);
    if(!res.empty()){
        return res[0];
    }else{
        return "false";
    }
}


int main() {
    int n;
    while(cin>> n){
        vector<int> lst(n);
        int sum=0;
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
            sum += lst[i];
        }
        int x, y;
        int mid = sum/2;
        for (int i = mid; i >=0; --i) {
            x = i;
            y = sum-i;

            string res;
            int x1 = x, y1 =y;
            res = check(lst, x1, y1);
            if(res != "false"){
                cout << x1 << ' ' << y1 << endl;
                cout << res << endl;
                break;
            }
            int x2 = -x, y2 =y;
            res = check(lst, x2, y2);
            if(res != "false"){
                cout << x2 << ' ' << y2 << endl;
                cout << res << endl;
                break;
            }
            int x3 = x, y3 =-y;
            res = check(lst, x3, y3);
            if(res != "false"){
                cout << x3 << ' ' << y3 << endl;
                cout << res << endl;
                break;
            }
            int x4 = -x, y4 =-y;
            res = check(lst, x4, y4);
            if(res != "false"){
                cout << x4 << ' ' << y4 << endl;
                cout << res << endl;
                break;
            }



        }

    }

    return 0;
}
