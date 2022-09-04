// 1143. 最长公共子序列
// 动态规划

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include "../utils.h"

using namespace std;


// void backtrack(vector<string> &res, string &path, string &text, int start){
//     if (start >= text.size()){
//         res.push_back(path);
//         return;
//     }
//     for(char choice :  {'*', text[start]}){
//         if(choice != '*')
//             path.push_back(choice);
//         backtrack(res, path, text, start+1);
//         if(choice != '*')
//             path.pop_back();
//     }
// }
//
//
// // 暴力穷举
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         vector<string> res1, res2;
//         string path1, path2;
//         backtrack(res1, path1, text1, 0);
//         backtrack(res2, path2, text2, 0);
//
//         unordered_set<string> s1(res1.begin(), res1.end());
//         unordered_set<string> s2(res2.begin(), res2.end());
//         int m = INT_MIN;
//         for (const auto &item: s1) {
//             if(s2.count(item)){
//                 m = max(m, (int)item.size());
//             }
//         }
//
//         return m==INT_MIN?0:m;
//
//     }
// };

// text1[i ...] 和 text2[j ...]
// 返回最长公共子序列
int dp(string &text1, int i, string &text2, int j, vector<vector<int>> &memo){
    if(i == text1.size() || j == text2.size()){
        return 0;
    }
    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }
    // 两个元素相等
    // 一定都在i.. j..开头的最长公共子序列里面
    if(text1[i] == text2[j]){
        int res = 1 + dp(text1, i+1, text2, j+1, memo);
        memo[i][j] = res;
        return res;
    }
    // 不相等
    // i在，j不在
    int p1 = dp(text1, i, text2, j+1, memo);
    // j在，i不在
    int p2 = dp(text1, i+1, text2, j, memo);
    // i和j都不在
    int p3 = dp(text1, i+1, text2, j+1, memo);
    int res = max(max(p1, p2), p3);
    memo[i][j] = res;
    return res;

}

// 动态规划
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), INT_MIN));
        return dp(text1, 0, text2, 0, memo);
    }
};

int main() {
    string text1;
    string text2;
    default_random_engine e;
    uniform_int_distribution<int> u(0, 25);
    for (int i = 0; i < 1000; ++i) {
        int temp = u(e);
        text1.push_back((char)('a'+temp));
        temp = u(e);
        text2.push_back((char)('a'+temp));
    }
    // string text1 = "abc";
    // string text2 = "def";


    cout << text1 << endl;
    cout << text2 << endl;

    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.longestCommonSubsequence(text1, text2);
    cout << res << endl;



    return 0;
}
