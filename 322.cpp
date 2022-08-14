// 322. 零钱兑换
// 动态规划
#include<iostream>
#include<vector>
#include <unordered_map>
#include <climits>
using namespace std;




class Solution {
    unordered_map<int, int> memo;

    int dp(const vector<int>& coins, int amount){
        if (memo.count(amount)) return memo[amount];
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        int minValue = INT_MAX;
        for (auto coin : coins){
            int res = dp(coins, amount-coin);
            if (res != -1){
                minValue = min(minValue, res + 1);
            }
        }
        memo[amount] = minValue != INT_MAX ? minValue : -1;
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
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