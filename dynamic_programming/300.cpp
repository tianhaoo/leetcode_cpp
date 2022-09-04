// 300. 最长递增子序列
// 动态规划




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include "../utils.h"

using namespace std;



// debug递归函数
int count_ = 0;
void printIndent(int n) {
    for (int i = 0; i < n; i++) {
        cout << "   ";
    }
}


// // 自顶向下备忘录
// class Solution {
// public:
//     int dp(vector<int>& nums, int i, unordered_map<int, int> &memo){
//         // 以nums[i]结尾的最长递增子序列的长度为l
//         printIndent(count_++);
//         cout
//         << "p1 = " << i << ", "
//         << endl;
//
//         int res;
//         if(memo.count(i)){
//             res =  memo[i];
//         }else if (i==0){
//             res = 1;
//         }else{
//             int m = 1;
//             for(int j=0; j<i; j++){
//                 if(nums[j]<nums[i]){
//                     m = max(m, dp(nums, j, memo)+1);
//                 }
//             }
//             res = m;
//             memo[i] = res;
//         }
//
//         printIndent(--count_);
//         cout
//         << "return " << res
//         << endl;
//         return res;
//     }
//
//     int lengthOfLIS(vector<int>& nums) {
//         unordered_map<int, int> memo;
//         int m = INT_MIN;
//         for (int i = 0; i < nums.size(); ++i) {
//             int length = dp(nums, i, memo);
//             m = max(m, length);
//         }
//         return m;
//
//     }
// };



// 自底向上
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int m = 1;
            for (int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]){
                    m = max(m, dp[j]+1);
                }
            }
            dp[i] = m;
            res = max(res, m);
        }
        return res;
    }
};





int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    auto solution = Solution();
    auto res = solution.lengthOfLIS(nums);
    cout << res << endl;

    return 0;
}
