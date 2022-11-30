//
// Created by Tiana on 2022/11/8.
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


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */

    bool dp(string s, string p){
        int len1 = s.size();
        int len2 = p.size();
        bool dp[len1 + 1][len2 + 1];
        for(int i=0; i < len1; i++){
            for(int j=0; j< len2; j++){
                dp[i][j] = false;
            }
        }

        s = " " + s;
        p = " " + p;
        dp[0][0] = true;
        for(int i=0; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(i > 0 && p[j] == '.' || p[j] == s[i]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-1];
                }else if(p[j] == '*'){
                    if(j > 1){
                        dp[i][j] = dp[i][j] || dp[i][j-2];
                    }
                    if(i > 0 && p[j-1] == '.' || s[i] == p[j-1]){
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }

                }
            }
        }
        return dp[len1][len2];

    }

    bool match(string str, string pattern) {
        // write code here
        if(str.size() == 0 && pattern.size() == 0){
            return true;
        }else if(pattern.size() == 0){
            return false;
        }else if(str == pattern){
            return true;
        }else if(pattern == "."){
            return true;
        }else{
            return dp(str, pattern);
        }
    }
};


int main() {
    auto solution = Solution();
    string s = "a";
    string p = "ab*a";
    bool res = solution.match(s, p);



    return 0;
}
