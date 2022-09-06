// 518. 零钱兑换 II




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





// [0 ..i]的硬币可选，凑出j元，所有的组合总数
int dp(vector<int> &coins, int i, int j, vector<vector<int>> & memo){

    if(i < 0 || j <= 0){
        int res = 0;
        return res;
    }
    if(i == 0){
        int res=0;
        if(j % coins[i] == 0){
            res = 1;
        }
        return res;
    }
    if(memo[i][j] != INT_MIN){
        return memo[i][j];
    }


    int candidatesNum = j / coins[i] ;  // 最多选这么多个nums[i]
    int res = 0;
    for (int k = 0; k < candidatesNum+1; ++k) {
        int pi;
        if(j-k*coins[i] == 0){
            pi = 1;
        }else{
            pi = dp(coins, i-1, j-k*coins[i], memo);
        }
        res += pi;
    }
    memo[i][j] = res;
    return res;

}



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0){
            return 1;
        }
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, INT_MIN));
        return dp(coins, coins.size()-1, amount, memo);
    }
};


int main() {
    // int amount = 5;
    // vector<int> coins = {1, 2, 5};
    int amount = 1000;
    vector<int> coins = {3,5,7,8,9,10,11};
    auto solution = Solution();
    auto mt = MyTimer();
    auto res = solution.change(amount, coins);
    cout << res << endl;


    return 0;
}
