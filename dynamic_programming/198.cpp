// 198. 打家劫舍
// 动态规划



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "../utils.h"

using namespace std;

// //  动态规划1
// class Solution {
// public:
//     int dp(unordered_map<int, int> &memo, vector<int> &nums, int start){
//         if(memo.find(start) != memo.end()){
//             return memo[start];
//         }
//         if(start >= nums.size()){
//             return 0;
//         }
//         int res = max(
//                 dp(memo, nums, start+2) + nums[start],
//                 dp(memo, nums, start+1)
//                 );
//         memo[start] = res;
//         return res;
//     }
//
//     int rob(vector<int>& nums) {
//         unordered_map<int, int> memo;
//         return dp(memo, nums, 0);
//     }
// };



// 返回 [0 ... i]的房屋，不触发警报的情况下，的最高金额
int dp(vector<int>& nums, int i, vector<int> &memo){
    if(i==0){
        return nums[0];
    }
    if(i==1){
        return max(nums[0], nums[1]);
    }
    if(memo[i] != INT_MIN){
        return memo[i];
    }
    // 偷nums[i]
    int p1 = nums[i] + dp(nums, i-2, memo);
    // 不偷
    int p2 = dp(nums, i-1, memo);
    int res = max(p1, p2);
    memo[i] = res;
    return res;

}


// 动态规划2
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), INT_MIN);
        return dp(nums, nums.size()-1, memo);
    }
};


int main() {

    // vector<int> nums = {1,2,3,1};
    vector<int> nums = {2,7,9,3,1};
    auto solution = Solution();
    auto res = solution.rob(nums);
    cout << res << endl;

    return 0;
}
