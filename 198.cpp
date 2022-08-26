// 198. 打家劫舍
// 动态规划



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "utils.h"

using namespace std;


class Solution {
public:
    int dp(unordered_map<int, int> &memo, vector<int> &nums, int start){
        if(memo.find(start) != memo.end()){
            return memo[start];
        }
        if(start >= nums.size()){
            return 0;
        }
        int res = max(
                dp(memo, nums, start+2) + nums[start],
                dp(memo, nums, start+1)
                );
        memo[start] = res;
        return res;
    }

    int rob(vector<int>& nums) {
        unordered_map<int, int> memo;
        return dp(memo, nums, 0);
    }
};

int main() {

    vector<int> nums = {1,2,3,1};
    auto solution = Solution();
    auto res = solution.rob(nums);
    cout << res << endl;

    return 0;
}
