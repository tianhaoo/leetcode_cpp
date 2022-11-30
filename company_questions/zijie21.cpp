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
#include <sstream>

using namespace std;


void dfs(vector<string> &res, string &path, vector<string> &choices, int cur){
    if(cur >= choices.size()){
        res.push_back(path);
        return;
    }
    for(auto c: choices[cur]){
        path.push_back(c);
        dfs(res, path, choices, cur+1);
        path.pop_back();
    }
}



int main() {

    string input;
    while(getline(cin, input, '\n')){
        string temp;
        vector<string> lst;
        istringstream iss(input);
        while(iss >> temp){
            lst.push_back(temp);
        }

        vector<string> res;
        string path;

        dfs(res, path, lst, 0);

        int count = 0;
        for(auto s: res){
            int sum = 0;
            for(auto c: s){
                sum += (c-'0');
            }
            if(sum % 2 == 0){
                count ++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
