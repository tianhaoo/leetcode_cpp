// 494. 目标和
// 动态规划 回溯


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
#include <random>
#include "../utils.h"

using namespace std;


// void backtrack(vector<int>& nums, int &count, int pathSum, int target, int start){
//     cout << start << ", " << pathSum << endl;
//     if(start == nums.size() && pathSum == target){
//         count ++;
//         return;
//     }
//     if(start >= nums.size()){
//         return;
//     }
//     for(auto choice : {1, -1}){
//         pathSum += (nums[start] * choice);
//         backtrack(nums, count, pathSum, target, start+1);
//         pathSum -= (nums[start] * choice);
//     }
// }
//
// // 回溯
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int count=0;
//         backtrack(nums, count, 0, target, 0);
//         return count;
//     }
// };

DECLARE_PRINT


// 选[0, ...i]的数，运算结果等于j的不同表达式数目，返回
int dp(vector<int>& nums, int i, int j, unordered_map<string, int> &memo){
    PRINT_PARAM(i, j)
    if(i < 0){
        return 0;
    }
    if(i == 0){
        int res=0;
        if(j == nums[0]){
            res += 1;
        }
        if(j == -nums[0]){
            res += 1;
        }
        PRINT_RES(res)
        return res;
    }
    string key = "";
    key += to_string(i);
    key.push_back(',');
    key += to_string(j);
    if (memo.count(key)){
        return memo[key];
    }

    // 选择加上nums[i]
    int p1 = dp(nums, i-1, j-nums[i], memo);
    // 选择减掉nums[i]
    int p2 = dp(nums, i-1, j+nums[i], memo);

    int res = p1 + p2;
    memo[key] = res;
    PRINT_RES(res)
    return res;

}

// 动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        int res = dp(nums, nums.size()-1, target, memo);
        return res;

    }
};

int main() {
    vector<int> nums = {0,1};
    int target = 1;
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.findTargetSumWays(nums, target);
    cout << res << endl;

    return 0;
}
