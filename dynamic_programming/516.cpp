// 516. 最长回文子序列
// 动态规划




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


// 返回s[i ... j] 之间最长回文子序列的长度
int dp(string &s, int l, int r, vector<vector<int>> &memo){
    // 指在同一个元素上
    if(l==r){
        return 1;
    }
    // 指在相邻元素上
    if(l+1 == r){
        if(s[l] == s[r]){
            return 2;
        }else{
            return 1;
        }
    }
    if(memo[l][r] != INT_MIN){
        return memo[l][r];
    }
    // 相隔大于等于1个元素
    if(s[l] == s[r]){
        return 2 + dp(s, l+1, r-1, memo);
    }
    // 两个元素不相等的情况
    // 把左边的元素加进去
    int p1 = dp(s, l, r-1, memo);
    // 把右边的元素加进去
    int p2 = dp(s, l+1, r, memo);
    int res = max(p1, p2);
    memo[l][r] = res;
    return res;
}


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), INT_MIN));
        return dp(s, 0, s.size()-1, memo);
    }
};


int main() {
    string s = "abcdef";
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.longestPalindromeSubseq(s);
    cout << res << endl;

    return 0;
}
