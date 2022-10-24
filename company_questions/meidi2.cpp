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


int main() {
    string s;
    while(cin >> s){

        vector<bool> del(s.size(), false);
        for (int i = 0; i < s.size()-1; ++i) {
            int left = i;
            int right = i+1;
            while(s[left] == s[right]){
                del[left] = true;
                del[right] = true;
                left--;
                right++;
            }
        }
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if(!del[i]){
                res.push_back(s[i]);
            }
        }
        cout << res << endl;
    }

    return 0;
}
