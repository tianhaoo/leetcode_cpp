//
// Created by Tiana on 2022/10/9.
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


int sum(vector<int> &set, vector<int> &lst){
    int s=0;
    for (int i : set) {
        s+=lst[i];
    }
    return s;
}

string convert(vector<int> lst){
    sort(lst.begin(), lst.end());
    string res;
    for (int i : lst) {
        res.push_back(i+'0');
    }
    return res;
}

void dfs(vector<int> &lst, vector<int> &rLst, vector<int> &bLst, vector<int> &rSet, vector<int> &bSet, int rp, int bp, unordered_set<string> &s){

    if(!rSet.empty() && !bSet.empty() && sum(rSet, lst) == sum(bSet, lst)){
        string key = convert(rSet) + "," + convert(bSet);
        s.insert(key);
        return;
    }

    if(rp<rLst.size()){
        rSet.push_back(rLst[rp]);
        dfs(lst, rLst, bLst, rSet, bSet, rp+1, bp, s);
        rSet.pop_back();
    }

    if(rp<rLst.size()){
        dfs(lst, rLst, bLst, rSet, bSet, rp+1, bp, s);
    }

    if(bp<bLst.size()){
        bSet.push_back(bLst[bp]);
        dfs(lst, rLst, bLst, rSet, bSet, rp, bp+1, s);
        bSet.pop_back();
    }

    if(bp<bLst.size()){
        dfs(lst, rLst, bLst, rSet, bSet, rp, bp+1, s);
    }




}


int main() {
    int n;
    while(cin >> n){
        vector<int> lst(n);
        for (int i = 0; i < n; ++i) {
            cin >> lst[i];
        }
        string str;
        cin >> str;

        vector<int> rLst, bLst;
        for (int i = 0; i < str.size(); ++i) {
            if(str[i] == 'R'){
                rLst.push_back(i);
            }else{
                bLst.push_back(i);
            }
        }


        unordered_set<string> s;
        vector<int> rSet, bSet;
        dfs(lst, rLst, bLst, rSet, bSet, 0, 0, s);
        cout << s.size() << endl;



    }

    return 0;
}
