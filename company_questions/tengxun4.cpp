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
#include <bitset>

using namespace std;

void add(string &s){
    string temp;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '1'){
            temp.push_back('0');
        }else{
            temp.push_back('1');
        }
    }
    s += temp;
}


int main() {
    int L, R;
    while(cin >> L >> R){
        string s = "1";
        while(s.size() < R){
            add(s);
        }
        int count = 0;
        for (int i = L-1; i < R; ++i) {
            if(s[i] == '1'){
                count ++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
