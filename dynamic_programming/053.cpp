// 53. 最大子数组和
// 动态规划
// 前缀和



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <random>
#include "../utils.h"

using namespace std;

// // 暴力穷举法
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int m = INT_MIN;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i; j < nums.size(); ++j) {
//                 int sum=0;
//                 for (int k = i; k <= j; ++k) {
//                     sum += nums[k];
//                 }
//                 m = max(m, sum);
//             }
//         }
//         return m;
//     }
// };


// // 返回以nums[i]结尾的子数组最大和
// int dp(vector<int> &nums, int i, vector<int> &memo){
//     if(i==0){
//         return nums[0];
//     }
//     if(memo[i] != INT_MIN){
//         return memo[i];
//     }
//     // 拼在前面一个元素后面
//     int p1 = dp(nums, i-1, memo) + nums[i];
//     // 自己成为一个子数组
//     int p2 = nums[i];
//     int res = max(p1, p2);
//     memo[i] = res;
//     return res;
// }
//
// // 动态规划
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         vector<int> memo(nums.size(), INT_MIN);
//         int m=INT_MIN;
//         for (int i = 0; i < nums.size(); ++i) {
//             int res = dp(nums, i, memo);
//             m = max(m, res);
//         }
//         return m;
//
//     }
// };


// 前缀和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            preSum[i] = preSum[i-1] + nums[i];
        }
        int m = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                // nums[i ... j]求和
                int sum;
                if(i==0){
                    sum = preSum[j];
                }else{
                    sum = preSum[j] - preSum[i-1];
                }
                m = max(m, sum);
            }
        }
        return m;
    }
};


int main() {
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {5,4,-1,7,8};
    // vector<int> nums = {1};
    // vector<int> nums;
    // default_random_engine e;
    // uniform_int_distribution<int> u(-10000, 10000);
    // for (int i = 0; i < 100; ++i) {
    //     nums.push_back(u(e));
    // }
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.maxSubArray(nums);
    cout << res << endl;

    return 0;
}
