//
// Created by Tiana on 2022/10/15.
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


bool check(vector<int> &lst,  vector<int> &starts, vector<int> &ends){
    sort(lst.begin(), lst.end(), [starts](int a, int b){return starts[a] < starts[b];});
    int pre_start = starts[lst[0]];
    int pre_end = ends[lst[0]];
    for (int i = 1; i < lst.size(); ++i) {
        int start=starts[lst[i]];
        int end = ends[lst[i]];
        if(start <= pre_start){
            return false;
        }
        if(end <= pre_end){
            return false;
        }
        pre_start = start;
        pre_end = end;
    }
    return true;
}

void bt(int n, vector<int> &starts, vector<int> &ends, vector<int> &path, vector<bool> &used, unordered_set<string> &res){
    if(path.size()==3){
        cout << ")))))" << endl;

        cout << check(path, starts, ends) << endl;
        sort(path.begin(), path.end());
        printVector(path);
        cout << ")))))" << endl;

        if(check(path, starts, ends)){

            sort(path.begin(), path.end());
            string key;
            for (int i = 0; i < path.size(); ++i) {
                key.push_back(path[i]+'0');
                printVector(path);
            }
            res.insert(key);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(!used[i]){
            used[i] = true;
            path.push_back(i);
            bt(n, starts, ends, path, used, res);
            used[i] = false;
            path.pop_back();
        }
    }
}





int main() {
    int n;
    while (cin >> n){
        vector<int> starts(n);
        vector<int> ends(n);
        for (int i = 0; i < n; ++i) {
            cin>>starts[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>ends[i];
        }

        vector<int> path;
        unordered_set<string> res;
        vector<bool> used(n, false);
        bt(n, starts, ends, path, used, res);


        for (const auto &item: res) {
            cout << item << endl;
        }


    }

    return 0;
}
