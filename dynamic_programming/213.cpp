// 213. 打家劫舍 II



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



class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }

        // 抢[0, ...n-2]
        vector<int> memo1(nums.size(), INT_MIN);
        int p1 = dp(nums, nums.size()-2, memo1);
        // 抢[1, ..n-1]
        auto p = nums.begin();
        nums.erase(p);
        vector<int> memo2(nums.size(), INT_MIN);
        int p2 = dp(nums, nums.size()-1, memo2);
        return max(p1, p2);

    }
};


int main() {

    return 0;
}
