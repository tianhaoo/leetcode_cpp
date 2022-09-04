//
// Created by Tiana on 2022/9/4.
//




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <random>
#include "../utils.h"

using namespace std;

// 从center出发向左右寻找最长回子串
// 从l和r出发
string find(string &s, int l, int r){
    while(l>=0 && r<=s.size()-1){
        if(s[l] != s[r]){
            return s.substr(l+1, r-l-1);
        }
        l --;
        r ++;
    }
    return s.substr(l+1, r-l-1);
}


class Solution {
public:
    string longestPalindrome(string s) {
        string m = "";

        for (int i = 0; i < s.size(); ++i) {
            string temp;
            temp = find(s, i, i);
            if(temp.size() > m.size()){
                m = temp;
            }
            if(i+1<s.size()){
                temp = find(s, i, i+1);
                if(temp.size() > m.size()){
                    m = temp;
                }
            }
        }
        return m;
    }
};



int main() {
    string s = "babad";
    auto solution = Solution();
    auto res = solution.longestPalindrome(s);
    cout << res << endl;

    return 0;
}
