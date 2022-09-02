// 322. 零钱兑换
// 动态规划
#include<iostream>
#include<vector>
#include <unordered_map>
#include <climits>
using namespace std;



// // 备忘录自顶向下
// class Solution {
//     unordered_map<int, int> memo;
//
//     int dp(const vector<int>& coins, int amount){
//         if (memo.count(amount)) return memo[amount];
//         if (amount < 0) return -1;
//         if (amount == 0) return 0;
//         int minValue = INT_MAX;
//         for (auto coin : coins){
//             int res = dp(coins, amount-coin);
//             if (res != -1){
//                 minValue = min(minValue, res + 1);
//             }
//         }
//         memo[amount] = minValue != INT_MAX ? minValue : -1;
//         return memo[amount];
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         return dp(coins, amount);
//     }
// };


// 自底向上
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int a = 0; a < amount + 1; ++a) {
            for (const auto &coin: coins) {
                if(a-coin < 0){
                    continue;
                }
                dp[a] = min(dp[a-coin] + 1, dp[a]);
            }
        }
        return dp[amount] == amount+1? -1 : dp[amount];

    }
};



int main(){
    auto s = Solution();
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int n = s.coinChange(coins, amount);
    cout << n << endl;

    return 0;
}