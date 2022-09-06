// 416. 分割等和子集
// 01背包，动态规划


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



// 编号为[0, .. i]的物品，背包容量为j的时候，是否能恰好装满
bool dp(vector<int> &nums, int i, int j, vector<vector<int>> &memo){


    if(i<0 || j <= 0){
        return false;
    }
    if(i==0){
        return (nums[0] == j);
    }

    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }
    // 如果能装得下，装一装试试看
    bool p1 = false;
    if(nums[i] < j){
        p1 = dp(nums, i-1, j-nums[i], memo);
    }
    // 不装试试看
    bool p2 = dp(nums, i-1, j, memo);

    bool res = p1 || p2;
    memo[i][j] = res;
    return res;

}


// 动态规划
// 归约到01背包，有N个物品，每个价值为nums[i]，容量为sum/2的背包能装的最大价值是多少
// 简化一下，N个物品，每个价值为nums[i]，容量为sum/2的背包，是否能恰好装满
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        vector<vector<int>> memo(nums.size(), vector<int>(sum/2 + 1, INT_MIN));
        return dp(nums, nums.size()-1, sum/2, memo);
    }
};


int main() {
    vector<int> nums = {1,5,11,5};
    // vector<int> nums = {1,2,3,5};
    auto solution = Solution();
    auto res = solution.canPartition(nums);
    cout << res << endl;

    return 0;
}
